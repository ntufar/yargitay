/*
 *  tools/tools.h
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */


/* Yargitay Forms Library */

/* Input field types */
#define IF_TEXT 	0
#define IF_NUMBER	1
#define IF_DATE		2
#define IF_YEAR		3

#define KEY_CHANGESENTURY	25

typedef struct{
	char text[100];
        int len;
        int maxlen;
        int ws;                 /* Window Start */
        int wl;                 /* Window Length */
        int cur;                /* Cursor */
	int bx,by,ex,ey;
	int edit;
	int type;
	int show;
	int y2k;
}inp;
typedef struct{
	char lines[30][85];
	char *_lines;
	inp ifs[50];
}yf;

typedef struct{
	char lines[30][85];
}ym;


int inityf();
int shutyf();
yf *initform(char *filename);
int closeform(yf *form);
int showform(yf *form);
int clearform(yf *form);
int superinputform(yf *form, int start);
int inputform(yf *form);
int outputform(yf *form);
int yfmessage(char *message);
int yfquestion(char *message);
ym *initmenu(char *filename);
int yfmenu(ym *menu);
int supermenu(yf *form,int cifs);

extern int messageline;
