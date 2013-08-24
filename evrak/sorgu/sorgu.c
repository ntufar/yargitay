#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yf.h"
#include "sorgu.h"

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


	if(initsorgu()==0){printf("Baslangicta hata\n");exit(0);}
	while(1){
		cevap = yfmenu(msorgumenu);
		switch(cevap){
		case '0':	
				yfmenu(maciklama);
				break;
		case '2': while(cezasor());	/* in sorgu1.pc  */
				break;
		case '1': while(hukuksor());	/* in sorgu1.pc */
		case '3':
				break;
		case 'x':
		case 'X':shutsorgu();exit(0);
		default: continue;
		}
	}
}
/*------------------------------*/
