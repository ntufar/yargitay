/*
 *  evrak/hukuk/hukuk.c
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yf.h"
#include "hukuk.h"

char mydir[255];

int dosya();

main(argc,argv)
	int argc;
	char **argv;
{
	int cevap;
	char *b;
	char *b1;

        if(argv[0][0]=='-')strcpy(mydir,getenv("SHELL"));
        else strcpy(mydir,argv[0]);
	for(b=mydir,b1=mydir;*b;b++){
		if(*b == '/')b1=b;
	}
	if(b1==mydir)mydir[0]=0;
	else *(b1+1)=0;
	
	if(inithukuk()==0){printf("Baslangicta hata\n");exit(0);}
	while(1){
		cevap = yfmenu(mhukukmenu);
		switch(cevap){
		case '0':	
				yfmenu(maciklama);
				break;
		case '1':
				dosya();	
				break;
		case '2':teslimlist();break;	/* in hukuk5.pc */
		case '3':mahiyetliste(); break; /* in hukuk5.pc */
		case '4':kptlmynlist(1);break;	/* in hukuk5.pc */
		case '5':clear();refresh();
			 system("/usr/local/yargitay/evrak/sorgu/sorgu");

	/*	case '5':clear();refresh();system(getenv("SORGU"));*/
				break;
		case '6':hrehber();break;	/* in hukuk5.pc */
		case 'x':
		case 'X':shuthukuk();exit(0);
		default: continue;
		}
	}
}
/*------------------------------*/
dosya()
{
	int cevap;
	
	while(1){
		cevap = yfmenu(mdosya);
		switch(cevap){
		case '0':kayitgir(0,0);break;   /*in hukuk1.pc */
		case '1':kayitgir(1,0);break;   /*in hukuk1.pc */
		case '2':while(kayitsor());break;   /* in hukuk1.pc */
		case '3':kayitduzelt();break; /* in hukuk1.pc */
		case '4':sonucgir();break;	/* in hukuk1.pc */
		case '5':sonucsor();break;	/* in hukuk1.pc */
		case '6':sonucduzelt();break;	/* in hukuk1.pc */
		case '7':sonucsil();break;	/* in hukuk1.pc */
		case '8':kapatilmayan();break;	/* in hukuk5.pc */
		case '9':kayitgir(1,1);break;   /*in hukuk1.pc */
			break;
		case 'x':
		case 'X':
			return;
		}
	}
}
