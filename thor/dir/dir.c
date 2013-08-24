/********************
 * Thor editor project
 * routines to display files in directory
 * dir.c
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <curses.h>
#include <thordefs.h>
#include "dir.h"

char **initfilelist();
int freefilelist(char **filelist);

int Activefile = 0;
int Totalfiles = 0;
/*----------------------------------------*/
/*----------------------------------------*/
showstatus(statusline,filelist)
WINDOW *statusline;
char **filelist;
{
        wattrset(statusline, A_REVERSE);
        wmove(statusline,0,0);
        wprintw(statusline,"                                        "\
                        "                                        ");
        wmove(statusline,0,0);
        wprintw(statusline,"%s",filelist[Activefile]);
        wrefresh(statusline);
}

/*----------------------------------------*/
showlist(area,filelist)
WINDOW *area;
char **filelist;
{
	int i;
	int count;
	
	werase(area);

	for(i=0,count=0;filelist[i][0] && count <44;i++, count++){
		wmove(area,count >= 22? count - 22:count,count >= 22? 42:2);
		if(Activefile==i) wattrset(area, A_REVERSE);
		wprintw(area,filelist[i]);
		if(Activefile==i) wattrset(area, A_NORMAL);
	}
	wrefresh(area);
}
/*----------------------------------------*/
char *getfile(area, statusline)
WINDOW *area;
WINDOW *statusline;
{
	int i;
	int c;

	char **filelist = initfilelist();

	Activefile = 0;
	while(1){
		showlist(area,filelist);
		showstatus(statusline,filelist);
		/*c = ntgetch();*/
		switch(c){	
		/*-------*/
		case KEY_UP:
			if(Activefile)Activefile--;
			break;
		/*-------*/
		case KEY_DOWN:
			if(Activefile!=43 && Activefile < Totalfiles)Activefile++;
			break;
		/*-------*/
		case KEY_PPAGE:
			break;
		/*-------*/
		case KEY_NPAGE:
			break;
		/*-------*/
		case KEY_LEFT:
			if(Activefile > 22)Activefile-=22;
			else if(Activefile+22 < Totalfiles)Activefile+=22;
			break;
		/*-------*/
		case KEY_RIGHT:
			if(Activefile < 22){
				if(Activefile+22 < Totalfiles)
							Activefile+=22;
			} else Activefile-=22;
			break;
		/*-------*/
		case KEY_HOME:
			break;
		/*-------*/
		case KEY_END:
			break;
		/*-------*/
		case 'x'-'a'+1:
			freefilelist(filelist);
			return;
		default:
			break;
		} /*switch*/
	} /* while */
	
	
}

/*----------------------------------------*/
/*----------------------------------------*/
/*----------------------------------------*/
char **initfilelist(path)
	char	*path;
{
	DIR *directory;
	struct dirent *entry;
	char **filelist;
	int i;

	/*strcpy(path,getenv("HOME"));
	strcat(path,"/");
	strcat(path,DOCDIRECTORY);*/

	directory=opendir(path);
	if(directory==NULL)return (char**)NULL;
	filelist = (char**)malloc(sizeof(char**)*1024);
	for(i=0;1;i++){
		filelist[i]=(char*)malloc(sizeof(char)*256);
		if(filelist[i]==NULL)return 0;
		filelist[i][0]=0;

		entry = readdir(directory);
		if(entry==NULL)break;
		if(entry->d_name[0]=='.'){i--;continue;}
		strcpy(filelist[i],entry->d_name);
	}
	Totalfiles = i-1;
	
	return filelist;
}

/*----------------------------------------*/
int freefilelist(filelist)
char **filelist;
{
	int i;
	for(i=0;filelist[i][0]!=0;i++){
		free(filelist[i]);
	}
	free(filelist);
	return 0;
}

/*----------------------------------------*/
