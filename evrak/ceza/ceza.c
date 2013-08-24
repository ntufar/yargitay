#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yf.h"
#include "ceza.h"

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
        for(b=b1=mydir;*b;b++){
                if(*b == '/')b1=b;
        }
        if(b1==mydir)mydir[0]=0;
        else *(b1+1)=0;


	if(initceza()==0){printf("Baslangicta hata\n");exit(0);}
	while(1){
		cevap = yfmenu(mcezamenu);
		switch(cevap){
		case '0':	
				yfmenu(maciklama);
				break;
		case '1':
				dosya();	
				break;
		case '2':teslimlist();break;	/* in ceza5.pc */
		case '3':mahiyetliste(); break; /* in ceza5.pc */
		case '4':kptlmynlist(1);break;	/* in ceza5.pc */
		case '5':clear();refresh();
			 system("/usr/local/yargitay/evrak/sorgu/sorgu");
		/*case '5':clear();refresh();system(getenv("SORGU"));*/
				break;
		case 'x':
		case 'X':shutceza();exit(0);
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
		case '0':kayitgir(0,0);break;   /*in ceza1.pc */
		case '1':kayitgir(1,0);break;   /*in ceza1.pc */
		case '2':while(kayitsor());break;   /* in ceza1.pc */
		case '3':kayitduzelt();break; /* in ceza1.pc */
		case '4':sonucgir();break;	/* in ceza1.pc */
		case '5':sonucsor();break;	/* in ceza1.pc */
		case '6':sonucduzelt();break;	/* in ceza1.pc */
		case '7':sonucsil();break;	/* in ceza1.pc */
		case '8':kapatilmayan();break;	/* in ceza5.pc */
		case '9':kayitgir(1,1);break;   /*in ceza1.pc */
			break;
		case 'x':
		case 'X':
			return;
		}
	}
}
