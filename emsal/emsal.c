#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yf.h"
#include "emsal.h"

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


	if(initemsal()==0){printf("Baslangicta hata\n");exit(0);}
	/*dosetdaire();*/
	while(1){
		cevap = yfmenu(emsalmenu);
		switch(cevap){
		case '0':	
				yfmenu(aciklama);
				break;
		case '1':kara(1);	/* in emsal1.c */
				break;
		case '2':kanara();break;	/* in ceza1.pc */
		case '3':esasara(); break; /* in ceza1.pc */
		case '4':dosetdaire(); break;	/* in ceza1.pc */
		case '5':clear();refresh();
			 system("/usr/local/yargitay/evrak/sorgu/sorgu");
			 break;	
		case 'x':
		case 'X':shutemsal();exit(0);
		default: continue;
		}
	}
}
/*------------------------------*/
