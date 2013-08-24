/*
 *  evrak/hukuk/hukuk.h
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */

/* in initceza.pc */
int inithukuk();
int shuthukuk();
extern yf *cgir;
extern yf *csor;
extern yf *sgir;
extern yf *skapatilmayan;
extern yf *fkptlmynlist;
extern yf *teslimlst;
extern yf *mahlist;
extern yf *rehber;

extern ym *maciklama;
extern ym *mdosya;
extern ym *mhukukmenu;

extern char user[];
extern char home[];
extern char daire[];
extern char tarih[];
extern char yil[];
extern char yyil[];
extern int  superuser;


/* in hukuk1.pc */
int kayitgir(int tekrar, int y1999);
int kayitsor();
int sonucgir();
int sonucsor();
int sonucduzelt();
int sonucsil();

/* in hukuk5.pc */
int kptlmynlist(int guzellik);
int mahiyetliste();
int teslimlist();
int kapatilmayan();
int hrehber();


/* in tools.c */
#include "tools.h"

/* in hukuk.c */
char mydir[];

#define SQL_ERROR       sqlca.sqlcode < 0
#define SQL_NOTFOUND    sqlca.sqlcode == 1403
#define SQL_MESSAGE     sqlca.sqlerrm.sqlerrmc

