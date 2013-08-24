#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yf.h"
#include "emsalgir.h"

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


	if(initemsalgir()==0){printf("Baslangicta hata\n");exit(0);}

	while(1){
		cevap = yfmenu(memsalgir);
		switch(cevap){
                case '0':
                                yfmenu(maciklama);
                                break;

		case '1':girme();break;
                case '2':clear();refresh();
                         system("/usr/local/yargitay/emsal/emsal");
                         break;
                case 'x':
                case 'X':shutemsalgir();exit(0);
		default: continue;
		}
	}

}
/*------------------------------*/
girme()
{
	int cevap;
	while(1){
		cevap = yfmenu(memsalgir1);
		switch(cevap){
		case '1':kavramgir();
				break;
		case '2':kanungir();
				break;
		case '3':tuzegir();
				break;

		case 'x':
		case 'X':return;
		default: continue;
		}
	}
}
