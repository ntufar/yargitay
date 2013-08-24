#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <syslog.h>
#include <stdarg.h>
#include <time.h>
#include "wwwtools.h"


#define DEGISIKLER "degisikler.sql"
#define HAREKETLER "hareketler.log"




char Curusr[30];	/* Current User */
static char firsttime = 1;

char *strip(str)
	char *str;
{
	register int i;
	for(i=0;str[i];i++);
	for(;i>=0 && (isspace(str[i])||str[i]==0);i--)str[i]=0;
	return str;
}

char *dress(str,len)
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
int
inittools()
{
	strcpy(Curusr,getlogin());
	firsttime = 0;
}
/*--------------------------------*/

#define HEADER  	"\x1b\x5b\x35\x69"
#define TERMINATOR  	"\x1b\x5b\x34\x69"

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

		if(x == (unsigned char)'Ý') x = '˜';
		else if(x == (unsigned char)'Ð') x = '¦';
		else if(x == (unsigned char)'Þ') x = 'ž';
		else if(x == (unsigned char)'Ö') x = '™';
		else if(x == (unsigned char)'Ç') x = '€';
		else if(x == (unsigned char)'Ü') x = 'š';
		else if(x == (unsigned char)'ö') x = '”';
		else if(x == (unsigned char)'ü') x = '';
		else if(x == (unsigned char)'ç') x = '‡';
		else if(x == (unsigned char)'ð') x = '§';
		else if(x == (unsigned char)'ý') x = '';
		else if(x == (unsigned char)'þ') x = 'Ÿ';

		if (c==EOF)break;
		putchar(x);
	}
	puts(TERMINATOR);
	return 1;
}
/*--------------------------------*/
int
iso2dos(int c)
{
		unsigned char x;

		x = (unsigned char)c;

		if(x == (unsigned char)'Ý') x = '˜';
		else if(x == (unsigned char)'Ð') x = '¦';
		else if(x == (unsigned char)'Þ') x = 'ž';
		else if(x == (unsigned char)'Ö') x = '™';
		else if(x == (unsigned char)'Ç') x = '€';
		else if(x == (unsigned char)'Ü') x = 'š';
		else if(x == (unsigned char)'ö') x = '”';
		else if(x == (unsigned char)'ü') x = '';
		else if(x == (unsigned char)'ç') x = '‡';
		else if(x == (unsigned char)'ð') x = '§';
		else if(x == (unsigned char)'ý') x = '';
		else if(x == (unsigned char)'þ') x = 'Ÿ';
		return x;
}
/*--------------------------------*/
char *
striso2dos(char *str)
{
	int i;
	for(i=0; str[i]; i++)
		str[i]=iso2dos(str[i]);
	return str;
}
