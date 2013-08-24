
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,0,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[9];
};
static struct sqlcxp sqlfpn =
{
    8,
    "ceza1.pc"
};


static unsigned long sqlctx = 17715;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   unused;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[21];
   unsigned int   sqhstl[21];
            int   sqhsts[21];
            void  *sqindv[21];
            int   sqinds[21];
   unsigned int   sqharm[21];
   unsigned int   *sqharc[21];
   unsigned short  sqadto[21];
   unsigned short  sqtdso[21];
} sqlstm = {10,21};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned long *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned long *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned long *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

 static char *sq0006 = 
"select id ,daireno ,esassirayil ,esassirano ,geldigitarih ,tebligtarih ,tebl\
igmasa ,tebligno ,esasno ,kararno ,gonderenmahkeme ,sucunturu ,temyizeden ,tut\
uklu  from gelendosya where ((daireno=:b0 and esassirayil=:b1) and esassirano=\
:b2) for update ";

 static char *sq0012 = 
"select daireno ,esassirayil ,esassirano ,geldigitarih ,tebligtarih ,tebligma\
sa ,tebligno ,esasno ,kararno ,gonderenmahkeme ,sucunturu ,temyizeden ,tutuklu\
  from gelendosya where ((daireno=:b0 and esassirayil=:b1) and esassirano=:b2)\
 for update ";

 static char *sq0019 = 
"select kararsonucu.id ,kararsonucu.daireno ,kararsonucu.esassirayil ,kararso\
nucu.esassirano ,kararsonucu.karsonucu ,kararsonucu.karartarihi ,kararsonucu.k\
ararnumarasi ,kararsonucu.gonderilistarihi ,gelendosya.geldigitarih ,gelendosy\
a.tebligtarih ,gelendosya.tebligmasa ,gelendosya.tebligno ,gelendosya.esasno ,\
gelendosya.kararno ,gelendosya.gonderenmahkeme ,gelendosya.sucunturu ,gelendos\
ya.temyizeden ,gelendosya.tutuklu  from kararsonucu ,gelendosya where (((karar\
sonucu.daireno=:b0 and kararsonucu.esassirayil=:b1) and kararsonucu.esassirano\
=:b2) and kararsonucu.id=gelendosya.kararsonucu) for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4114,0,0,0,
5,0,0,1,91,0,4,110,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
32,0,0,2,223,0,3,236,0,0,13,13,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
99,0,0,3,0,0,29,295,0,0,0,0,0,1,0,
114,0,0,4,0,0,17,496,0,0,1,1,0,1,0,1,5,0,0,
133,0,0,4,0,0,45,502,0,0,0,0,0,1,0,
148,0,0,4,0,0,13,506,0,0,14,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,
5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
219,0,0,4,0,0,15,522,0,0,0,0,0,1,0,
234,0,0,5,186,0,4,556,0,0,5,1,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,3,0,0,
269,0,0,6,248,0,9,704,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
296,0,0,6,0,0,13,714,0,0,14,0,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,
5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
367,0,0,7,0,0,31,820,0,0,0,0,0,1,0,
382,0,0,8,184,0,46,915,0,0,10,10,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
437,0,0,6,0,0,15,1007,0,0,0,0,0,1,0,
452,0,0,9,0,0,29,1008,0,0,0,0,0,1,0,
467,0,0,6,0,0,15,1010,0,0,0,0,0,1,0,
482,0,0,10,0,0,31,1011,0,0,0,0,0,1,0,
497,0,0,11,97,0,4,1153,0,0,4,3,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
528,0,0,12,244,0,9,1176,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
555,0,0,12,0,0,13,1177,0,0,13,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
622,0,0,13,0,0,31,1234,0,0,0,0,0,1,0,
637,0,0,14,145,0,3,1281,0,0,7,7,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
1,3,0,0,1,5,0,0,
680,0,0,15,142,0,46,1358,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
707,0,0,12,0,0,15,1383,0,0,0,0,0,1,0,
722,0,0,16,0,0,29,1384,0,0,0,0,0,1,0,
737,0,0,12,0,0,15,1386,0,0,0,0,0,1,0,
752,0,0,17,0,0,31,1387,0,0,0,0,0,1,0,
767,0,0,18,724,0,4,1521,0,0,20,3,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
862,0,0,19,604,0,9,1799,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
889,0,0,19,0,0,13,1808,0,0,18,0,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,
2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,
976,0,0,20,0,0,31,1891,0,0,0,0,0,1,0,
991,0,0,21,105,0,5,1941,0,0,5,5,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,
1026,0,0,19,0,0,15,1998,0,0,0,0,0,1,0,
1041,0,0,22,0,0,29,1999,0,0,0,0,0,1,0,
1056,0,0,19,0,0,15,2001,0,0,0,0,0,1,0,
1071,0,0,23,0,0,31,2002,0,0,0,0,0,1,0,
1086,0,0,24,749,0,4,2137,0,0,21,3,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
1185,0,0,25,58,0,5,2244,0,0,1,1,0,1,0,1,3,0,0,
1204,0,0,26,38,0,2,2256,0,0,1,1,0,1,0,1,3,0,0,
1223,0,0,27,0,0,29,2279,0,0,0,0,0,1,0,
1238,0,0,28,0,0,31,2282,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include "yf.h"
#include "tools.h"
#include "ceza.h"
#define KAYIT_GIRILSIN_MI \
	do{\
		stat = yfquestion("Bu kayýt girilsin mi? (e/h)"); \
	}while(stat != 'e' && stat != 'E' && stat !='H' && stat != 'h')

/* EXEC SQL INCLUDE SQLCA;
 */ 
/*
 * $Header: sqlca.h,v 1.3 1994/12/12 19:27:27 jbasu Exp $ sqlca.h 
 */

/* Copyright (c) 1985,1986 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ long    sqlabc;
         /* b4  */ long    sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ long    sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


kayitgir(tekrarli, y1999)
	int tekrarli;
	int y1999;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

	long enbuyukesas;
	char tamyil[5];

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;
	int startfield=0;
	int i;

	showform(cgir);
	/* masa */
	for(i=0;daire[i];i++){
		if(!isdigit(daire[i]))break;
		buf[i]=daire[i];
	}
	buf[i]=0; 
	strcpy(cgir->ifs[5].text,buf);
kgyenikayit:
	refreshtime();		
	cgir->ifs[0].edit = 1;
	cgir->ifs[1].edit = 1;
	cgir->ifs[2].edit = 1;
	cgir->ifs[3].edit = 1;
	cgir->ifs[4].edit = 1;
	cgir->ifs[5].edit = 1;
	cgir->ifs[6].edit = 1;
	cgir->ifs[7].edit = 1;
	cgir->ifs[8].edit = 1;
	cgir->ifs[9].edit = 1;
	cgir->ifs[10].edit = 1;
	cgir->ifs[11].edit = 1;
	cgir->ifs[12].edit = 1;

	if(y1999){
                strcpy(yyil,"19");
                strcpy(yil,"99");
                strcpy(tamyil,"1999");
                strcpy(tarih,"30/12/1999");
	}

	if(!tekrarli){
		clearform(cgir);
	}else{
		cgir->ifs[4].edit = 0;
		cgir->ifs[5].edit = 0;
		cgir->ifs[9].edit = 0;
		cgir->ifs[10].edit = 0;
		clearform(cgir);
		cgir->ifs[4].edit = 1;
		cgir->ifs[5].edit = 1;
		cgir->ifs[9].edit = 1;
		cgir->ifs[10].edit = 1;
	}

	strcpy(cgir->ifs[0].text, daire);
	dress(daire,3);
	
	strcpy(cgir->ifs[1].text,yyil);
	strcat(cgir->ifs[1].text,yil);
	dress(yil,2);

	strcpy(cgir->ifs[3].text,tarih);
	cgir->ifs[3].edit = 0;

	/*yfmessage("Lütfen bekleyiniz...");*/
	strcpy(tamyil,yyil);
	strcat(tamyil,yil);
	/* EXEC SQL SELECT MAX(esassirano) INTO :enbuyukesas:ind1 FROM gelendosya
		WHERE daireno = :daire AND esassirayil = :tamyil; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select max(esassirano) into :b0:b1  from gelendosya where (d\
aireno=:b2 and esassirayil=:b3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&enbuyukesas;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind1;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)daire;
 sqlstm.sqhstl[1] = (unsigned int  )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)tamyil;
 sqlstm.sqhstl[2] = (unsigned int  )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(sqlca.sqlcode < 0){
		yfquestion(sqlca.sqlerrm.sqlerrmc);
		return 0;
	}
	if(sqlca.sqlcode == 1403){
		yfquestion(sqlca.sqlerrm.sqlerrmc);
		return 0;
	}
	/*yfmessage(" ");*/
	
	if(ind1 == -1 || enbuyukesas == 0)enbuyukesas = 1;
	else enbuyukesas++;
	sprintf(buf,"%lu",enbuyukesas);
	strcpy(cgir->ifs[2].text,buf);
	cgir->ifs[2].edit=0;


	cgir->ifs[0].edit = 0;
	cgir->ifs[1].edit = 0;
	cgir->ifs[2].edit = 0;
	cgir->ifs[3].edit = 0;
	cgir->ifs[4].edit = 1;
	cgir->ifs[5].edit = 1;
	cgir->ifs[6].edit = 1;
	cgir->ifs[7].edit = 1;
	cgir->ifs[8].edit = 1;
	cgir->ifs[9].edit = 1;
	cgir->ifs[10].edit = 1;
	cgir->ifs[11].edit = 1;
	cgir->ifs[12].edit = 1;

	outputform(cgir);
	if(!tekrarli)startfield = 0;
kgyineden:
	stat = superinputform(cgir, startfield);
	if (stat == 0){
		refreshtime();
		return 1;
	}

	/* Insert new values */
	strcpy(daireno,	cgir->ifs[0].text);
	daireno[3]=0;

	strcpy(esassirayil,	cgir->ifs[1].text);
	esassirayil[4]=0;

	esassirano = atol(cgir->ifs[2].text);

	strcpy(geldigitarih,cgir->ifs[3].text);
	geldigitarih[10]=0;

	strcpy(tebligtarih,	cgir->ifs[4].text);
	tebligtarih[10]=0;
	if(tebligtarih[0]==0){
		yfmessage("Teblið tarihi geçersiz");
		startfield = 4;
		goto kgyineden;
	}

	strcpy(tebligmasa,	cgir->ifs[5].text);
	tebligmasa[2]=0;
	if(tebligmasa[0]==0){
		yfmessage("Teblið masasý geçersiz");
		startfield = 5;
		goto kgyineden;
	}

	tebligno = atol(cgir->ifs[6].text);
	if(tebligno == 0){
		yfmessage("Teblið numarasý geçersiz");
		startfield = 6;
		goto kgyineden;
	}

	esasno = atol(cgir->ifs[7].text);
	if(esasno == 0){
		yfmessage("Esas numarasý geçersiz");
		startfield = 7;
		goto kgyineden;
	}

	kararno = atol(cgir->ifs[8].text);
	if(kararno == 0){
		yfmessage("Karar numarasý geçersiz");
		startfield = 8;
		goto kgyineden;
	}

	strcpy(gonderenmahkeme,cgir->ifs[9].text);
	gonderenmahkeme[31]=0;
	if(gonderenmahkeme[0]==0){
		yfmessage("Gönderen mahkeme geçersiz");
		startfield = 9;
		goto kgyineden;
	}

	strcpy(sucunturu,	cgir->ifs[10].text);
	sucunturu[31]=0;
	if(sucunturu[0]==0){
		yfmessage("Suçun türü geçersiz");
		startfield = 10;
		goto kgyineden;
	}

	strcpy(temyizeden,	cgir->ifs[11].text);
	temyizeden[50]=0;
	if(temyizeden[0]==0){
		yfmessage("Sanýk adý geçersiz");
		startfield = 11;
		goto kgyineden;
	}

	strcpy(tutuklu,	cgir->ifs[12].text);
	tutuklu[31]=0;
	/*if(tutuklu[0]==0){
		yfmessage("Tutuklu bilgileri geçersiz");
		startfield = 12;
		goto kgyineden;
	}*/
	
	KAYIT_GIRILSIN_MI;	
        if (stat == 'e' || stat == 'E'){
	
		/* EXEC SQL INSERT INTO gelendosya 
			(
			DAIRENO, ESASSIRAYIL, ESASSIRANO,
			GELDIGITARIH, TEBLIGTARIH,
			TEBLIGMASA, TEBLIGNO, ESASNO,
			KARARNO, GONDERENMAHKEME, 
			SUCUNTURU, TEMYIZEDEN, TUTUKLU
			)
			VALUES(
			:daireno, :esassirayil, :esassirano,
			:geldigitarih, :tebligtarih, :tebligmasa,
			:tebligno, :esasno, :kararno,
			:gonderenmahkeme, :sucunturu, 
			:temyizeden, :tutuklu); */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into gelendosya(DAIRENO,ESASSIRAYIL,ESASSIRANO,GELDI\
GITARIH,TEBLIGTARIH,TEBLIGMASA,TEBLIGNO,ESASNO,KARARNO,GONDERENMAHKEME,SUCUNTU\
RU,TEMYIZEDEN,TUTUKLU) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b\
11,:b12)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)daireno;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)esassirayil;
  sqlstm.sqhstl[1] = (unsigned int  )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&esassirano;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)geldigitarih;
  sqlstm.sqhstl[3] = (unsigned int  )11;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)tebligtarih;
  sqlstm.sqhstl[4] = (unsigned int  )11;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)tebligmasa;
  sqlstm.sqhstl[5] = (unsigned int  )3;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&tebligno;
  sqlstm.sqhstl[6] = (unsigned int  )4;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&esasno;
  sqlstm.sqhstl[7] = (unsigned int  )4;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&kararno;
  sqlstm.sqhstl[8] = (unsigned int  )4;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)gonderenmahkeme;
  sqlstm.sqhstl[9] = (unsigned int  )32;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)sucunturu;
  sqlstm.sqhstl[10] = (unsigned int  )32;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)temyizeden;
  sqlstm.sqhstl[11] = (unsigned int  )51;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)tutuklu;
  sqlstm.sqhstl[12] = (unsigned int  )32;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		if (SQL_ERROR){
			ntlog2(LOG_CEZA,"kayitgir.SQL_INSERT",SQL_MESSAGE);
			yfmessage(SQL_MESSAGE);
			goto kgyineden;
		}
		{
		char	x1[1024];
		char	x2[1024];
		char	x3[1024];
		char	x4[1024];
		char	x5[1024];
		char	x6[1024];
		char	x7[1024];
		/*char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(daireno));
		strcpy(x2, quote(esassirayil));
		strcpy(x3, quote(tebligmasa));
		strcpy(x4, quote(gonderenmahkeme));
		strcpy(x5, quote(sucunturu));
		strcpy(x6, quote(temyizeden));
		strcpy(x7, quote(tutuklu));
		ntchanges("INSERT INTO gelendosya VALUES(\n"
			"\t'%s',\t'%s',\t%lu,\n"
			"\t'%s',\t'%s',\t'%s',\n"
			"\t%lu,\t%lu,\t%lu,\n"
			"\t'%s',\t'%s',\n"
			"\t'%s',\t'%s');\n",
			x1, x2, esassirano,
			geldigitarih, tebligtarih, x3,
			tebligno, esasno, kararno,
			x4, x5, 
			x6, x7);
		}
			/*daireno, esassirayil, esassirano,
			geldigitarih, tebligtarih, tebligmasa,
			tebligno, esasno, kararno,
			gonderenmahkeme, sucunturu, 
			temyizeden, tutuklu);*/
		nthareket("ceza: dosya gir");

		/* EXEC SQL COMMIT WORK ; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )99;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		yfmessage("Kayýt kaydedildi");
	} else yfmessage("Kayýt iptal edildi");
	if(tekrarli)startfield=6;
	goto kgyenikayit;
}
/**************************** Sorgu ************************/
int kayitsor()
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/*------------- Kararsonucu ------------*/
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skararsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7;
	/*------------- Gelendosya ------------*/
        char daireno[100];
        char esassirayil[100];
        char esassirano[100];
        char geldigitarih[100];
        char tebligtarih[100];
	char tebligmasa[100];
	char tebligno[100];
        char esasno[100];
        char kararno[100];
	char gonderenmahkeme[100];
	char sucunturu[100];
	char temyizeden[100];
	char tutuklu[100];
	long p_kararsonucu;

	long essno;
	long tblno;
	long esno;
	long karno;

	char buf[1000];
	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13, ind14;
	SQL_CURSOR cur;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	int waswhere = 0;
	int returnvalue = 0;


	nthareket("ceza: dosya sor");
yenidensor:
	clearform(csornson);
	csornson->ifs[0].edit = 1;
	csornson->ifs[1].edit = 1;
	csornson->ifs[2].edit = 1;
	csornson->ifs[3].edit = 1;
	csornson->ifs[4].edit = 1;
	csornson->ifs[5].edit = 1;
	csornson->ifs[6].edit = 1;
	csornson->ifs[7].edit = 1;
	csornson->ifs[8].edit = 1;
	csornson->ifs[9].edit = 1;
	csornson->ifs[10].edit = 1;
	csornson->ifs[11].edit = 1;
	csornson->ifs[13].edit = 1;
	csornson->ifs[14].edit = 1;
	csornson->ifs[15].edit = 1;
	csornson->ifs[16].edit = 1;
	clearform(csornson);
	csornson->ifs[13].edit = 0;
	csornson->ifs[14].edit = 0;
	csornson->ifs[15].edit = 0;
	csornson->ifs[16].edit = 0;
	showform(csornson);

        strcpy(csornson->ifs[0].text, daire);
	outputform(csornson);

	i = inputform(csornson);
	if(i == 0)return 0;
	strcpy(daireno,		csornson->ifs[0].text);
	strcpy(esassirayil,	csornson->ifs[1].text);
	strcpy(esassirano,	csornson->ifs[2].text);
	strcpy(geldigitarih,	csornson->ifs[3].text);
	strcpy(tebligtarih,	csornson->ifs[4].text);
	strcpy(tebligmasa,	csornson->ifs[5].text);
	strcpy(tebligno,	csornson->ifs[6].text);
	strcpy(esasno,		csornson->ifs[7].text);
	strcpy(kararno,		csornson->ifs[8].text);
	strcpy(gonderenmahkeme,	csornson->ifs[9].text);
	strcpy(sucunturu,	csornson->ifs[10].text);
	strcpy(temyizeden,	csornson->ifs[11].text);
	strcpy(tutuklu,		csornson->ifs[12].text);
	

        strcpy(buf,"select "
                "g.daireno, g.esassirayil, g.esassirano, g.geldigitarih,"
                "g.tebligtarih, g.tebligmasa, g.tebligno, g.esasno,"
                "g.kararno, g.gonderenmahkeme, g.sucunturu,"
                "g.temyizeden, g.tutuklu, g.kararsonucu "
	/*	"k.karsonucu, k.karartarihi, "
		"k.kararnumarasi, k.gonderilistarihi "*/
                "from gelendosya g "/*, kararsonucu k "
		"where g.kararsonucu = k.id "*/
	       ); 
	/***********************/
	if(strcmp(esassirayil,"19")==0||strcmp(esassirayil,"20")==0)esassirayil[0]=0;
        if(daireno[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.daireno = '");
                strcat(buf,quote(daireno));
                strcat(buf,"'");
        }
        if(esassirayil[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.esassirayil = '");
                strcat(buf,esassirayil);
                strcat(buf,"'");
        }
        if(esassirano[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.esassirano =");
                strcat(buf,esassirano);
        }
        if(geldigitarih[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.geldigitarih ='");
                strcat(buf,quote(geldigitarih));
                strcat(buf,"'");
        }
        if(tebligtarih[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.tebligtarih = '");
                strcat(buf,quote(tebligtarih));
                strcat(buf,"'");
        }
        if(tebligmasa[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.tebligmasa like '");
                strcat(buf,quote(tebligmasa));
                strcat(buf,"%'");
        }
        if(tebligno[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.tebligno =");
                strcat(buf,tebligno);
        }
        if(esasno[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.esasno =");
                strcat(buf,esasno);
        }
        if(kararno[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.kararno =");
                strcat(buf,kararno);
        }
        if(gonderenmahkeme[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.gonderenmahkeme like '");
                strcat(buf,quote(gonderenmahkeme));
                strcat(buf,"%'");
        }
        if(sucunturu[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.sucunturu like '");
                strcat(buf,quote(sucunturu));
                strcat(buf,"%'");
        }
        if(temyizeden[0]!=0){
		if(!waswhere){strcat(buf," where ");waswhere=1;}
		else strcat(buf," and ");
                strcat(buf," g.temyizeden like '");
                strcat(buf,quote(temyizeden));
                strcat(buf,"%'");
        }
        if(tutuklu[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," g.tutuklu like '");
                strcat(buf,quote(tutuklu));
                strcat(buf,"%'");
        }


	/* EXEC SQL PREPARE s1 FROM :buf; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )114;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)buf;
 sqlstm.sqhstl[0] = (unsigned int  )1000;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(SQL_ERROR || SQL_NOTFOUND){
		yfquestion(SQL_MESSAGE);
		goto sorsonkayit;
	}
	/* EXEC SQL declare cur cursor for s1; */ 

	/* EXEC SQL OPEN cur ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )133;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	while(1){
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL FETCH cur INTO
		:daireno:ind1, :esassirayil:ind2, :essno:ind3,
		:geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
		:tblno:ind7, :esno:ind8, :karno:ind9,
		:gonderenmahkeme:ind10, :sucunturu:ind11,
		:temyizeden:ind12, :tutuklu:ind13,
		:p_kararsonucu:ind14
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daireno;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind1;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)esassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )100;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&ind2;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&essno;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&ind3;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)geldigitarih;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&ind4;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)tebligtarih;
 sqlstm.sqhstl[4] = (unsigned int  )100;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)tebligmasa;
 sqlstm.sqhstl[5] = (unsigned int  )100;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&tblno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&esno;
 sqlstm.sqhstl[7] = (unsigned int  )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&karno;
 sqlstm.sqhstl[8] = (unsigned int  )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[9] = (unsigned int  )100;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)sucunturu;
 sqlstm.sqhstl[10] = (unsigned int  )100;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)temyizeden;
 sqlstm.sqhstl[11] = (unsigned int  )100;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)tutuklu;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind13;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)&p_kararsonucu;
 sqlstm.sqhstl[13] = (unsigned int  )4;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind14;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_NOTFOUND) goto sorsonkayit;
	if (SQL_ERROR) goto sorsonkayit;
	goto sornoerror;
sorsorerror:
	yfquestion(SQL_MESSAGE);
	goto yenidensor;
sorsonkayit:
	/* EXEC SQL CLOSE cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )219;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	yfquestion("Son kayýt. Devam için bir tuþa basýnýz");
	returnvalue = 1;
	break;
sornoerror:
	clearform(csornson);

	if(ind1 >= 0) strncpy(csornson->ifs[0].text,daireno,90);
	else csornson->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(csornson->ifs[1].text,esassirayil,90);
	else csornson->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(csornson->ifs[2].text,"%lu",essno);
	else csornson->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(csornson->ifs[3].text,geldigitarih,90);
	else csornson->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(csornson->ifs[4].text,tebligtarih,90);
	else csornson->ifs[4].text[0]=0;
	if(ind6 >= 0) strncpy(csornson->ifs[5].text,tebligmasa,90);
	else csornson->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(csornson->ifs[6].text,"%lu",tblno);
	else csornson->ifs[6].text[0]=0;
	if(ind8 >= 0) sprintf(csornson->ifs[7].text,"%lu",esno);
	else csornson->ifs[7].text[0]=0;
	if(ind9 >= 0) sprintf(csornson->ifs[8].text,"%lu",karno);
	else csornson->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(csornson->ifs[9].text,gonderenmahkeme,90);
	else csornson->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(csornson->ifs[10].text,sucunturu,90);
	else csornson->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(csornson->ifs[11].text,temyizeden,90);
	else csornson->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(csornson->ifs[12].text,tutuklu,90);
	else csornson->ifs[12].text[0]=0;
	/* simdi sonuc var mi bakalim... */
	/* EXEC SQL SELECT 
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi
	INTO 	
		:skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7

	FROM kararsonucu
	WHERE
		kararsonucu.id = :p_kararsonucu
	/o	
		kararsonucu.daireno = :daireno AND 
		kararsonucu.esassirayil = :esassirayil AND
		kararsonucu.esassirano = :essno	

	o/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select kararsonucu.karsonucu ,kararsonucu.karartarihi ,karar\
sonucu.kararnumarasi ,kararsonucu.gonderilistarihi into :b0:b1,:b2:b3,:b4:b5,:\
b6:b7  from kararsonucu where kararsonucu.id=:b8";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )234;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)skararsonucu;
 sqlstm.sqhstl[0] = (unsigned int  )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&sind4;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)skarartarihi;
 sqlstm.sqhstl[1] = (unsigned int  )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&sind5;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&sind6;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[3] = (unsigned int  )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&sind7;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)&p_kararsonucu;
 sqlstm.sqhstl[4] = (unsigned int  )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/***************************************************/

	csornson->ifs[13].text[0]=0;
	csornson->ifs[14].text[0]=0;
	csornson->ifs[15].text[0]=0;
	csornson->ifs[16].text[0]=0;

	if (p_kararsonucu == 0){
		strcpy(csornson->ifs[13].text,"Bu dosya sonuca baðlanmamýþtýr");
	}else{
	if(sind4 >= 0) strncpy(csornson->ifs[13].text,skararsonucu,90);
	else csornson->ifs[13].text[0]=0;
	if(sind5 >= 0) strncpy(csornson->ifs[14].text,skarartarihi,90);
	else csornson->ifs[14].text[0]=0;
	if(sind6 >= 0) sprintf(csornson->ifs[15].text,"%lu",skararnumarasi,90);
	else csornson->ifs[15].text[0]=0;
	if(sind7 >= 0) strncpy(csornson->ifs[16].text,sgonderilistarihi,90);
	else csornson->ifs[16].text[0]=0;
	}

	outputform(csornson);
	i = yfquestion("Sonraki kaydý görmek için herhangi bir tuþa basýnýz."
			" Çýkmak için x basýnýz");
	if(i == 'x' || i == 'X') break;
	}
	return returnvalue;

}
/**************************** Kayit Duzeltme ************************/
kayitduzelt()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


        long id;
        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13, ind14;

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;
	int startfield;

	showform(cgir);
kdyenikayit:
	cgir->ifs[0].edit = 1;
	cgir->ifs[1].edit = 1;
	cgir->ifs[2].edit = 1;
	cgir->ifs[3].edit = 1;
	cgir->ifs[4].edit = 1;
	cgir->ifs[5].edit = 1;
	cgir->ifs[6].edit = 1;
	cgir->ifs[7].edit = 1;
	cgir->ifs[8].edit = 1;
	cgir->ifs[9].edit = 1;
	cgir->ifs[10].edit = 1;
	cgir->ifs[11].edit = 1;
	cgir->ifs[12].edit = 1;
	clearform(cgir);

	strcpy(cgir->ifs[0].text, daire);
	cgir->ifs[0].edit = 0;
	cgir->ifs[1].edit = 1;
	cgir->ifs[2].edit = 1;
	cgir->ifs[3].edit = 0;
	cgir->ifs[4].edit = 0;
	cgir->ifs[5].edit = 0;
	cgir->ifs[6].edit = 0;
	cgir->ifs[7].edit = 0;
	cgir->ifs[8].edit = 0;
	cgir->ifs[9].edit = 0;
	cgir->ifs[10].edit = 0;
	cgir->ifs[11].edit = 0;
	cgir->ifs[12].edit = 0;


	outputform(cgir);
kdy:
	stat = inputform(cgir);
	if(stat == 0){
		return 1;
	}
	if(cgir->ifs[0].text[0]==0 ||
	   cgir->ifs[1].text[0]==0 ||
	   cgir->ifs[2].text[0]==0){
		yfmessage("2 alaný doldurunuz");
		goto kdy;
	}

	strcpy(daireno, cgir->ifs[0].text);
	dress(daireno,3);
	strcpy(esassirayil,     cgir->ifs[1].text);
	/*dress(esassirayil,4);*/
	esassirano = atol(cgir->ifs[2].text);


	yfmessage("Lütfen bekleyiniz...");
        /* EXEC SQL DECLARE gd_cur CURSOR FOR SELECT
                id, daireno, esassirayil, esassirano, geldigitarih,
                tebligtarih, tebligmasa, tebligno, esasno,
                kararno, gonderenmahkeme, sucunturu,
                temyizeden, tutuklu 
		FROM gelendosya
		WHERE
		daireno = :daireno and esassirayil = :esassirayil and
		esassirano = :esassirano
		FOR UPDATE
	; */ 

	/* EXEC SQL OPEN gd_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )269;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)esassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&esassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"kayit_duzelt.duzeltecek_dosya_arama",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto kdy;
	}
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir dosya bulunmadý");
		goto kdy;
	}
	/* EXEC SQL FETCH gd_cur INTO 
		:id:ind14,
                :daireno:ind1, :esassirayil:ind2, :essno:ind3,
                :geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
                :tblno:ind7, :esno:ind8, :karno:ind9,
                :gonderenmahkeme:ind10, :sucunturu:ind11,
                :temyizeden:ind12, :tutuklu:ind13; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )296;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&id;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind14;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)daireno;
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&ind1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)esassirayil;
 sqlstm.sqhstl[2] = (unsigned int  )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&ind2;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&essno;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&ind3;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)geldigitarih;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind4;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)tebligtarih;
 sqlstm.sqhstl[5] = (unsigned int  )11;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind5;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)tebligmasa;
 sqlstm.sqhstl[6] = (unsigned int  )3;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind6;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&tblno;
 sqlstm.sqhstl[7] = (unsigned int  )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind7;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&esno;
 sqlstm.sqhstl[8] = (unsigned int  )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind8;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&karno;
 sqlstm.sqhstl[9] = (unsigned int  )4;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind9;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[10] = (unsigned int  )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind10;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)sucunturu;
 sqlstm.sqhstl[11] = (unsigned int  )32;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind11;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)temyizeden;
 sqlstm.sqhstl[12] = (unsigned int  )51;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind12;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)tutuklu;
 sqlstm.sqhstl[13] = (unsigned int  )32;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind13;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"kayit_duzelt.duzeltecek_dosya_arama",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto kdy;
	}
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir dosya bulunmadý");
		goto kdy;
	}
	yfmessage(" ");
	/*-------------------------------------/
	cgir->ifs[0].edit = 0;
	cgir->ifs[1].edit = 1;
	cgir->ifs[2].edit = 0;
	cgir->ifs[3].edit = 1;
	cgir->ifs[4].edit = 1;
	cgir->ifs[5].edit = 1;
	cgir->ifs[6].edit = 1;
	cgir->ifs[7].edit = 1;
	cgir->ifs[8].edit = 1;
	cgir->ifs[9].edit = 1;
	cgir->ifs[10].edit = 1;
	cgir->ifs[11].edit = 1;
	cgir->ifs[12].edit = 1;

	if(ind1 >= 0) strncpy(cgir->ifs[0].text,daireno,90);
	else cgir->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(cgir->ifs[1].text,esassirayil,90);
	else cgir->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(cgir->ifs[2].text,"%lu",essno);
	else cgir->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(cgir->ifs[3].text,geldigitarih,90);
	else cgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(cgir->ifs[4].text,tebligtarih,90);
	else cgir->ifs[4].text[0]=0;
	if(ind6 >= 0) strncpy(cgir->ifs[5].text,tebligmasa,90);
	else cgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(cgir->ifs[6].text,"%lu",tblno);
	else cgir->ifs[6].text[0]=0;
	if(ind8 >= 0) sprintf(cgir->ifs[7].text,"%lu",esno);
	else cgir->ifs[7].text[0]=0;
	if(ind9 >= 0) sprintf(cgir->ifs[8].text,"%lu",karno);
	else cgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(cgir->ifs[9].text,gonderenmahkeme,90);
	else cgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(cgir->ifs[10].text,sucunturu,90);
	else cgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(cgir->ifs[11].text,temyizeden,90);
	else cgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(cgir->ifs[12].text,tutuklu,90);
	else cgir->ifs[12].text[0]=0;
	/*-------------------------------------*/
	
/***************************aaaaaaaaaaaaaaaaaaaaaaaaaaaaa*/
	cgir->ifs[0].edit = 0;
	cgir->ifs[1].edit = 0;
	cgir->ifs[2].edit = 0;
	cgir->ifs[3].edit = 1;
	cgir->ifs[4].edit = 1;
	cgir->ifs[5].edit = 1;
	cgir->ifs[6].edit = 1;
	cgir->ifs[7].edit = 1;
	cgir->ifs[8].edit = 1;
	cgir->ifs[9].edit = 1;
	cgir->ifs[10].edit = 1;
	cgir->ifs[11].edit = 1;
	cgir->ifs[12].edit = 1;
	if(ind1 >= 0) strncpy(cgir->ifs[0].text,daireno,90);
	else cgir->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(cgir->ifs[1].text,esassirayil,90);
	else cgir->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(cgir->ifs[2].text,"%lu",essno);
	else cgir->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(cgir->ifs[3].text,geldigitarih,90);
	else cgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(cgir->ifs[4].text,tebligtarih,90);
	else cgir->ifs[4].text[0]=0;
	if(ind6 >= 0) strncpy(cgir->ifs[5].text,tebligmasa,90);
	else cgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(cgir->ifs[6].text,"%lu",tblno);
	else cgir->ifs[6].text[0]=0;
	if(ind8 >= 0) sprintf(cgir->ifs[7].text,"%lu",esno);
	else cgir->ifs[7].text[0]=0;
	if(ind9 >= 0) sprintf(cgir->ifs[8].text,"%lu",karno);
	else cgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(cgir->ifs[9].text,gonderenmahkeme,90);
	else cgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(cgir->ifs[10].text,sucunturu,90);
	else cgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(cgir->ifs[11].text,temyizeden,90);
	else cgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(cgir->ifs[12].text,tutuklu,90);
	else cgir->ifs[12].text[0]=0;
/***************************aaaaaaaaaaaaaaaaaaaaaaaaaaaaa*/
	outputform(cgir);
	startfield = 0;
kdyenidendene:
	stat = superinputform(cgir, startfield);
	if (stat == 0){
		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )367;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return 1;
	}

	/* Insert new values */

/*********************************************************************/
	strcpy(daireno,	cgir->ifs[0].text);
	daireno[3]=0;
	dress(daireno,3);

	strcpy(esassirayil,	cgir->ifs[1].text);
	esassirayil[4]=0;

	esassirano = atol(cgir->ifs[2].text);

	strcpy(geldigitarih,cgir->ifs[3].text);
	geldigitarih[10]=0;

	strcpy(tebligtarih,	cgir->ifs[4].text);
	tebligtarih[10]=0;
	if(tebligtarih[0]==0){
		yfmessage("Teblið tarihi geçersiz");
		startfield = 4;
		goto kdyenidendene;
	}

	strcpy(tebligmasa,	cgir->ifs[5].text);
	tebligmasa[2]=0;
	if(tebligmasa[0]==0){
		yfmessage("Teblið masasý geçersiz");
		startfield = 5;
		goto kdyenidendene;
	}

	tebligno = atol(cgir->ifs[6].text);
	if(tebligno == 0){
		yfmessage("Teblið numarasý geçersiz");
		startfield = 6;
		goto kdyenidendene;
	}

	esasno = atol(cgir->ifs[7].text);
	if(esasno == 0){
		yfmessage("Esas numarasý geçersiz");
		startfield = 7;
		goto kdyenidendene;
	}

	kararno = atol(cgir->ifs[8].text);
	if(kararno == 0){
		yfmessage("Karar numarasý geçersiz");
		startfield = 8;
		goto kdyenidendene;
	}

	strcpy(gonderenmahkeme,cgir->ifs[9].text);
	gonderenmahkeme[31]=0;
	if(gonderenmahkeme[0]==0){
		yfmessage("Gönderen mahkeme geçersiz");
		startfield = 9;
		goto kdyenidendene;
	}

	strcpy(sucunturu,	cgir->ifs[10].text);
	sucunturu[31]=0;
	if(sucunturu[0]==0){
		yfmessage("Suçun türü geçersiz");
		startfield = 10;
		goto kdyenidendene;
	}

	strcpy(temyizeden,	cgir->ifs[11].text);
	temyizeden[50]=0;
	if(temyizeden[0]==0){
		yfmessage("Sanýk adý geçersiz");
		startfield = 11;
		goto kdyenidendene;
	}

	strcpy(tutuklu,	cgir->ifs[12].text);
	tutuklu[31]=0;
	/*if(tutuklu[0]==0){
		yfmessage("Turuklu bilgileri geçersiz");
		startfield = 12;
		goto kdyenidendene;
	}*/
	
/*********************************************************************/
	KAYIT_GIRILSIN_MI;	
        if (stat == 'e' || stat == 'E'){
	
	
	
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL UPDATE gelendosya SET
		geldigitarih 	= :geldigitarih, 
		tebligtarih 	= :tebligtarih, 
		tebligmasa 	= :tebligmasa,
		tebligno 	= :tebligno, 
		esasno 		= :esasno, 
		kararno 	= :kararno,
		gonderenmahkeme	= :gonderenmahkeme, 
		sucunturu	= :sucunturu, 
		temyizeden	= :temyizeden, 
		tutuklu		= :tutuklu
	WHERE 
		CURRENT OF gd_cur
	/o	daireno 	= :daireno AND
		esassirayil	= :esassirayil AND
		esassirano	= :esassiranoo/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update gelendosya  set geldigitarih=:b0,tebligtarih=:b1,tebl\
igmasa=:b2,tebligno=:b3,esasno=:b4,kararno=:b5,gonderenmahkeme=:b6,sucunturu=:\
b7,temyizeden=:b8,tutuklu=:b9 where rowid = :x";
 sqlstm.iters = (unsigned int  )6;
 sqlstm.offset = (unsigned int  )382;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)geldigitarih;
 sqlstm.sqhstl[0] = (unsigned int  )11;
 sqlstm.sqhsts[0] = (         int  )11;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)tebligtarih;
 sqlstm.sqhstl[1] = (unsigned int  )11;
 sqlstm.sqhsts[1] = (         int  )11;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)tebligmasa;
 sqlstm.sqhstl[2] = (unsigned int  )3;
 sqlstm.sqhsts[2] = (         int  )3;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&tebligno;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )4;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)&esasno;
 sqlstm.sqhstl[4] = (unsigned int  )4;
 sqlstm.sqhsts[4] = (         int  )4;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&kararno;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )4;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[6] = (unsigned int  )32;
 sqlstm.sqhsts[6] = (         int  )32;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)sucunturu;
 sqlstm.sqhstl[7] = (unsigned int  )32;
 sqlstm.sqhsts[7] = (         int  )32;
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)temyizeden;
 sqlstm.sqhstl[8] = (unsigned int  )51;
 sqlstm.sqhsts[8] = (         int  )51;
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)tutuklu;
 sqlstm.sqhstl[9] = (unsigned int  )32;
 sqlstm.sqhsts[9] = (         int  )32;
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		

	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"kayit_gir.SQL_update",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto kdyenidendene;
	}
		{
		char	x1[1024];
		char	x2[1024];
		char	x3[1024];
		char	x4[1024];
		char	x5[1024];
		/*char	x6[1024];
		char	x7[1024];
		char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(tebligmasa));
		strcpy(x2, quote(gonderenmahkeme));
		strcpy(x3, quote(sucunturu));
		strcpy(x4, quote(temyizeden));
		strcpy(x5, quote(tutuklu));
	ntchanges("UPDATE gelendosya SET\n"
		"\tgeldigitarih	= '%s', \n"
		"\ttebligtarih 	= '%s', \n"
		"\ttebligmasa 	= '%s',\n"
		"\ttebligno 	= %lu, \n"
		"\tesasno	= %lu, \n"
		"\tkararno 	= %lu, \n"
		"\tgonderenmahkeme	= '%s', \n"
		"\tsucunturu	= '%s', \n"
		"\ttemyizeden	= '%s', \n"
		"\ttutuklu	= '%s'\n"
		"WHERE\n"
		"\tdaireno 	= '%s' AND\n"
		"\tesassirayil	= '%s' AND\n"
		"\tesassirano	= %lu;\n",
		geldigitarih, 
		tebligtarih, 
		x1,
		tebligno, 
		esasno, 
		kararno,
		x2, 
		x3, 
		x4, 
		x5,	
			/*WHERE */
		daireno,
		esassirayil,
		esassirano
	);
	}
		/*geldigitarih, 
		tebligtarih, 
		tebligmasa,
		tebligno, 
		esasno, 
		kararno,
		gonderenmahkeme, 
		sucunturu, 
		temyizeden, 
		tutuklu,	
			WHERE 
		daireno,
		esassirayil,
		esassirano
	);*/
	nthareket("ceza: dosya duzelt");
	

	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL CLOSE gd_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )437;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL COMMIT WORK ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )452;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else {
		/* EXEC SQL CLOSE gd_cur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )467;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )482;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		yfmessage("Kayýt iptal edildi");
	}
	goto kdyenikayit;
}
/**************************** Sonuc Girme ************************/
sonucgir()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/*------------- Kararsonucu ------------*/
	long sid;
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skararsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7,sind8;
	/*------------- Gelendosya ------------*/
	long id;
        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	long mid;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13, ind14;

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;
	int startfield;

	showform(sgir);
	/* butun alanlari sil. sadece fonksyona ilk girdiginde
	   yapilacak
	*/
	sgir->ifs[0].edit = 1;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
sgyenikayit:
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
	strcpy(sgir->ifs[0].text, daire);
	sgir->ifs[0].edit = 0;
	

	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
	sgir->ifs[5].edit = 0;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;


	outputform(sgir);
	startfield = 0;
sgyineden:
	stat = superinputform(sgir, startfield);
	if (stat == 0)return 1;
	/*---------------------*/
	strcpy(sdaireno, sgir->ifs[0].text);
	dress(sdaireno,3);
	/*sdaireno[3]=0;*/
	dress(sdaireno,3);

	strcpy(sesassirayil, sgir->ifs[1].text);
	sesassirayil[4]=0;
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		startfield = 1;
		goto sgyineden;
	}

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		startfield = 2;
		goto sgyineden;
	}
	/* EXEC SQL SELECT id
	INTO :sid
	FROM kararsonucu
	WHERE
		daireno = :sdaireno AND esassirayil = :sesassirayil AND
		esassirano = :sesassirano; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select id into :b0  from kararsonucu where ((daireno=:b1 and\
 esassirayil=:b2) and esassirano=:b3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )497;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&sid;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sdaireno;
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)sesassirayil;
 sqlstm.sqhstl[2] = (unsigned int  )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&sesassirano;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (!(SQL_NOTFOUND)){
		yfmessage("Bu sonuç zaten girilmiþ");
		goto sgyineden;
	}
	/*------------- Get data from gelendosya --------------*/
	yfmessage("Lütfen bekleyiniz...");
        /* EXEC SQL DECLARE sg_gd_cur CURSOR FOR SELECT
                daireno, esassirayil, esassirano, geldigitarih,
                tebligtarih, tebligmasa, tebligno, esasno,
                kararno, gonderenmahkeme, sucunturu,
                temyizeden, tutuklu 
		FROM gelendosya
		WHERE
		daireno = :sdaireno and esassirayil = :sesassirayil and
		esassirano = :sesassirano
		FOR UPDATE
	; */ 

	/* EXEC SQL OPEN sg_gd_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )528;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)sdaireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sesassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL FETCH sg_gd_cur
		INTO
                :daireno:ind1, :esassirayil:ind2, :essno:ind3,
                :geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
                :tblno:ind7, :esno:ind8, :karno:ind9,
                :gonderenmahkeme:ind10, :sucunturu:ind11,
                :temyizeden:ind12, :tutuklu:ind13
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )555;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind1;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)esassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&ind2;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&essno;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&ind3;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)geldigitarih;
 sqlstm.sqhstl[3] = (unsigned int  )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&ind4;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)tebligtarih;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)tebligmasa;
 sqlstm.sqhstl[5] = (unsigned int  )3;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&tblno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&esno;
 sqlstm.sqhstl[7] = (unsigned int  )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&karno;
 sqlstm.sqhstl[8] = (unsigned int  )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[9] = (unsigned int  )32;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)sucunturu;
 sqlstm.sqhstl[10] = (unsigned int  )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)temyizeden;
 sqlstm.sqhstl[11] = (unsigned int  )51;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)tutuklu;
 sqlstm.sqhstl[12] = (unsigned int  )32;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind13;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	yfmessage(" ");
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir dosya bulunmadý");
		goto sgyineden;
	}
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 0;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;

	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[7].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tebligtarih,90);
	else sgir->ifs[8].text[0]=0;
	if(ind6 >= 0) strncpy(sgir->ifs[9].text,tebligmasa,90);
	else sgir->ifs[9].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",tblno);
	else sgir->ifs[10].text[0]=0;
	if(ind8 >= 0) sprintf(sgir->ifs[11].text,"%lu",esno);
	else sgir->ifs[11].text[0]=0;
	if(ind9 >= 0) sprintf(sgir->ifs[12].text,"%lu",karno);
	else sgir->ifs[12].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,gonderenmahkeme,90);
	else sgir->ifs[13].text[12]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,sucunturu,90);
	else sgir->ifs[14].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,temyizeden,90);
	else sgir->ifs[15].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,tutuklu,90);
	else sgir->ifs[16].text[0]=0;
	/*-------------------------------------*/
	outputform(sgir);
	startfield = 0;
sgyine2:
	stat = superinputform(sgir, startfield);
	if(stat == 0){
		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )622;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return 0;
	}
	/*-----------------------------------------------------*/
	/* Insert new values */
	strcpy(sdaireno,	sgir->ifs[0].text);
	sdaireno[3]=0;

	strcpy(sesassirayil,	sgir->ifs[1].text);
	sesassirayil[4]=0;

	sesassirano = atol(sgir->ifs[2].text);

        strcpy(skararsonucu,    sgir->ifs[3].text);
        skararsonucu[30]=0;
	if(skararsonucu[0]==0){
		yfmessage("Geçersiz karar");
		startfield = 3;
		goto sgyine2;
	}

	strcpy(skarartarihi,sgir->ifs[4].text);
	skarartarihi[10]=0;
	if(skarartarihi[0]==0){
		yfmessage("Geçersiz karar tarihi");
		startfield = 4;
		goto sgyine2;
	}

	skararnumarasi = atol(sgir->ifs[5].text);
	if(skararnumarasi == 0){
		yfmessage("Geçersiz karar numarasý");
		startfield = 5;
		goto sgyine2;
	}

	strcpy(sgonderilistarihi,	sgir->ifs[6].text);
	sgonderilistarihi[10]=0;
	if(sgonderilistarihi[0] == 0){
		yfmessage("Geçersiz gönderiliþ tarihi");
		startfield = 6;
		goto sgyine2;
	}

	
	KAYIT_GIRILSIN_MI;	
        if (stat == 'e' || stat == 'E'){
	/* EXEC SQL INSERT INTO kararsonucu 
		(
		DAIRENO, ESASSIRAYIL, ESASSIRANO,
		KARSONUCU, KARARTARIHI, KARARNUMARASI,
		GONDERILISTARIHI
		)
		VALUES(
		:sdaireno, :sesassirayil, :sesassirano,
		:skararsonucu,
		:skarartarihi, :skararnumarasi,
		:sgonderilistarihi); */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into kararsonucu(DAIRENO,ESASSIRAYIL,ESASSIRANO,KARSO\
NUCU,KARARTARIHI,KARARNUMARASI,GONDERILISTARIHI) values (:b0,:b1,:b2,:b3,:b4,:\
b5,:b6)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )637;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)sdaireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sesassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)skararsonucu;
 sqlstm.sqhstl[3] = (unsigned int  )31;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)skarartarihi;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[6] = (unsigned int  )11;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"sonuc_gir.SQL_INSERT",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
	if (SQL_NOTFOUND){
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
		{
		char	x1[1024];
		char	x2[1024];
		char	x3[1024];
		/*char	x4[1024];
		char	x5[1024];
		char	x6[1024];
		char	x7[1024];
		char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(sdaireno));
		strcpy(x2, quote(sesassirayil));
		strcpy(x3, quote(skararsonucu));
	ntchanges("INSERT INTO kararsonucu VALUES(\n"
		"\t'%s',\t'%s',\t%lu,\n"
		"\t'%s',\n"
		"\t'%s',\t%lu,\n"
		"\t'%s');\n",
		x1, x2, sesassirano,
		x3,
		skarartarihi, skararnumarasi,
		sgonderilistarihi
	);
	}
		/*sdaireno, sesassirayil, sesassirano,
		skararsonucu,
		skarartarihi, skararnumarasi,
		sgonderilistarihi
	);*/
/**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************/
	dress(sdaireno,3);
/*
	EXEC SQL SELECT id INTO :mid FROM kararsonucu WHERE
		daireno = :sdaireno AND
		esassirayil = :sesassirayil AND
		esassirano = :sesassirano
	;
	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"sonuc_gir.SQL_SELECT_FOR_FK",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir sonuc bulunmadý");
		goto sgyineden;
	}
*/


	/* EXEC SQL UPDATE gelendosya SET kararsonucu=(SELECT id FROM kararsonucu WHERE
			 	daireno = :sdaireno AND
                		esassirayil = :sesassirayil AND
                		esassirano = :sesassirano
			)
		WHERE
		CURRENT OF sg_gd_cur
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update gelendosya  set kararsonucu=(select id  from kararson\
ucu where ((daireno=:b0 and esassirayil=:b1) and esassirano=:b2)) where rowid \
= :x";
 sqlstm.iters = (unsigned int  )12;
 sqlstm.offset = (unsigned int  )680;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)sdaireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )4;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sesassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )5;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )4;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"sonuc_gir.SQL_INSERT_FOR_FK",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir dosya bulunmadý");
		goto sgyineden;
	}

/**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************/
	nthareket("ceza: sonuc gir");
	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL CLOSE sg_gd_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )707;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL COMMIT WORK ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )722;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else {
		/* EXEC SQL CLOSE sg_gd_cur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )737;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )752;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		yfmessage("Kayýt iptal edildi");
	}
	goto sgyenikayit;
}
/**************************** Sonuc Sorgulama ************************/
sonucsor()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/*------------- Kararsonucu ------------*/
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skararsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7;
	/*------------- Gelendosya ------------*/
        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;

	showform(sgir);
	/* butun alanlari sil. sadece fonksyona ilk girdiginde
	   yapilacak
	*/
	sgir->ifs[0].edit = 1;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
ssyenisor:
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
	strcpy(sgir->ifs[0].text, daire);
	sgir->ifs[0].edit = 0;
	

	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
	sgir->ifs[5].edit = 0;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;


	outputform(sgir);
ssyineden:
	stat = inputform(sgir);
	if (stat == 0)return 1;
	/*---------------------*/
	strcpy(sdaireno, sgir->ifs[0].text);
	dress(sdaireno,3);
	sdaireno[3]=0;

	strcpy(sesassirayil, sgir->ifs[1].text);
	sesassirayil[4]=0;
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto ssyineden;
	}

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		goto ssyineden;
	}
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL SELECT 
		kararsonucu.daireno, 
		kararsonucu.esassirayil, 
		kararsonucu.esassirano,
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi,

                gelendosya.geldigitarih,
                gelendosya.tebligtarih, 
		gelendosya.tebligmasa, 
		gelendosya.tebligno, 
		gelendosya.esasno,
                gelendosya.kararno, 
		gelendosya.gonderenmahkeme, 
		gelendosya.sucunturu,
                gelendosya.temyizeden, 
		gelendosya.tutuklu 
	INTO 	
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

                :geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
                :tblno:ind7, :esno:ind8, :karno:ind9,
                :gonderenmahkeme:ind10, :sucunturu:ind11,
                :temyizeden:ind12, :tutuklu:ind13
	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		kararsonucu.id = gelendosya.kararsonucu

	/o	kararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassiranoo/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select kararsonucu.daireno ,kararsonucu.esassirayil ,kararso\
nucu.esassirano ,kararsonucu.karsonucu ,kararsonucu.karartarihi ,kararsonucu.k\
ararnumarasi ,kararsonucu.gonderilistarihi ,gelendosya.geldigitarih ,gelendosy\
a.tebligtarih ,gelendosya.tebligmasa ,gelendosya.tebligno ,gelendosya.esasno ,\
gelendosya.kararno ,gelendosya.gonderenmahkeme ,gelendosya.sucunturu ,gelendos\
ya.temyizeden ,gelendosya.tutuklu into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9,:b10\
:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:b26:b27,:\
b28:b29,:b30:b31,:b32:b33  from kararsonucu ,gelendosya where (((kararsonucu.d\
aireno=:b0 and kararsonucu.esassirayil=:b2) and kararsonucu.esassirano=:b4) an\
d kararsonucu.id=gelendosya.kararsonucu)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )767;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)sdaireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&sind1;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sesassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&sind2;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&sind3;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)skararsonucu;
 sqlstm.sqhstl[3] = (unsigned int  )31;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&sind4;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)skarartarihi;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&sind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&sind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[6] = (unsigned int  )11;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&sind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)geldigitarih;
 sqlstm.sqhstl[7] = (unsigned int  )11;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind4;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)tebligtarih;
 sqlstm.sqhstl[8] = (unsigned int  )11;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind5;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)tebligmasa;
 sqlstm.sqhstl[9] = (unsigned int  )3;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind6;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&tblno;
 sqlstm.sqhstl[10] = (unsigned int  )4;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind7;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&esno;
 sqlstm.sqhstl[11] = (unsigned int  )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind8;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)&karno;
 sqlstm.sqhstl[12] = (unsigned int  )4;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind9;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[13] = (unsigned int  )32;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind10;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)sucunturu;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind11;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)temyizeden;
 sqlstm.sqhstl[15] = (unsigned int  )51;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind12;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)tutuklu;
 sqlstm.sqhstl[16] = (unsigned int  )32;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         void  *)&ind13;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)sdaireno;
 sqlstm.sqhstl[17] = (unsigned int  )4;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)sesassirayil;
 sqlstm.sqhstl[18] = (unsigned int  )5;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&sesassirano;
 sqlstm.sqhstl[19] = (unsigned int  )4;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_NOTFOUND){
		yfmessage("Bu sonuç yok");
		goto ssyineden;
	}
	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"sonuc_sor.SQL_SELECT_kararsonucu",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto ssyineden;
	}
	/*------------- Get data from gelendosya --------------*/
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 0;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
	sgir->ifs[5].edit = 0;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;

	if(sind1 >= 0) strncpy(sgir->ifs[0].text,sdaireno,90);
	else sgir->ifs[0].text[0]=0;
	if(sind2 >= 0) strncpy(sgir->ifs[1].text,sesassirayil,90);
	else sgir->ifs[1].text[0]=0;
	if(sind3 >= 0) sprintf(sgir->ifs[2].text,"%lu",sesassirano,90);
	else sgir->ifs[2].text[0]=0;
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skararsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;
	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[7].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tebligtarih,90);
	else sgir->ifs[8].text[0]=0;
	if(ind6 >= 0) strncpy(sgir->ifs[9].text,tebligmasa,90);
	else sgir->ifs[9].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",tblno);
	else sgir->ifs[10].text[0]=0;
	if(ind8 >= 0) sprintf(sgir->ifs[11].text,"%lu",esno);
	else sgir->ifs[11].text[0]=0;
	if(ind9 >= 0) sprintf(sgir->ifs[12].text,"%lu",karno);
	else sgir->ifs[12].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,gonderenmahkeme,90);
	else sgir->ifs[13].text[12]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,sucunturu,90);
	else sgir->ifs[14].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,temyizeden,90);
	else sgir->ifs[15].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,tutuklu,90);
	else sgir->ifs[16].text[0]=0;
	/*-------------------------------------*/
	nthareket("ceza: sonuc sor");
	outputform(sgir);
	yfquestion("Devam etmek için RETURN");
	yfmessage(" ");
	goto ssyenisor;
}
/**************************** Sonuc Duzeltme ************************/
sonucduzelt()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/*------------- Kararsonucu ------------*/
	long sid;
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skararsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7,sind8;
	/*------------- Gelendosya ------------*/
        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

	char buf[100];
/* EXEC SQL END DECLARE SECTION; */ 



	int stat;
	int startfield;

	showform(sgir);
	/* butun alanlari sil. sadece fonksyona ilk girdiginde
	   yapilacak
	*/
	sgir->ifs[0].edit = 1;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
sdyenisor:
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
	strcpy(sgir->ifs[0].text, daire);
	sgir->ifs[0].edit = 0;
	

	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
	sgir->ifs[5].edit = 0;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;


	outputform(sgir);
sdyineden:
	stat = inputform(sgir);
	if (stat == 0)return 1;
	/*---------------------*/
	strcpy(sdaireno, sgir->ifs[0].text);
	sdaireno[3]=0;

	strcpy(sesassirayil, sgir->ifs[1].text);
	sesassirayil[4]=0;
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto sdyineden;
	}

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		goto sdyineden;
	}
	dress(sdaireno,3);
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL DECLARE sd_ks_cur CURSOR FOR SELECT 
		kararsonucu.id,
		kararsonucu.daireno, 
		kararsonucu.esassirayil, 
		kararsonucu.esassirano,
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi,

                gelendosya.geldigitarih,
                gelendosya.tebligtarih, 
		gelendosya.tebligmasa, 
		gelendosya.tebligno, 
		gelendosya.esasno,
                gelendosya.kararno, 
		gelendosya.gonderenmahkeme, 
		gelendosya.sucunturu,
                gelendosya.temyizeden, 
		gelendosya.tutuklu 
	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		kararsonucu.id = gelendosya.kararsonucu
		/o
		kararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassirano
		o/
		FOR UPDATE
	; */ 

	/* EXEC SQL OPEN sd_ks_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )862;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)sdaireno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sesassirayil;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQL_NOTFOUND){
		yfmessage("Bu sonuç yok");
		goto sdyineden;
	}
	if (SQL_ERROR){
		yfmessage("Bu sonuç yok");
		goto sdyineden;
	}
	/* EXEC SQL FETCH sd_ks_cur
	INTO 	
		:sid:sind8,
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

                :geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
                :tblno:ind7, :esno:ind8, :karno:ind9,
                :gonderenmahkeme:ind10, :sucunturu:ind11,
                :temyizeden:ind12, :tutuklu:ind13
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )889;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&sid;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&sind8;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sdaireno;
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&sind1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)sesassirayil;
 sqlstm.sqhstl[2] = (unsigned int  )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&sind2;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&sesassirano;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&sind3;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)skararsonucu;
 sqlstm.sqhstl[4] = (unsigned int  )31;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&sind4;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)skarartarihi;
 sqlstm.sqhstl[5] = (unsigned int  )11;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&sind5;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&sind6;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[7] = (unsigned int  )11;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&sind7;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)geldigitarih;
 sqlstm.sqhstl[8] = (unsigned int  )11;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind4;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)tebligtarih;
 sqlstm.sqhstl[9] = (unsigned int  )11;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind5;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)tebligmasa;
 sqlstm.sqhstl[10] = (unsigned int  )3;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind6;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&tblno;
 sqlstm.sqhstl[11] = (unsigned int  )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind7;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)&esno;
 sqlstm.sqhstl[12] = (unsigned int  )4;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind8;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)&karno;
 sqlstm.sqhstl[13] = (unsigned int  )4;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind9;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind10;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)sucunturu;
 sqlstm.sqhstl[15] = (unsigned int  )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind11;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)temyizeden;
 sqlstm.sqhstl[16] = (unsigned int  )51;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         void  *)&ind12;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)tutuklu;
 sqlstm.sqhstl[17] = (unsigned int  )32;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         void  *)&ind13;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_NOTFOUND){
		yfmessage("Bu sonuç yok");
		goto sdyineden;
	}
	if (SQL_ERROR){
		yfmessage("Bu sonuç yok");
		goto sdyineden;
	}
	yfmessage(" ");
	/*------------- Get data from gelendosya --------------*/
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 0;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;

	if(sind1 >= 0) strncpy(sgir->ifs[0].text,sdaireno,90);
	else sgir->ifs[0].text[0]=0;
	if(sind2 >= 0) strncpy(sgir->ifs[1].text,sesassirayil,90);
	else sgir->ifs[1].text[0]=0;
	if(sind3 >= 0) sprintf(sgir->ifs[2].text,"%lu",sesassirano,90);
	else sgir->ifs[2].text[0]=0;
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skararsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;
	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[7].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tebligtarih,90);
	else sgir->ifs[8].text[0]=0;
	if(ind6 >= 0) strncpy(sgir->ifs[9].text,tebligmasa,90);
	else sgir->ifs[9].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",tblno);
	else sgir->ifs[10].text[0]=0;
	if(ind8 >= 0) sprintf(sgir->ifs[11].text,"%lu",esno);
	else sgir->ifs[11].text[0]=0;
	if(ind9 >= 0) sprintf(sgir->ifs[12].text,"%lu",karno);
	else sgir->ifs[12].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,gonderenmahkeme,90);
	else sgir->ifs[13].text[12]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,sucunturu,90);
	else sgir->ifs[14].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,temyizeden,90);
	else sgir->ifs[15].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,tutuklu,90);
	else sgir->ifs[16].text[0]=0;
	/*-------------------------------------*/
	outputform(sgir);

	startfield=0;
sdyine2:
	stat = superinputform(sgir, startfield);
	if(stat == 0){
		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )976;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return 0;
	}
	/*-----------------------------------------------------*/
	/* Insert new values */
	/*strcpy(sdaireno,	sgir->ifs[0].text);
	sdaireno[3]=0;

	strcpy(sesassirayil,	sgir->ifs[1].text);
	sesassirayil[4]=0;

	sesassirano = atol(sgir->ifs[2].text);*/

        strcpy(skararsonucu,    sgir->ifs[3].text);
        skararsonucu[30]=0;
	if(skararsonucu[0] == 0){
		yfmessage("Karar sonucu geçersiz");
		startfield = 3;
		goto sdyine2;
	}

	strcpy(skarartarihi,sgir->ifs[4].text);
	skarartarihi[10]=0;
	if(skarartarihi[0] == 0){
		yfmessage("Karar tarihi geçersiz");
		startfield = 4;
		goto sdyine2;
	}

	skararnumarasi = atol(sgir->ifs[5].text);
	if(skararnumarasi == 0){
		yfmessage("Karar numarasý geçersiz");
		startfield = 5;
		goto sdyine2;
	}

	strcpy(sgonderilistarihi,	sgir->ifs[6].text);
	sgonderilistarihi[10]=0;
	if(sgonderilistarihi[0] == 0){
		yfmessage("Gönderiliþ tarihi geçersiz");
		startfield = 6;
		goto sdyine2;
	}

	
	KAYIT_GIRILSIN_MI;
        if (stat == 'e' || stat == 'E'){
	sprintf(buf,"%d",sesassirano);
	strcpy(buf,sdaireno);
	dress(buf,3);
	/* EXEC SQL UPDATE kararsonucu SET
		karsonucu = :skararsonucu,
		karartarihi = :skarartarihi,
		kararnumarasi =  :skararnumarasi,
		gonderilistarihi = :sgonderilistarihi
	WHERE 
		id = :sid
		/oCURRENT OF sd_ks_curo/
		/odaireno 	= :sdaireno AND
		esassirayil	= :sesassirayil AND
		esassirano	= :sesassirano
		o/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update kararsonucu  set karsonucu=:b0,karartarihi=:b1,kararn\
umarasi=:b2,gonderilistarihi=:b3 where id=:b4";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )991;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)skararsonucu;
 sqlstm.sqhstl[0] = (unsigned int  )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)skarartarihi;
 sqlstm.sqhstl[1] = (unsigned int  )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[3] = (unsigned int  )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)&sid;
 sqlstm.sqhstl[4] = (unsigned int  )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"sonuc_duzelt.SQL_UPDATE",SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sdyine2;
	}
	sprintf(buf,"ceza: sonuc duzelt (%d)",sqlca.sqlcode);
	nthareket(buf);
		{
		char	x1[1024];
		/*char	x2[1024];
		char	x3[1024];
		char	x4[1024];
		char	x5[1024];
		char	x6[1024];
		char	x7[1024];
		char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(skararsonucu));
	ntchanges("UPDATE kararsonucu SET\n"
		"\tkarsonucu	= '%s', \n"
		"\tkarartarihi 	= '%s', \n"
		"\tkararnumarasi= %lu, \n"
		"\tgonderilistarihi= '%s'\n"
		"WHERE\n"
		"\tdaireno 	= '%s' AND\n"
		"\tesassirayil	= '%s' AND\n"
		"\tesassirano	= %lu;\n",
		x1, 
		/*skararsonucu, */
		skarartarihi, 
		skararnumarasi,
		sgonderilistarihi, 
			/*WHERE */
		sdaireno,
		sesassirayil,
		sesassirano
	);
	}
	nthareket("ceza: sonuc duzelt");
	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL CLOSE sd_ks_cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1026;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL COMMIT WORK ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1041;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else {
		/* EXEC SQL CLOSE sd_ks_cur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1056;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1071;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		yfmessage("Kayýt iptal edildi");
	}
	goto sdyenisor;
}
/**************************** Sonuc Silme ************************/
sonucsil()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/*------------- Kararsonucu ------------*/
	long sid;
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skararsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7,sind8;
	/*------------- Gelendosya ------------*/
        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tebligtarih[11];
	char tebligmasa[3];
	long tebligno;
        long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char sucunturu[32];
	char temyizeden[51];
	char tutuklu[32];

	long essno;
	long tblno;
	long esno;
	long karno;

	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;

	showform(sgir);
	/* butun alanlari sil. sadece fonksyona ilk girdiginde
	   yapilacak
	*/
	sgir->ifs[0].edit = 1;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	clearform(sgir);
ssilyenisor:
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 1;
	sgir->ifs[8].edit = 1;
	sgir->ifs[9].edit = 1;
	sgir->ifs[10].edit = 1;
	sgir->ifs[11].edit = 1;
	sgir->ifs[12].edit = 1;
	sgir->ifs[13].edit = 1;
	sgir->ifs[14].edit = 1;
	sgir->ifs[15].edit = 1;
	sgir->ifs[16].edit = 1;
	strcpy(sgir->ifs[0].text, daire);
	sgir->ifs[0].edit = 0;
	clearform(sgir);
	

	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 1;
	sgir->ifs[2].edit = 1;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
	sgir->ifs[5].edit = 0;
	sgir->ifs[6].edit = 0;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;


	outputform(sgir);
ssilyineden:
	stat = inputform(sgir);
	if (stat == 0)return 1;
	/*---------------------*/
	strcpy(sdaireno, sgir->ifs[0].text);
	dress(sdaireno,3);
	sdaireno[3]=0;

	strcpy(sesassirayil, sgir->ifs[1].text);
	sesassirayil[4]=0;
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto ssilyineden;
	}

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		goto ssilyineden;
	}
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL SELECT 
		kararsonucu.id,
		kararsonucu.daireno, 
		kararsonucu.esassirayil, 
		kararsonucu.esassirano,
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi,

                gelendosya.geldigitarih,
                gelendosya.tebligtarih, 
		gelendosya.tebligmasa, 
		gelendosya.tebligno, 
		gelendosya.esasno,
                gelendosya.kararno, 
		gelendosya.gonderenmahkeme, 
		gelendosya.sucunturu,
                gelendosya.temyizeden, 
		gelendosya.tutuklu 
	INTO 	
		:sid:sind8,
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

                :geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
                :tblno:ind7, :esno:ind8, :karno:ind9,
                :gonderenmahkeme:ind10, :sucunturu:ind11,
                :temyizeden:ind12, :tutuklu:ind13
	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		gelendosya.kararsonucu = kararsonucu.id
		/okararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassiranoo/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select kararsonucu.id ,kararsonucu.daireno ,kararsonucu.esas\
sirayil ,kararsonucu.esassirano ,kararsonucu.karsonucu ,kararsonucu.karartarih\
i ,kararsonucu.kararnumarasi ,kararsonucu.gonderilistarihi ,gelendosya.geldigi\
tarih ,gelendosya.tebligtarih ,gelendosya.tebligmasa ,gelendosya.tebligno ,gel\
endosya.esasno ,gelendosya.kararno ,gelendosya.gonderenmahkeme ,gelendosya.suc\
unturu ,gelendosya.temyizeden ,gelendosya.tutuklu into :b0:b1,:b2:b3,:b4:b5,:b\
6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b2\
4:b25,:b26:b27,:b28:b29,:b30:b31,:b32:b33,:b34:b35  from kararsonucu ,gelendos\
ya where (((kararsonucu.daireno=:b2 and kararsonucu.esassirayil=:b4) and karar\
sonucu.esassirano=:b6) and gelendosya.kararsonucu=kararsonucu.id)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1086;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&sid;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&sind8;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sdaireno;
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&sind1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)sesassirayil;
 sqlstm.sqhstl[2] = (unsigned int  )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&sind2;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&sesassirano;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&sind3;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)skararsonucu;
 sqlstm.sqhstl[4] = (unsigned int  )31;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&sind4;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)skarartarihi;
 sqlstm.sqhstl[5] = (unsigned int  )11;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&sind5;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&skararnumarasi;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&sind6;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[7] = (unsigned int  )11;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&sind7;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)geldigitarih;
 sqlstm.sqhstl[8] = (unsigned int  )11;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind4;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)tebligtarih;
 sqlstm.sqhstl[9] = (unsigned int  )11;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind5;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)tebligmasa;
 sqlstm.sqhstl[10] = (unsigned int  )3;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind6;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&tblno;
 sqlstm.sqhstl[11] = (unsigned int  )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind7;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)&esno;
 sqlstm.sqhstl[12] = (unsigned int  )4;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind8;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)&karno;
 sqlstm.sqhstl[13] = (unsigned int  )4;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind9;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind10;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)sucunturu;
 sqlstm.sqhstl[15] = (unsigned int  )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind11;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)temyizeden;
 sqlstm.sqhstl[16] = (unsigned int  )51;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         void  *)&ind12;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)tutuklu;
 sqlstm.sqhstl[17] = (unsigned int  )32;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         void  *)&ind13;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)sdaireno;
 sqlstm.sqhstl[18] = (unsigned int  )4;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)sesassirayil;
 sqlstm.sqhstl[19] = (unsigned int  )5;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)&sesassirano;
 sqlstm.sqhstl[20] = (unsigned int  )4;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (SQL_NOTFOUND){
		yfmessage("Bu sonuç yok");
		goto ssilyineden;
	}
	/*------------- Get data from gelendosya --------------*/
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 0;
	sgir->ifs[3].edit = 1;
	sgir->ifs[4].edit = 1;
	sgir->ifs[5].edit = 1;
	sgir->ifs[6].edit = 1;
	sgir->ifs[7].edit = 0;
	sgir->ifs[8].edit = 0;
	sgir->ifs[9].edit = 0;
	sgir->ifs[10].edit = 0;
	sgir->ifs[11].edit = 0;
	sgir->ifs[12].edit = 0;
	sgir->ifs[13].edit = 0;
	sgir->ifs[14].edit = 0;
	sgir->ifs[15].edit = 0;
	sgir->ifs[16].edit = 0;

	if(sind1 >= 0) strncpy(sgir->ifs[0].text,sdaireno,90);
	else sgir->ifs[0].text[0]=0;
	if(sind2 >= 0) strncpy(sgir->ifs[1].text,sesassirayil,90);
	else sgir->ifs[1].text[0]=0;
	if(sind3 >= 0) sprintf(sgir->ifs[2].text,"%lu",sesassirano,90);
	else sgir->ifs[2].text[0]=0;
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skararsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;
	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[7].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tebligtarih,90);
	else sgir->ifs[8].text[0]=0;
	if(ind6 >= 0) strncpy(sgir->ifs[9].text,tebligmasa,90);
	else sgir->ifs[9].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",tblno);
	else sgir->ifs[10].text[0]=0;
	if(ind8 >= 0) sprintf(sgir->ifs[11].text,"%lu",esno);
	else sgir->ifs[11].text[0]=0;
	if(ind9 >= 0) sprintf(sgir->ifs[12].text,"%lu",karno);
	else sgir->ifs[12].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,gonderenmahkeme,90);
	else sgir->ifs[13].text[12]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,sucunturu,90);
	else sgir->ifs[14].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,temyizeden,90);
	else sgir->ifs[15].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,tutuklu,90);
	else sgir->ifs[16].text[0]=0;
	/*-------------------------------------*/
	outputform(sgir);
ssilyine2:
	stat = yfquestion("Bu kayýt silinsin mi? (e/h)");
	if (stat == 'e' || stat == 'E'){
	
		/* EXEC SQL UPDATE gelendosya SET kararsonucu = 0 
		WHERE 
			kararsonucu = :sid
			/odaireno 	= :sdaireno AND
			esassirayil	= :sesassirayil AND
			esassirano	= :sesassiranoo/
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update gelendosya  set kararsonucu=0 where kararsonucu=:b0";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1185;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&sid;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (SQL_ERROR){
			ntlog2(LOG_CEZA,"sonuc_sil.SQL_DELETE",SQL_MESSAGE);
			yfmessage(SQL_MESSAGE);
			goto ssilyine2;
		}
		/* EXEC SQL DELETE FROM kararsonucu 
		WHERE 
			id = :sid
		/o	daireno 	= :sdaireno AND
			esassirayil	= :sesassirayil AND
			esassirano	= :sesassiranoo/
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete  from kararsonucu  where id=:b0";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1204;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&sid;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		if (SQL_ERROR){
			ntlog2(LOG_CEZA,"sonuc_sil.SQL_DELETE",SQL_MESSAGE);
			yfquestion(SQL_MESSAGE);
			goto ssilyine2;
		}
		ntchanges("DELETE FROM kararsonucu\n"
			"\tWHERE\n"
			"\tdaireno\t=\t'%s' AND\n"
			"\tesassirayil\t=\t'%s' AND\n"
			"\tesassirano\t=\t%lu;\n",
			sdaireno,
			sesassirayil,
			sesassirano
		);
		nthareket("ceza: sonuc sil");
		/* EXEC SQL COMMIT WORK ; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1223;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		yfmessage("Kayýt silindi");
	}else yfmessage("Silme iptal edildi");
	/* EXEC SQL ROLLBACK; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1238;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	goto ssilyenisor;
}
