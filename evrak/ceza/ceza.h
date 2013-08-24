/* in initceza.pc */
int initceza();
int shutceza();
extern yf *cgir;
extern yf *csor;
extern yf *csornson;
extern yf *sgir;
extern yf *skapatilmayan;
extern yf *fkptlmynlist;
extern yf *teslimlst;
extern yf *mahlist;

extern ym *maciklama;
extern ym *mcezamenu;
extern ym *mdosya;

extern char user[];
extern char home[];
extern char daire[];
extern char tarih[];
extern char yil[];
extern char yyil[];
extern int  superuser;


/* in ceza1.pc */
int kayitgir(int tekrar, int y1999);
int kayitsor();
int sonucgir();
int sonucsor();
int sonucduzelt();
int sonucsil();

/* in ceza5.pc */
int kptlmynlist(int guzellik);
int mahiyetliste();
int teslimlist();
int kapatilmayan();


/* in tools.c */
#include "tools.h"

/* in ceza.c */
char mydir[];

#define SQL_ERROR       sqlca.sqlcode < 0
#define SQL_NOTFOUND    sqlca.sqlcode == 1403
#define SQL_MESSAGE     sqlca.sqlerrm.sqlerrmc

