/*
 *  tools/yf.c
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */

/* Yargitay Forms Library yf.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "yf.h"

extern char mydir[];
extern char yyil[];

int inityf();
int shutyf();
yf *initform(char *filename);
int closeform(yf *form);
int showform(yf *form);
int clearform(yf *form);
int superinputform(yf *form,int start);
int inputform(yf *form);
int outputform(yf *form);
int updateform(yf *form);
int yfmessage(char *message);
int yfquestion(char *message);
ym *initmenu(char *filename);
int yfmenu(ym *menu);
int yffmore(char *filename, char *message);
int yfmore(char *message, char *prompt);
int supermenu(yf *form, int cifs);

int messageline=22;

/*-----------------------------------------------*/
#define ESCDELAY 300000L   /* 0.5 saniye */
/*
 * benim yazdigim getchar() gibi bir fonksyon. ESC tusu basilmissa
 * ESCDELAY kadar milisanye bekliyor, bu arada tus basilmamissa sade
 * ESC donduruyor, basilmissa yorumlyor
 */
int ntgetch()
{
	int c;
	int sawesc = 0;
        fd_set rfds;
        struct timeval tv;
        int retval;


        c = getch();
	/*if ( c == EOF ){
		exit(0);
	}
	if ( c == 255 ){
		exit(0);
	}
	if ( c == 0){
		exit(0);
	}*/
        if(c == 0x1b ){
        	sawesc = 1;
                nodelay(stdscr,1);
                /* Watch stdin (fd 0) to see when it has input. */
                FD_ZERO(&rfds);
                FD_SET(0, &rfds);
                /* Wait up to five seconds. */
                tv.tv_sec = 0;
                tv.tv_usec = ESCDELAY;  
                retval = select(1, &rfds, NULL, NULL, &tv);
                nodelay(stdscr,0);
                if (retval==0)return 0x1b;   /* there is input in stdin */
		c = getch();
        }
	if( c == 0x5b || c == 0x4f){
		c = getch();
		switch(c){
		case 0x41:return KEY_UP;
		case 0x42:return KEY_DOWN;
		case 0x43:return KEY_RIGHT;
		case 0x44:return KEY_LEFT;
		}
	}
	return c;

}
/*-----------------------------------------------*/
/* 
 * signal handler. Oldurucu bir signal aldigimizda bu fonksyon
 * calistiriyoruz, curses kutuphaneyi kapatmaya calisiyoruz
 */
int diewell()
{
	shutyf();
	exit(0);
}
/*-----------------------------------------------*/
/*
 * Yargitay Forms kutuphanesi kuruluyor, curses ilgili
 * parametreler belirtiliyor, signal handler'ler 
 * tutuluyor.
 */
int inityf()
{
        initscr();
        crmode();
        nl();
        noecho();
	/*nocbreak();*/
	/*nodelay(stdscr,1);*/
	/*keypad(stdscr,1);*/
        scrollok(stdscr,1);
	attrset(A_NORMAL);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGINT,SIG_IGN);
	signal(SIGABRT,SIG_IGN);
	signal(SIGHUP,SIG_DFL);
}
/*-----------------------------------------------*/
/*
 * Yargitay Forms kutuphanesi kapatiliyor...  Yapacagimiz tek sey -
 * curses'i kapatmak.
 */
int shutyf()
{
        endwin();
}
/*-----------------------------------------------*/
/*
 * yeni bir formu initilyze ediyor. Parametre - dosya adi,
 * form'a pointer donduruyor.  Form icin butun gereken memory
 * ayarlaniyor.
 *
 * Formu yok etmek icin closeform();
 */
yf *initform(filename)
	char *filename;
{
	FILE *inf;
	yf *newform;
	long filelen;
	char *text;
	char *b,*b1,*b2;
	int i,k,p;
	char buf[150];

	strcpy(buf,mydir);
	strcat(buf,filename);
	if((inf=fopen(buf,"r"))==NULL)return NULL;
	if(fseek(inf, 0L, SEEK_END)==-1)return NULL;
	if((filelen = ftell(inf))==-1)return NULL;
	if(fseek(inf, 0L, SEEK_SET)==-1)return NULL;
	if((newform = (yf*)malloc(sizeof(yf)))==NULL)return NULL;
	if((text = (char*)malloc(filelen+10))==NULL){
		free(newform);
		return NULL;
	}
	bzero(text,filelen+9);
	bzero(newform,sizeof(yf));
	fread(text, filelen, 1, inf);
	fclose(inf);

	/* Fill Lines */
	b=text;
	b1=newform->lines[0];
	for(i=0;i<25;i++){
		for(k=0;k<80;k++,b++){
			if(*b == 0){k=85;continue;}
			if(*b=='\n' || *b=='\r'){
				newform->lines[i][k]=0;
				k=85;continue;
			}
			newform->lines[i][k]=*b;
		}
		if(*b==0)break;
	}
	newform->lines[i][k]=0;
	newform->lines[i+1][0]='~'; /* ~ - end-of-text isareti */
	
	/* Figure out Input Fileds */
	/* Input fieldler, form dosyasindaki `[' ve `]' isaretlere
	 * gore ayarlanir. Fielddeki ilk karakter:
	 * t - text (dafault)
	 * d - date, field soyle cizilir: [  /  /19  ] yada [  /  /20  ]
	 *     yyil degiskenine gore.  Veri girerken sadece rakamlar kabul 
	 *     edilir.
	 * n - number, veri girerken sadece rakamlar kabul edilir.
	 * y - yil, [19  ] yada [20  ] olarak gosterilir. Sadece rakamlar kabul
	 *     edilir.
	 */

	p = 0;
	for(i=0;i<25;i++){
		for(k=0;k<80;k++){
			if(newform->lines[i][k]=='['){
				newform->ifs[p].by=i;
				newform->ifs[p].bx=++k;
				newform->ifs[p].type=IF_TEXT; /* default */
				if(newform->lines[i][k]=='t')
					newform->ifs[p].type=IF_TEXT;
				if(newform->lines[i][k]=='d')
					newform->ifs[p].type=IF_DATE;
				if(newform->lines[i][k]=='n')
                                        newform->ifs[p].type=IF_NUMBER;
				if(newform->lines[i][k]=='y')
                                        newform->ifs[p].type=IF_YEAR;

				for(;k<80 && newform->lines[i][k]!=']';k++){
					newform->lines[i][k]=' ';
				}
				newform->ifs[p].ey = i;
				newform->ifs[p].ex = k-1;
				newform->ifs[p].edit=1;
				newform->ifs[p].show=1;
				newform->ifs[p].y2k=1;
				p++;
			}
		}
	}
	newform->ifs[p].by = 0xffff;
	free(text);
	return newform;
}
/*-----------------------------------------------*/	
/*
 * fromu yok ediyor
 */

int closeform(form)
	yf *form;
{
	free(form);
}
/*-----------------------------------------------*/	
/*
 * Formu ekranda gosteriyor, alanlardaki bilileri gosteriyor
 */
int showform(form)
	yf *form;
{
	int i;
	int curifs;


        clear();
	/* Once formun kendisi oldugu gibi ciziyor... */
	for(i=0;i<25 && form->lines[i][0]!='~';i++){
		printw("%s\n",form->lines[i]);
	}
	/* ...sonra alanlardaki bilgiler gosteriyor. */
	for(curifs=0;form->ifs[curifs].by!=0xffff;curifs++){
		if(form->ifs[curifs].type == IF_DATE){
			move(form->ifs[curifs].by, form->ifs[curifs].bx+2);
			printw("/");
			move(form->ifs[curifs].by, form->ifs[curifs].bx+5);
			printw("/");
			printw(yyil);
		}
		if(form->ifs[curifs].type == IF_YEAR){
			move(form->ifs[curifs].by, form->ifs[curifs].bx);
			printw(yyil);
		}
	}
	refresh();
}	
/*-----------------------------------------------*/	
/*
 * Eski, bunun yerine superinputform() kullanin,
 */
int 
inputform(form)
	yf *form;
{
	return superinputform(form,0);		/* start from 0st field */
}

/* superinputform()'un kullandigi makrolar: */

#define ISNOEDIT form->ifs[curifs].edit == 0
#define ISNOSHOW form->ifs[curifs].show == 0

#define GO_NEXT if(form->ifs[++curifs].by==0xffff)goto done_edit;\
		wmove(stdscr,form->ifs[curifs].by, \
			form->ifs[curifs].bx);\
			didnotedit = 1;\
		if(form->ifs[curifs].type==IF_YEAR)\
			wmove(stdscr,form->ifs[curifs].by, \
				form->ifs[curifs].bx+2);

#define GO_PREV if(curifs!=0){--curifs;\
		wmove(stdscr,form->ifs[curifs].by, \
			form->ifs[curifs].bx);}\
		didnotedit = 1;\
		if(form->ifs[curifs].type==IF_YEAR)\
			wmove(stdscr,form->ifs[curifs].by, \
				form->ifs[curifs].bx+2);


#define GO_LEFT didnotedit = 0;\
		getyx(stdscr,y,x);if(x>form->ifs[curifs].bx){\
			if(form->ifs[curifs].type==IF_DATE &&(\
				x == form->ifs[curifs].bx+3))\
				move(y,x-2);\
			else \
			if(form->ifs[curifs].type==IF_DATE &&(\
				x == form->ifs[curifs].bx+8))\
				move(y,x-4);\
			else \
			if(form->ifs[curifs].type==IF_YEAR &&\
				x == form->ifs[curifs].bx+2)\
				move(y,x);\
			else move(y,x-1);}\

#define GO_RIGHT didnotedit = 0;\
		 getyx(stdscr,y,x);if(x<form->ifs[curifs].ex){\
                        if(form->ifs[curifs].type==IF_DATE &&(\
                                x == form->ifs[curifs].bx+1))\
                                move(y,x+2);\
			else \
                        if(form->ifs[curifs].type==IF_DATE &&(\
                                x == form->ifs[curifs].bx+4))\
                                move(y,x+4);\
			else \
                        if(form->ifs[curifs].type==IF_YEAR &&(\
                                x <= form->ifs[curifs].bx+1))\
                                move(y,x+1);\
                 	else move(y,x+1);}

/*
 * superinputform(), Yargitay Forms kutuphanenin en onemli fonksyonlerdan
 * biri. Parametreler: form ve start - baslayacak alan. Formu aktif hale
 * getiriyor, kullanicidan giris bekiyor ve sonuc statusu donduruyor.
 * Sonuc:
 *      1 - Kullanici bilgi girdi ve ESC C-k yada son alanda Enter'e
 *          basarak girisi kabul etti.
 *      0 - Kullanici girisi iptal etti
 */  
int 
superinputform(form, start)
	yf *form;
	int start;
{
	int c;
	int y,x;
	int sawesc=0;
	int saw5b=0;
	int curifs = start;
	int i,k;
        fd_set rfds;
        struct timeval tv;
        int retval;
	int didnotedit = 1;


	wmove(stdscr,form->ifs[0].by, form->ifs[0].bx);
	while(ISNOEDIT)GO_NEXT;
	while(1){
		refresh();
		c = ntgetch();
		if (c == KEY_CHANGESENTURY){
			if(form->ifs[curifs].type == IF_DATE){
				getyx(stdscr,y,x);
				move(form->ifs[curifs].by, form->ifs[curifs].bx+5);
				printw("/");
				if(form->ifs[curifs].y2k == 0){
					printw(yyil);
					form->ifs[curifs].y2k = 1;
				}else{
					printw(strncmp(yyil,"20",2)==0?"19":"20");
					form->ifs[curifs].y2k = 0;
				}
				move(y,x);
				continue;
			}
			if(form->ifs[curifs].type == IF_YEAR){
				getyx(stdscr,y,x);
				move(form->ifs[curifs].by, form->ifs[curifs].bx);
				if(form->ifs[curifs].y2k == 0){
					printw(yyil);
					form->ifs[curifs].y2k = 1;
				}else{
					printw(strncmp(yyil,"20",2)==0?"19":"20");
					form->ifs[curifs].y2k = 0;
				}
				move(y,x);
				continue;
			}
		}
		if(c == 0x1b ){
			goto done_edit;   /* no input: just ESC pressed */
		}
		if( c == 0xa){		/* Enter */
			GO_NEXT;
			while(ISNOEDIT)GO_NEXT;
			continue;
		}
                if( c == 0x7f || c == 0x8 || c == 0x107){	/* Backspace */
			GO_LEFT;
			addch(' ');
			GO_LEFT;
                        continue;
                }
		if( c == 0x9){		/* Tab */
			GO_NEXT;
			while(ISNOEDIT)GO_NEXT;
			continue;
		}
                if( c == 0x1b){		/* Esc */
                        sawesc = 1;
                        continue;
                }
		if( c == 'k'-'a'+1){		/* Control - k */
			goto done_edit;
		}
		if( c == 'x'-'a'+1){		/* Control - x */
			return 0;
		}
		if( c == 't'-'a'+1){		/* Control - t */
			getyx(stdscr,y,x);
			clearform(form);
			showform(form);
			outputform(form);
			move(y,x);
		}
		if ( c == KEY_UP ){
			GO_PREV;
                        while(ISNOEDIT && curifs != 0)GO_PREV;
			while(ISNOEDIT)GO_NEXT;
                        continue;
		}
		if ( c == KEY_DOWN ){
                        GO_NEXT;
			while(ISNOEDIT)GO_NEXT;
			continue;
		}
		if ( c == KEY_LEFT ){
                        GO_LEFT;
			continue;
		}
		if ( c == KEY_RIGHT ){
                        GO_RIGHT;
			continue;
		}


		getyx(stdscr,y,x);
		if( x <= form->ifs[curifs].ex && form->ifs[curifs].edit){
			if(didnotedit){
				getyx(stdscr,y,x);
				move(form->ifs[curifs].by,form->ifs[curifs].bx);
				for(i=form->ifs[curifs].bx;
					i<=form->ifs[curifs].ex;i++)
						addch(' ');
				move(y,x);
				if(form->ifs[curifs].type == IF_DATE){
					move(form->ifs[curifs].by, form->ifs[curifs].bx+2);
					printw("/");
					move(form->ifs[curifs].by, form->ifs[curifs].bx+5);
					printw("/");
					if(form->ifs[curifs].y2k == 1){
						printw(yyil);
					}else{
						printw(strncmp(yyil,"20",2)==0?"19":"20");
					}
					/*printw(strncmp(yyil,"20",2)==0?"19":"20");
					printw(yyil);*/
				}
				if(form->ifs[curifs].type == IF_YEAR){
					move(form->ifs[curifs].by, form->ifs[curifs].bx);
					if(form->ifs[curifs].y2k == 1){
						printw(yyil);
					}else{
						printw(strncmp(yyil,"20",2)==0?"19":"20");
					}
					/*printw(yyil);*/
				}
				move(y,x);
				didnotedit = 0;
			}
			if(form->ifs[curifs].type == IF_NUMBER ||
			   form->ifs[curifs].type == IF_YEAR){
				if(isdigit(c)||c==' ')printw("%c",c);
			}else
                        if(form->ifs[curifs].type == IF_DATE){
                                if(isdigit(c)|c==' ')printw("%c",c);
				getyx(stdscr,y,x);
				if(x==form->ifs[curifs].bx+2)
					move(y,x+1);
				if(x==form->ifs[curifs].bx+5)
					move(y,x+3);
                        }else
			if( c >=32 ) printw("%c",c);
		}
	}
done_edit:

	/* Fill input fields with results */
	for(curifs=0;form->ifs[curifs].by!=0xffff;curifs++){
		for(i=form->ifs[curifs].bx,k=0;i<=form->ifs[curifs].ex;
				i++,k++){
			form->ifs[curifs].text[k]=mvinch(
				form->ifs[curifs].by,i);
		}
		form->ifs[curifs].text[k+1]=0;
		for(k++;k>=0;k--){
			if(form->ifs[curifs].text[k]==' '||
			   form->ifs[curifs].text[k]==0)
				form->ifs[curifs].text[k]=0;
			else break;
		}
		if(form->ifs[curifs].type == IF_DATE)
			if(strncmp(form->ifs[curifs].text,"  /  /",6)==0)
				form->ifs[curifs].text[0]=0;

	}
	return 1;
}
/*-----------------------------------------------*/	
/*
 * Formun kendini _cizmeden_ dagece ekrandaki formun alanlari
 * dolduruyor. Formun cizmemenin sebebi - form yeniden cizerken
 * mesaj satirindaki "Lutfen bekleyiniz.." gibi mesajlar siliniyor.
 * Formu yeniden cizmen istiyorsaniz, showform(); outputform();
 * cagirin
 */
int outputform(form)
	yf *form;
{
	int curifs, i, k, p;
/*	showform(form);*/
	for(curifs=0;form->ifs[curifs].by!=0xffff;curifs++){
		if(form->ifs[curifs].show==0)continue;
		move(form->ifs[curifs].by, form->ifs[curifs].bx);
		if(strlen(form->ifs[curifs].text) >= 
			form->ifs[curifs].ex -form->ifs[curifs].bx){
				form->ifs[curifs].text[form->ifs[curifs].ex -
				form->ifs[curifs].bx+1]=0;
		}
		if(form->ifs[curifs].edit==0)attrset(A_REVERSE);
		if(form->ifs[curifs].type==IF_DATE){
			printw("  /  /");
			if(form->ifs[curifs].y2k == 1){
				printw(yyil);
			}else{
				printw(strncmp(yyil,"20",2)==0?"19":"20");
			}
			/*printw(yyil);*/
			printw("  ");
		}else if(form->ifs[curifs].type==IF_YEAR){
				move(form->ifs[curifs].by, form->ifs[curifs].bx);
				if(form->ifs[curifs].y2k == 1){
					printw(yyil);
				}else{
					printw(strncmp(yyil,"20",2)==0?"19":"20");
				}
		}else{
                	for(p = form->ifs[curifs].ex-form->ifs[curifs].bx 
                       	 ;p >= 0;p--)
                              addch(' ');
		}
			/*printw(yyil);*/
		move(form->ifs[curifs].by, form->ifs[curifs].bx);

		printw(form->ifs[curifs].text);
		/*for(i=0;form->ifs[curifs].text[i];i++){
			addch(form->ifs[curifs].text[i]);
		}*/

		if(form->ifs[curifs].type!=IF_DATE && form->ifs[curifs].type!=IF_YEAR){
			form->ifs[curifs].text[form->ifs[curifs].ex -
				form->ifs[curifs].bx]=0;
			for(p = form->ifs[curifs].ex-1 -form->ifs[curifs].bx - 
				strlen(form->ifs[curifs].text)+1;p > 0;p--)
				/*printw(" ");*/
				addch(' ');
		}
		attrset(A_NORMAL);
	}
	refresh();
		
}
/*-----------------------------------------------*/	
/*
 * Formdaki butun alanlari siliyor.
 * Bu fonksyon sadece bellekteki formdaki alanlari siliyor,
 * onlari ekrandakilerle sinkronize etmek icin showform()
 * cagirin
 */
int clearform(form)
        yf *form;
{
        int curifs;
        for(curifs=0;form->ifs[curifs].by!=0xffff;curifs++){
		if(form->ifs[curifs].edit == 0)continue;
                form->ifs[curifs].text[0]=0;
                form->ifs[curifs].len = 0;
                form->ifs[curifs].ws = 0;
        }
        return 1;
}
/*-----------------------------------------------*/
/*
 * Ekraninin messageline'de belirtilmis satirda message mesaji
 * yaziliyor
 */
int yfmessage(message)
	char *message;
{
	char buf[80];
	int i,k;
	int y,x;
	move(messageline,0);
	for(i=0;i<79;i++)addch(' ');
	move(messageline,0);
	if(strlen(message)>79)message[79]=0;
	printw(message);
	/*getyx(stdscr,y,x);
	for(i=strlen(message),k=0;i<80;i++,k++)
		buf[k]=' ';
	buf[k]=0;
	printw(buf);
	move(y,x);*/
	refresh();
	return 1;
}
/*-----------------------------------------------*/	
/*
 * 'message' degiskendeki mesaji gosterip, kullanicinin
 * bir tusa basmasini bekliyor, bastigi tusu doinduruyor
 */
int yfquestion(message)
	char *message;
{
	int c;
	yfmessage(message);
	c = ntgetch();
	return c;
}
/*-----------------------------------------------*/	
/*
 * Dosya adi aliyor, structure ym olusturuyor.
 */
ym *initmenu(filename)
	char *filename;
{
	FILE *inf;
        ym *newmenu;
	char buf[100];
	int i;

	if((newmenu = (ym*)malloc(sizeof(ym)))==NULL)return NULL;

	strcpy(buf,mydir);
	strcat(buf,filename);
	if((inf=fopen(buf,"r"))==NULL)return NULL;
	for(i = 0; i < 29; i++){
		if(fgets(newmenu->lines[i],80,inf)==NULL)break;
	}
	newmenu->lines[i+1][0]='~';
	return newmenu;
}
/*-----------------------------------------------*/	
/* `menu'deki menu ekrana gosteriyor, bir tusun 
 * basamasi bekliyor, basilmis tusu donduruyor
 */
int yfmenu(menu)
	ym *menu;
{
	int i, k;
	int c;
	char bf[2];

	clear();
	for(i=0;i<29;i++){
		for(k=0;k<79;k++){
			c = menu->lines[i][k];
			if(c == 0)break;
			if(c == '~')goto superbreak;
			bf[0]=c;
			bf[1]=0;
			printw(bf);
		}
	}
superbreak:
	refresh();
	c = ntgetch();
	return c;
}

/*-----------------------------------------------*/	
/* bir dosya okuyup yfmore()'ye gonderiyor
 */
int yffmore(filename, message)
	char *filename;
	char *message;
{
	FILE *inf;
	char *xbuf;
	long filelen;

	if((inf=fopen(filename,"r"))==NULL)return 0;
	if(fseek(inf, 0L, SEEK_END)==-1)return 0;
	if((filelen = ftell(inf))==-1)return 0;
	if(fseek(inf, 0L, SEEK_SET)==-1)return 0;
	if((xbuf = (char*)malloc(filelen+10))==NULL)return 0;
	fread(xbuf, filelen, 1, inf);
	fclose(inf);
	yfmore(xbuf, message);
	free(xbuf);
	return 1;
}

/*-----------------------------------------------*/
/*
 * message'i, `ends'teki satir sonu bilgilere gore
 * terminal'e bagli olan ANSI yaziciyda bastiriyor.
 * `ends' array'i yfmore()'de olusturuluyor
 */
int toprint(message, ends)
	char *message;
	int *ends;
{
	int i;
	int k;
	char *buf;
	char b1[100];
	int bp;
	int lineno = 1;
	int pageno = 1;
	if((buf = (char*)malloc(strlen(message) * sizeof(char)*2))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	bzero(buf,strlen(message)*sizeof(char)*2);

	bp=0;
	buf[bp++]='\t';
	for(i = 0; ends[i] != -1; i++){
		for(k = i==0?0:ends[i-1]+1 ; k <= ends[i] && message[k]; k++){
				if(message[k]!='\r' &&
				   message[k]!='\n'){
				   buf[bp++]=message[k];
				}
		}
		buf[bp++]='\n';
		buf[bp++]='\t';
		lineno++;
		if (lineno >= 62){
			sprintf(b1,"\n\t\t\t\t\t- %d -\f\t",pageno++);
			strncat(&buf[bp-1],b1, strlen(b1));
			bp+=strlen(b1);
			lineno = 1;
		}
	}
	buf[bp]=0;
	aux(buf);
	aux("\f");
	/*ax = fopen("eraseme","w");
	fprintf(ax,buf);
	fclose(ax);*/
	free(buf);
}
/*-----------------------------------------------*/	
/*
 * toprint() gibi ama yazici yerine, e-mail adresi soran
 * bir pencere cikiyor, kullanici e-mail giriyor,
 * o e-mail'e gonderilir
 */
int
tomail(message,ends)
	char *message;
	int *ends;
{
	FILE *ppe;
	yf *aa;
	int stat = 0;
	char cmd[200];
        int i;
        int k;
        char *buf;
        int bp;



        if((buf = (char*)malloc(strlen(message) * sizeof(char)*2))==NULL){
                yfquestion("Bellek yetersiz");
                return 0;
        }
        bzero(buf,strlen(message)*sizeof(char)*2);

        bp=0;
        for(i = 0; ends[i] != -1; i++){
                for(k = i==0?0:ends[i-1]+1 ; k <= ends[i] && message[k]; k++){
                                if(message[k]!='\r' &&
                                   message[k]!='\n'){
                                   buf[bp++]=message[k];
                                }
                }
                        buf[bp++]='\n';
        }

	aa = initform("mail.frm");
	if(aa == NULL){
		yfquestion("Hmmm..");
		return 0;
	}
	showform(aa);
	stat = inputform(aa);
	if (stat == 0) return 0;
	sprintf(cmd,"/bin/mail -s \"Emsal Karari\" %s ",aa->ifs[0].text);
	ppe = popen(cmd,"w");


	fprintf(ppe,buf);
	pclose(ppe);
	closeform(aa);
	free(buf);
	return 1;
}
/*-----------------------------------------------*/	
/* 
 * `message'yi ekrana more komutu gibi gosteriyor.
 * Metin butukse satirlara bolunuyor.
 */
int yfmore(message, prompt)
	char *message;
	char *prompt;
{
	int i, k;
	int thisline = 0;
	int line = 0;
	int tabs = 0;
	char bf[3];		/* for turkish chars, booo */
	int c;
	int quit = 0;
	int *ends;
	FILE *aa;
	int xlp = 0;


	/*aa = fopen("eraseme","w");
	fprintf(aa,message);
	fclose(aa);*/
	if((ends = (int *)malloc(strlen(message) * sizeof(int)))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	memset(ends, -1, strlen(message) * sizeof(int));
	xlp = 0;
	for(i = 0; message[i]; i++){
		if(message[i]=='\n' || message[i]=='\r'){
			ends[xlp] = i;
			thisline = 0;
			tabs=0;
			xlp++;
			while (message[i]=='\n' || message[i]=='\r')i++;
			i--;
			continue;
		}
		if(message[i]=='\t')tabs++;
		else thisline++;
		if(thisline >= (71 - tabs*8)){
			for(k = i; k > i - (71 - tabs*8); k--){
				if(message[k] == ' '){
					for(; k > i - (71 - tabs*8); k--){
						if(message[k] != ' ')break;
					}
					break;
				}
			}
			if( k != i - 71) i = k;
			ends[xlp] = i;
			thisline = 0;
			tabs = 0;
			xlp++;
			continue;
		}
		
	}
	ends[xlp++]=i;
	ends[xlp]=-1;
	line = 0;
	do{
		clear();
		for(i = line; i < line + 24 && ends[i] != -1; i++){
			for(k = i==0?0:ends[i-1]+1 ; k <= ends[i] && message[k]; k++){
				if(message[k]!='\r' &&
				   message[k]!='\n'){
					bf[0]=message[k];
					bf[1]=0;
					printw(bf);
				}
			}
			addch('\n');
		}
		attrset(A_REVERSE);
		move(24,0);
		/*printw(prompt);*/
		/*printw("%d,%d",i,line);*/
		printw("Sonraki, önceki s. sað ve sol, yazdýr y,"
			" çýkýþ x tuþlarý");
		attrset(A_NORMAL);
		refresh();
		c = ntgetch();
		switch(c){
		case 'x': quit = 1; break;
		case 'o':
		case KEY_UP:
			if(line)line--;
			break;
		case 's':
		case KEY_DOWN:
			if(ends[line+1]!=-1 && ends[line+23]!=-1)line++;
			break;
		case KEY_PPAGE:
		case KEY_LEFT:
			line = line < 24?0: line - 24;
			break;
		case KEY_NPAGE:
		case KEY_RIGHT:
		case ' ':
		case KEY_ENTER:
			if(ends[line+2]!=-1 && ends[line+26]!=-1)line += 24;
			break;
		case 'y':
		case 'p':
			toprint(message,ends);
			break;
		case 'm':
			tomail(message, ends);
			break;
		}
	}while(!quit);
	free(ends);
	return 0;

		
		
}
/*-----------------------------------------------*/	
/* supermenu icin gereken makrolar */
#define HL wmove(stdscr,form->ifs[curifs].by, form->ifs[curifs].bx);\
  attrset(A_REVERSE);printw(form->ifs[curifs].text);\
  for(p = form->ifs[curifs].ex -form->ifs[curifs].bx - \
       strlen(form->ifs[curifs].text);p >= 0;p--)\
				printw(" ");\
			attrset(A_NORMAL);

#define UHL wmove(stdscr,form->ifs[curifs].by, form->ifs[curifs].bx);\
  attrset(A_NORMAL);printw(form->ifs[curifs].text);\
  for(p = form->ifs[curifs].ex -form->ifs[curifs].bx - \
       strlen(form->ifs[curifs].text);p >= 0;p--)\
				printw(" ");\
			attrset(A_NORMAL);

#define SF_GO_NEXT if(form->ifs[++curifs].by==0xffff||\
		form->ifs[curifs].show==0){curifs=0xffff;goto done_edit;}\
		wmove(stdscr,form->ifs[curifs].by, \
			form->ifs[curifs].bx);

#define SF_GO_PREV if(curifs!=0){--curifs;\
		wmove(stdscr,form->ifs[curifs].by, \
			form->ifs[curifs].bx);}\
		else{curifs=0xfffd;goto done_edit;}

int
supermenu(form, cifs)
yf *form;
int cifs;
{
	int c;
	int y,x;
	int sawesc=0;
	int saw5b=0;
	int curifs = 0;
	int i,k,p;
        fd_set rfds;
        struct timeval tv;
        int retval;
	int didnotedit = 1;

	curifs = cifs;
	wmove(stdscr,form->ifs[curifs].by, form->ifs[0].bx);
	HL;
	while(ISNOEDIT)SF_GO_NEXT;
	while(1){
		refresh();
		c = ntgetch();
		if(c == 0x1b ){
			goto done_edit;   /* no imput: just ESC pressed */
		}
		if( c == 0xa){		/* Enter */
			goto done_edit;
		}
		if( c == KEY_LEFT ){
			curifs=0xfffd;
			goto done_edit;
		}
		if( c == ' ' || c == KEY_RIGHT){		/* Space */
			curifs=0xffff;
			goto done_edit;
		}
		if( c == 0x9){		/* Tab */
			UHL;
			SF_GO_NEXT;
			while(ISNOSHOW)SF_GO_NEXT;
			HL;
			continue;
		}
                if( c == 0x1b){		/* Esc */
                        sawesc = 1;
                        continue;
                }
		if( c == 'k' - 'a' + 1){	/* el-kabulun */
			goto done_edit;
		}
		if( c == 'x'){		/* x */
			curifs=0xfffe;
			goto done_edit;
		}
		if( c == 'x' - 'a' + 1){	/* er-redd */
			curifs=0xfffe;
			goto done_edit;
		}
		if( c == 0x4){		/* Control - d */
			curifs=0xfffc;
			goto done_edit;
		}
		if( c == KEY_DOWN){
                        UHL;
			SF_GO_NEXT;
			while(ISNOSHOW)GO_NEXT;
			HL;
			continue;
		}
		if( c == KEY_UP){
                        UHL;
			SF_GO_PREV;
			while(ISNOSHOW)SF_GO_NEXT;
			HL;
			continue;
		}
		if(!sawesc && 
			(c >' '||
			 c == 'ð' ||
			 c == 'ü' ||
			 c == 'þ' ||
			 c == 'ö' ||
			 c == 'ç' ||
			 c == 'ý' ||
			 c == 'Ð' ||
			 c == 'Ü' ||
			 c == 'Þ' ||
			 c == 'Ý' ||
			 c == 'Ö' ||
			 c == 'Ç' 
			)){
			curifs = 0xf000+c;
			goto done_edit;
		}

	}
done_edit:

	return curifs;
}
/*-----------------------------------------------*/	
