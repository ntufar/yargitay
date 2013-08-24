/*****************
 * Thor editor project
 * visual stuff
 * Maintained by Nicholas Tufar
 * vi.c
 ****************/
#include <thordefs.h>
#include <signal.h>
#include <string.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ctype.h>
#include "vi.h"

WINDOW *Area=NULL;
WINDOW *Loft=NULL;
WINDOW *Statusline=NULL;

char Loftmessage[80];

short Maxy;
short Maxx;
/*------------------------------------*/
int initthor(maxy,maxx,by,bx)
	int maxy, maxx, by, bx;
{
	WINDOW  *basescreen;

	if(Area != NULL)return 0;	/* Already initialized */
        /*basescreen  = initscr(); since curses are initialized by
			yf library there is no need to do it again */
	basescreen = stdscr;
	Maxy = basescreen->_maxy < maxy + by? basescreen->_maxy : maxy;
	Maxx = basescreen->_maxx < maxx + bx? basescreen->_maxx : maxx;
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
	if(inittext()==0)return 0;
	Curpar = Curline = Curpos = Upperline = 0;
	Area = newwin( Maxy /*- by*/ - 2, Maxx, by+1, bx);
	Loft = newwin(1, Maxx, by, bx);
	Statusline = newwin(1, Maxx, Maxy + by - 1, bx);
	if(Area == NULL) return 0;
	if(Loft == NULL) return 0;
	if(Statusline == NULL) return 0;
	Upperline = 0;
	strcpy(Loftmessage,"Thor Editor");
	return 1;
}
/*------------------------------------*/
shutthor()
{
	delwin(Area);
	delwin(Statusline);
	delwin(Loft);
	Area = Statusline = Loft = NULL;
	endwin();
}
/*------------------------------------*/
int repaintthor()
{
	repaint();
	repaintstatus();
	repaintloft();
	return 0;
}
/*------------------------------------*/
int repaint()
{
	int y,x;
	int i,k,m;
	char buf[100];
	
	getyx(Area,y,x);
	for(i = 0, k = Upperline; i < Maxy - 2  && k < Textlines;i++, k++){
		wmove(Area,i,0);
		wprintw(Area,"                                        "\
			     "                                        ");
		wmove(Area,i,0);
		strncpy(buf,getline(k),80);
		buf[79]=0;
		/* printw hangs if string has tabulation and exceeds
		   80 characters. so I replace tabs with spaces */
		for(m=0;buf[m];m++)
			if(buf[m]=='\t')buf[m]=' ';
		wprintw(Area,"%s",buf);
	}
	/*if( k == Textlines ){
		wmove(Area,i,0);
		wprintw(Area,">>EOF<<");
	}*/
	wmove(Area,y,x);
	wrefresh(Area);
}
/*------------------------------------*/
int repaintstatus()
{
	int x,y;
	getyx(Area,y,x);
	wattrset(Statusline, A_REVERSE);
	wmove(Statusline,0,0);
	wprintw(Statusline,"                                        "\
			"                                        ");
	wmove(Statusline,0,0);
	wprintw(Statusline,"Satir: %3d    Sutun: %3d",y+Upperline+1,x+1);
	wrefresh(Statusline);
	wmove(Area,y,x);
	wrefresh(Area);
}
/*------------------------------------*/
int thorsetloft(message)
	char *message;
{
	strncpy(Loftmessage,message,80);
	return 1;
}
/*------------------------------------*/
int repaintloft()
{
	int x,y;
	getyx(Area,y,x);
	wattrset(Loft, A_REVERSE);
	wmove(Loft,0,0);
	wprintw(Loft,"                                        "\
			"                                        ");
	wmove(Loft,0,0);
	wprintw(Loft,Loftmessage);
	wrefresh(Loft);
	wmove(Area,y,x);
	wrefresh(Area);
}
/*------------------------------------*/
int edit(ro)
	int ro;
{
	int c;
	int x,y;
	char *buf;

	repaint();
	while(1){
		repaintstatus();
		repaintloft();
		c = nttgetch();
		switch(c){
		/*-------*/
		case KEY_UP:
			getyx(Area,y,x);
			if(y == 0){
				if(Upperline != 0){
					Upperline--;
					repaint();
					wmove(Area,0,x);
					wrefresh(Area);
				}
			}else{
				wmove(Area,y-1,x);
				wrefresh(Area);
			}
			break;
		/*-------*/
		case KEY_DOWN:
			getyx(Area,y,x);
			if(y == Maxy - 2 -1){
				if(Textlines - Upperline > Maxy - 2){
					Upperline++;
					wmove(Area,y,x);
					repaint();
				}
			}else{ 
				wmove(Area,y+1,x);
				wrefresh(Area);
			}
			break;
		/*-------*/
		case KEY_PPAGE:
			getyx(Area,y,x);
			if(Upperline - Maxy - 2 < 0)Upperline = 0;
			else Upperline -= Maxy - 2;
			repaint();
			break;
		/*-------*/
		case KEY_NPAGE:
			getyx(Area,y,x);
			if(Textlines - Upperline < (Maxy - 2) * 2)
				Upperline = Textlines - Maxy - 2;
			else Upperline += Maxy - 2;
			repaint();
			break;
		/*-------*/
		case KEY_LEFT:
			getyx(Area,y,x);
			wmove(Area,y,x-1);
			wrefresh(Area);
			break;
		/*-------*/
		case KEY_RIGHT:
			getyx(Area,y,x);
			wmove(Area,y,x+1);
			wrefresh(Area);
			break;
		/*-------*/
		case KEY_HOME:
			/* make cursor move to the first non blank char*/
			getyx(Area,y,x);
			wmove(Area,y,0);
			wrefresh(Area);
			break;
		/*-------*/
		case KEY_END:
			/* make cursor move to the last non blank char*/
			getyx(Area,y,x);
			buf=getline(y+Upperline);
			wmove(Area,y,strlen(buf));
			wrefresh(Area);
			break;
		/*-------*/
		case KEY_SAVE:
			getfile(Area, Statusline);
			break;
		/*-------*/
		/*case 'Q':
			thorreadfile("/home/proje/981519.4c");
			Upperline = 0;
			repaint();
			break;*/
		/*-------*/
		case 0x08:
		case KEY_BACKSPACE:
			getyx(Area,y,x);
			Curline = Upperline+y;
			Curpos = x;
			delete();
			wmove(Area, Curline - Upperline, Curpos);
			repaint();
			break;
		/*-------*/
		case 'x'-'a'+1:return 1;
		case 9:return 0;
		default:
			if(ro)break;
			if(isprint(c)||c=='\n'||c=='\t'){
				getyx(Area,y,x);
				Curline = Upperline+y;
				Curpos = x;
				/*repaint();*/
				insert(c);
				if(Curline - Upperline >= NLINES)Upperline++;
				wmove(Area, Curline - Upperline, Curpos);
				repaint();
			}
			break;
		} /*switch*/
	} /* while */
}
/*------------------------------------*/
int nttgetch()
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
	if( c == 0x7f || c == 0x8 || c == 0x107)return KEY_BACKSPACE;

        if(c == 0x1b ){
        	sawesc = 1;
                nodelay(stdscr,1);
                /* Watch stdin (fd 0) to see when it has input. */
                FD_ZERO(&rfds);
                FD_SET(0, &rfds);
                /* Wait up to five seconds. */
                tv.tv_sec = 0;
                tv.tv_usec = 300000L;   /* 0.5 saniye */
                retval = select(1, &rfds, NULL, NULL, &tv);
                nodelay(stdscr,0);
                if (retval==0)return 0x1b;   /* there is input in stdin */
		c = getch();
        }
	if( c == 0x5b){
		c = getch();
		switch(c){
		case 0x41:return KEY_UP;
		case 0x42:return KEY_DOWN;
		case 0x43:return KEY_RIGHT;
		case 0x44:return KEY_LEFT;
		case 0x35:
			c = getch();
			return KEY_PPAGE;
		case 0x36:
			c = getch();
			return KEY_NPAGE;
		case 0x31:
			c = getch();
			return KEY_HOME;
		case 0x34:
			c = getch();
			return KEY_END;
		case 0x5b:
			c = getch();
			switch(c){
			case 0x41:return KEY_HELP;
			case 0x42:return KEY_SAVE;
			case 0x43:return KEY_OPEN;
			}
		default: wprintw(Area,"%x",c);refresh();break;
		}
	}
	return c;

}
/*-----------------------------------------------*/
/*------------------------------------*/
/*------------------------------------*/
/*------------------------------------*/
