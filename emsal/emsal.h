#include "tools.h"

/* in initemsal.pc */
int initemsal();
extern yf *sm;
extern yf *fkara;
extern yf *fkara1;
extern yf *fkanara;
extern yf *fkanara1;
extern yf *fkanara2;
extern yf *setdaire;
extern yf *esara;
extern ym *emsalmenu;
extern ym *aciklama;

extern char user[30];
extern char home[255];
extern char daire[21];
extern char tarih[11];
extern char yil[3];
extern char yyil[3];


/* in emsal1.pc */
int kara(int kendi);
int kanara();
int esasara();
int dosetdaire();


#define SQL_ERROR 	sqlca.sqlcode < 0
#define SQL_NOTFOUND	sqlca.sqlcode == 1403
#define SQL_MESSAGE	sqlca.sqlerrm.sqlerrmc
