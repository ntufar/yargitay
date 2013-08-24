/* in initceza.pc */
int initsorgu();
int shutsorgu();
extern yf *csor;
extern yf *hsor;

extern ym *maciklama;
extern ym *msorgumenu;

extern char user[];
extern char home[];
extern char daire[];
extern char tarih[];
extern char yil[];
extern char yyil[];


/* in tools.c */
#include "tools.h"

/* in sorgu.c */
char mydir[];


#define SQL_ERROR       sqlca.sqlcode < 0
#define SQL_NOTFOUND    sqlca.sqlcode == 1403
#define SQL_MESSAGE     sqlca.sqlerrm.sqlerrmc

/* in sorgu1.pc */
int cezasor();
int hukuksor();
