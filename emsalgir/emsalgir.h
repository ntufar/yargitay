#include "tools.h"

/* in initemsal.pc */
int initemsalgir();
int shutemsalgir();

extern yf *fkavram;
extern yf *fkanun;
extern yf *ftuze;
extern yf *fyenikanun;

extern ym *maciklama;
extern ym *memsalgir;
extern ym *memsalgir1;

extern char user[30];
extern char home[255];
extern char daire[21];
extern char tarih[11];
extern char yil[3];
extern char yyil[3];


/* in emsalgir1.pc */
int kavramgir();
int kanungir();
char *yenikanun(long ikanunno);  /* internal */

#define SQL_ERROR 	sqlca.sqlcode < 0
#define SQL_NOTFOUND	sqlca.sqlcode == 1403
#define SQL_MESSAGE	sqlca.sqlerrm.sqlerrmc
