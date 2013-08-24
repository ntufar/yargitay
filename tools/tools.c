/*
 *  tools/tools.c
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */

/*
 * Yargitay evrak izleme projesi icin yardimci fonksyonlar:
 * refreshtime(); 
 * strip();
 * dress();
 * ntlog();
 * ntlog2();
 * quote();
 * ntchanges();
 * aux();
 */

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <syslog.h>
#include <stdarg.h>
#include <time.h>
#include "tools.h"

extern char tarih[];
extern char yil[];
extern char yyil[];
extern char mydir[];

#define DEGISIKLER "degisikler.sql"
#define HAREKETLER "hareketler.log"




char Curusr[30];	/* Current User */
static char firsttime = 1;

refreshtime()
	/**********************************************************
	 * tarih, yil ve yyl degiskeni su anki tarihiyle dolduruyor
	 * tarih  -- "xx/xx/xxxx"
	 * yil    -- "xx"
	 * yyil   -- 19 yada 20
	 * 2000 sorunu soyle cozulur: eger yil 90'dan buyukse 1990-1999,
	 * 90'dan kucukse  2000 - 2089.  Bu fonksyon 90 sene sonra calismayacak
	 * genelde dosya ve sonuc girme bugunku tarihi hesaplamak icin 
	 * cagiriliyor
	 *********************************************************/
{
	time_t now;
	struct tm *mtm;

        /* Get time */
        now=time(NULL);
        mtm = localtime(&now);
        sprintf(tarih,"%.2d/%.2d/%.2d%.2d",mtm->tm_mday,mtm->tm_mon+1,
			mtm->tm_year<100?19:20,mtm->tm_year>=100?100-mtm->tm_year:mtm->tm_year);
        sprintf(yil,"%.2d",mtm->tm_year>=100?100-mtm->tm_year:mtm->tm_year);
	strcpy(yyil,mtm->tm_year<100?"19":"20");
}


char *strip(str)
	/**********************************************************
	 * str string degiskenin sondaki bosluklari kaldiriyor
	 **********************************************************/
	
	char *str;
{
	register int i;
	for(i=0;str[i]!=0;i++)
		/* bos */;
	for(;i>=0 && (isspace(str[i])||str[i]==0);i--)str[i]=0;
	return str;
}

char *dress(str,len)
	/**********************************************************
	 * str string sonunda len bosluk dolduruyor.
	 * str degiskenin yeterince buyuk oldugunu kontrol edin
	 **********************************************************/

	char *str;
	int len;
{
	register int i;
	for(i=0;str[i] ;i++);
	for(;i<len;i++){
		str[i]=' ';
	}
	str[i]=0;
	return str;
}
/*--------------------------------*/
int
ntlog(int fac, char *msg)
	/**********************************************************
	 * fac - log olacak facility (LOG_HUKUK, LOG_CEZA, LOG_EMSAL, LOG_SORGU)
	 * bunlar hangi lig facility'ye ait oldugunu tools.h dosyasinda 
	 * ogrenebilirsiniz
	 * hangi dosyalara log edilir /etc/syslog.conf'ten ogrenebilirsiniz
	 * msg degiskeni -- yazilacak mesaj
	 **********************************************************/
{
	if(firsttime)inittools();
        openlog(Curusr, 0|LOG_PID, fac | LOG_INFO);
	syslog(fac | LOG_INFO, msg);
	closelog();
	nthareket(msg);
}
/*--------------------------------*/
/*
 * iki parametreli log yazmak icin. 2 parametreden 1 satir yapip
 * ntlog() cagiriyor
 */
int
ntlog2(int fac, char *function, char *msg)
{
	char buf[1024];
	
	sprintf(buf,"(%s):%s", function, msg);
	ntlog(fac,buf);
}
/*--------------------------------*/
/*
 * SQL standartina gor tirnak (') icinde olan bir satir icinde
 * tirnak isareti koymak gerekiyorsa onun yerine cift tirnak konulur.
 * Ornegin: 'Ankara'da' >>> 'Ankara''da'.  Bu fonksyon bu islemi yapar.
 * getiren satiri static char buf'ta saklar, o yuzden her sonraki 
 * cagirildiginda silinir.
 */
char *quote(char *str)
{
	static char buf[1024];
	int a,b;
	for(a = 0, b = 0; str[b];a++,b++){
		if(str[b]=='\''){
			buf[a]='\'';
			buf[++a]='\'';
			continue;
		}
		buf[a]=str[b];
	}
	buf[a]=0;
	return buf;
}
/*--------------------------------*/
/* 
 * Yapilan degisiklikleri bir dosyadaya yazmak icin kullanilir.
 * degisiklikler normal bir SQL komutu olarak kaydedilir, onu
 * sonra gidip baska bir SQL database'de calisitirabilirsiniz
 */
int
ntchanges(char *fmt, ... )
{
	va_list ap;
	char buf[100];
	FILE *of;
	time_t simdi;

	if(firsttime)inittools();

	va_start(ap,fmt);
        strcpy(buf,mydir);
        strcat(buf,DEGISIKLER);
	if((of = fopen(buf,"a"))==NULL)return 0;
	fprintf(of,"------------------------------------------\n");
	fprintf(of,"--- Kullanici: %s\n", Curusr);
	time(&simdi);
	fprintf(of,"--- Saat: %s",ctime(&simdi));
	vfprintf(of,fmt,ap);
	fclose(of);
	va_end(ap);
}
/*--------------------------------*/
/*
 * bu dosyadaki fonksyonlari kullanmadan once bunu cagiracaksiniz.
 * su an bu fonksyon log ver kareketler icin kullanici adi
 * kaydediyor.  Herhangi bir initialization da konulabilir
 */
int
inittools()
{
	strcpy(Curusr,getlogin());
	firsttime = 0;
}
/*--------------------------------*/
/*
 * hareketleri kayit etmek icin. mydir degiskende belirtilen dizinde,
 * HAREKETLER degiskeninde belirtilen dosyada kaydedilir, sonunda
 * da tarih, saat yazilir. Hareketleri variable peremeter olarak
 * gonderildigi icin printf()'deki gibi degisen degisken sayisi
 * kullanabilirsiniz, format-sring da kullanabilirsiniz
 */
int
nthareket(char *fmt, ... )
{
	va_list ap;
	char buf[100];
	FILE *of;
	time_t simdi;

	if(firsttime)inittools();

	va_start(ap,fmt);
        strcpy(buf,mydir);
        strcat(buf,HAREKETLER);
	if((of = fopen(buf,"a"))==NULL)return 0;
	vfprintf(of,fmt,ap);
	time(&simdi);
	fprintf(of,", %s, %s", Curusr, ctime(&simdi));
	fclose(of);
	va_end(ap);
}
/*--------------------------------*/

#define HEADER  	"\x1b\x5b\x35\x69"
#define TERMINATOR  	"\x1b\x5b\x34\x69"

/*
 * message degiskende bir metin alip once ekrana HEADER - karakterleri 
 * terminal'e bagli olan yaziciya gonder, sonra metinin kendisini,
 * rastlanan Turkce kararkterleri iso2dos() ile DOS kodlamaya cevirip
 * gonderiyor, sonunda da TERMINATOR - karakterleri yaziciya gondermeyi
 * durdur donderiyor.
 *
 * HEADER ve TERMINATOR - ANSI kontrol kodlaridir. ANSI desteklemeyen
 * terminallerde calismaz.  Metin oldugu gibi ekrana dokulur.
 */
aux(message)
char *message;
{
	int c;
	unsigned char x;
	int i;

	puts(HEADER);
	for(i=0; message[i]; i++){
		c = message[i];
		x = (unsigned char)c;

		x = iso2dos(c);

		if (c==EOF)break;
		putchar(x);
	}
	puts(TERMINATOR);
	return 1;
}
/*--------------------------------*/
/*
 * UNIX'te ve Windows'ta kullanilan Turkce karakterleri
 * DOS'taki turkce karakterlere ceviriyor. Niye? Bazi matrix
 * yazicilar bu kodlamayi kullaniyorlar. aux() tarafindan
 * cagiriliyor
 */
int
iso2dos(int c)
{
		unsigned char x;

		x = (unsigned char)c;

		if(x == (unsigned char)'İ') x = '˜';
		else if(x == (unsigned char)'Ğ') x = '¦';
		else if(x == (unsigned char)'Ş') x = '';
		else if(x == (unsigned char)'Ö') x = '™';
		else if(x == (unsigned char)'Ç') x = '€';
		else if(x == (unsigned char)'Ü') x = 'š';
		else if(x == (unsigned char)'ö') x = '”';
		else if(x == (unsigned char)'ü') x = '';
		else if(x == (unsigned char)'ç') x = '‡';
		else if(x == (unsigned char)'ğ') x = '§';
		else if(x == (unsigned char)'ı') x = '';
		else if(x == (unsigned char)'ş') x = 'Ÿ';
		return x;
}
/*--------------------------------*/
/*
 * bir satiri alip dos2iso() fonksyonu kullanarak dos'tan ISO-9
 * Turkce karakterleri ceviriyor
 */
char *
striso2dos(char *str)
{
	int i;
	for(i=0; str[i]; i++)
		str[i]=iso2dos(str[i]);
	return str;
}
/*------------------------------------*/
/*
 * PClerde kullanilan Turkce karakterleri normal ISOxxxx-9 ceviriyor.
 * Not: Turkce karakterler >128den oldugu icin unsigned 
 * kullaniyorum
 */
int dos2iso(c)
	int c;
{
	unsigned char x;

	x = (unsigned char)c;
	if(x == (unsigned char)'˜') x = 'İ';
	else if(x == (unsigned char)'¦') x = 'Ğ';
	else if(x == (unsigned char)'') x = 'Ş';
	else if(x == (unsigned char)'™') x = 'Ö';
	else if(x == (unsigned char)'€') x = 'Ç';
	else if(x == (unsigned char)'š') x = 'Ü';
	else if(x == (unsigned char)'”') x = 'ö';
	else if(x == (unsigned char)'') x = 'ü';
	else if(x == (unsigned char)'‡') x = 'ç';
	else if(x == (unsigned char)'§') x = 'ğ';
	else if(x == (unsigned char)'') x = 'ı';
	else if(x == (unsigned char)'Ÿ') x = 'ş';
	
	return (int)x;
}
/*------------------------------------*/
/*--------------------------------*/
/*
 * bir satiri alip dos2iso() fonksyonu kullanarak dos'tan ISO-9
 * Turkce karakterleri ceviriyor
 */
char *
strdos2iso(char *str)
{
	int i;
	for(i=0; str[i]; i++)
		str[i]=dos2iso(str[i]);
	return str;
}
