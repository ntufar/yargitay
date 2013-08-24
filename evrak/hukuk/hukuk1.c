
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
           char  filnam[10];
};
static struct sqlcxp sqlfpn =
{
    9,
    "hukuk1.pc"
};


static unsigned long sqlctx = 38835;


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
"select daireno ,esassirayil ,esassirano ,geldigitarih ,tarihi ,esasno ,karar\
no ,gonderenmahkeme ,temyizeden ,aleyhinetemyiz ,davaninturu ,dusunceler ,gond\
erendaire  from gelendosya where ((daireno=:b0 and esassirayil=:b1) and esassi\
rano=:b2) for update ";

 static char *sq0012 = 
"select daireno ,esassirayil ,esassirano ,geldigitarih ,tarihi ,esasno ,karar\
no ,gonderenmahkeme ,temyizeden ,aleyhinetemyiz ,davaninturu ,dusunceler ,gond\
erendaire ,kararsonucu  from gelendosya where ((daireno=:b0 and esassirayil=:b\
1) and esassirano=:b2) for update of kararsonucu ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4114,0,0,0,
5,0,0,1,91,0,4,103,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
32,0,0,2,232,0,3,219,0,0,13,13,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,
3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
99,0,0,3,0,0,29,288,0,0,0,0,0,1,0,
114,0,0,4,0,0,17,488,0,0,1,1,0,1,0,1,5,0,0,
133,0,0,4,0,0,45,490,0,0,0,0,0,1,0,
148,0,0,4,0,0,13,494,0,0,14,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,
3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
219,0,0,4,0,0,15,502,0,0,0,0,0,1,0,
234,0,0,5,186,0,4,544,0,0,5,1,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,3,0,0,
269,0,0,6,253,0,9,700,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
296,0,0,6,0,0,13,701,0,0,13,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,
3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
363,0,0,7,0,0,31,757,0,0,0,0,0,1,0,
378,0,0,8,193,0,46,833,0,0,10,10,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
433,0,0,6,0,0,15,917,0,0,0,0,0,1,0,
448,0,0,9,0,0,29,918,0,0,0,0,0,1,0,
463,0,0,6,0,0,15,920,0,0,0,0,0,1,0,
478,0,0,10,0,0,31,921,0,0,0,0,0,1,0,
493,0,0,11,102,0,4,1051,0,0,4,3,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
524,0,0,12,281,0,9,1074,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
551,0,0,12,0,0,13,1075,0,0,13,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
618,0,0,13,0,0,31,1134,0,0,0,0,0,1,0,
633,0,0,14,145,0,3,1177,0,0,7,7,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
1,3,0,0,1,5,0,0,
676,0,0,15,142,0,46,1207,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
703,0,0,12,0,0,15,1259,0,0,0,0,0,1,0,
718,0,0,16,0,0,29,1260,0,0,0,0,0,1,0,
733,0,0,12,0,0,15,1262,0,0,0,0,0,1,0,
748,0,0,17,0,0,31,1263,0,0,0,0,0,1,0,
763,0,0,18,733,0,4,1394,0,0,20,3,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
858,0,0,19,758,0,4,1635,0,0,21,3,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,
2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
957,0,0,20,105,0,5,1792,0,0,5,5,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,
992,0,0,21,0,0,29,1847,0,0,0,0,0,1,0,
1007,0,0,22,758,0,4,1978,0,0,21,3,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
1106,0,0,23,58,0,5,2093,0,0,1,1,0,1,0,1,3,0,0,
1125,0,0,24,38,0,2,2097,0,0,1,1,0,1,0,1,3,0,0,
1144,0,0,25,0,0,29,2110,0,0,0,0,0,1,0,
};


/*
 *  evrak/hukuk/hukuk1.pc
 *
 *  Copyright (C) 1998, 1999 Nicholas Tufar
 */

#include <stdio.h>
#include <string.h>
#include "yf.h"
#include "tools.h"
#include "hukuk.h"
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
	int tekrarli; int y1999;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];


	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

	long enbuyukesas;
	char tamyil[5];

/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;
	int startfield = 0;

	clearform(cgir);
	showform(cgir);
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
	if(!tekrarli){
		clearform(cgir);
	}else{
		cgir->ifs[4].edit = 0;
		cgir->ifs[7].edit = 0;
		cgir->ifs[8].edit = 0;
		cgir->ifs[10].edit = 0;
		clearform(cgir);
		cgir->ifs[4].edit = 1;
		cgir->ifs[7].edit = 1;
		cgir->ifs[8].edit = 1;
		cgir->ifs[10].edit = 1;
		
	}
	strcpy(cgir->ifs[0].text, daire);
	cgir->ifs[0].edit = 0;
	
	if(y1999){
		strcpy(yyil,"19");
		strcpy(yil,"99");
		strcpy(tamyil,"1999");
		strcpy(tarih,"30/12/1999");
	}
	strcpy(cgir->ifs[1].text,yyil);
	strcat(cgir->ifs[1].text,yil);
	cgir->ifs[1].edit = 0;

	strcpy(cgir->ifs[3].text,tarih);
	cgir->ifs[3].edit = 0;

	yfmessage("Lütfen bekleyiniz...");
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


	if(SQL_ERROR){
		ntlog2(LOG_HUKUK,"kayit_gir.SQL_SELECT_max_esasno", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		return 0;
	}
	if(SQL_NOTFOUND){
		enbuyukesas=0;
	}
	if(ind1 < 0)enbuyukesas=0;
	yfmessage(" ");
	if(enbuyukesas == 0)enbuyukesas = 1;
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

	strcpy(tarihi,	cgir->ifs[4].text);
	tarihi[10]=0;
	if(tarihi[0]==0){
		yfmessage("Mahkeme tarihi geçersiz");
		startfield = 4;
		goto kgyineden;
	}

	esasno = atol(cgir->ifs[5].text);
	if(esasno == 0){
		yfmessage("Mahkeme esas numarasý geçersiz");
		startfield = 5;
		goto kgyineden;
	}

	kararno = atol(cgir->ifs[6].text);
	if(kararno == 0){
		yfmessage("Mahkeme karar numarasý geçersiz");
		startfield = 6;
		goto kgyineden;
	}

	strcpy(gonderenmahkeme,cgir->ifs[7].text);
	gonderenmahkeme[31]=0;
	if(gonderenmahkeme[0]==0){
		yfmessage("Geldiði mahkeme geçersiz");
		startfield = 7;
		goto kgyineden;
	}

	strcpy(temyizeden,	cgir->ifs[8].text);
	temyizeden[31]=0;
	if(temyizeden[0]==0){
		yfmessage("Temyiz eden geçersiz");
		startfield = 8;
		goto kgyineden;
	}

	strcpy(aleyhinetemyiz,	cgir->ifs[9].text);
	aleyhinetemyiz[31]=0;
	if(aleyhinetemyiz[0]==0){
		yfmessage("Aleyhine temyiz geçersiz");
		startfield = 9;
		goto kgyineden;
	}

	strcpy(davaninturu,	cgir->ifs[10].text);
	davaninturu[31]=0;
	if(davaninturu[0]==0){
		yfmessage("Davanýn türü geçersiz");
		startfield = 10;
		goto kgyineden;
	}
	
	strcpy(dusunceler,	cgir->ifs[11].text);
	dusunceler[31]=0;

	strcpy(gonderendaire,	cgir->ifs[12].text);
	gonderendaire[31]=0;

	KAYIT_GIRILSIN_MI;
        if (stat == 'e' || stat == 'E'){
	
		/* EXEC SQL INSERT INTO gelendosya 
			(
			DAIRENO, ESASSIRAYIL, ESASSIRANO, 
			GELDIGITARIH, TARIHI, ESASNO, 
			KARARNO, GONDERENMAHKEME, 
			TEMYIZEDEN, ALEYHINETEMYIZ, 
			DAVANINTURU, DUSUNCELER, GONDERENDAIRE 
			)
			VALUES(
			:daireno, :esassirayil, :esassirano,
			:geldigitarih, :tarihi,
			:esasno, :kararno,
			:gonderenmahkeme,
			:temyizeden, :aleyhinetemyiz,
			:davaninturu, :dusunceler,
			:gonderendaire)
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into gelendosya(DAIRENO,ESASSIRAYIL,ESASSIRANO,GELDI\
GITARIH,TARIHI,ESASNO,KARARNO,GONDERENMAHKEME,TEMYIZEDEN,ALEYHINETEMYIZ,DAVANI\
NTURU,DUSUNCELER,GONDERENDAIRE) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b\
9,:b10,:b11,:b12)";
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
  sqlstm.sqhstv[4] = (         void  *)tarihi;
  sqlstm.sqhstl[4] = (unsigned int  )11;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&esasno;
  sqlstm.sqhstl[5] = (unsigned int  )4;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&kararno;
  sqlstm.sqhstl[6] = (unsigned int  )4;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)gonderenmahkeme;
  sqlstm.sqhstl[7] = (unsigned int  )32;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)temyizeden;
  sqlstm.sqhstl[8] = (unsigned int  )32;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)aleyhinetemyiz;
  sqlstm.sqhstl[9] = (unsigned int  )32;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)davaninturu;
  sqlstm.sqhstl[10] = (unsigned int  )32;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)dusunceler;
  sqlstm.sqhstl[11] = (unsigned int  )32;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)gonderendaire;
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
			ntlog2(LOG_HUKUK,"kayit_gir.SQL_INSERT_INTO", SQL_MESSAGE);
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
		char	x8[1024];
		/*char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(daireno));
		strcpy(x2, quote(esassirayil));
		strcpy(x3, quote(gonderenmahkeme));
		strcpy(x4, quote(temyizeden));
		strcpy(x5, quote(aleyhinetemyiz));
		strcpy(x6, quote(davaninturu));
		strcpy(x7, quote(dusunceler));
		strcpy(x8, quote(gonderendaire));
                ntchanges("INSERT INTO gelendosya VALUES(\n"
                        "\t'%s',\t'%s',\t%lu,\n"
                        "\t'%s',\t'%s',\n"
                        "\t%lu,\t%lu,\n"
                        "\t'%s',\n"
                        "\t'%s',\t'%s',\n"
                        "\t'%s',\t'%s',\n"
                        "\t'%s');\n",
                        x1, x2, esassirano,
                        geldigitarih, tarihi, 
                        esasno, kararno,
                        x3, 
                        x4, x5,
			x6, x7,
			x8);
		}
                        /*daireno, esassirayil, esassirano,
                        geldigitarih, tarihi, 
                        esasno, kararno,
                        gonderenmahkeme, 
                        temyizeden, aleyhinetemyiz,
			davaninturu, dusunceler,
			gonderendaire);*/
                nthareket("hukuk: dosya gir");

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
	startfield = 5;
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
	char skarsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7;
	/*------------- Gelendosya ------------*/
        char daireno[4];
        char esassirayil[5];
        char esassirano[10];
        char geldigitarih[11];
        char tarihi[11];
	char esasno[10];
        char kararno[10];
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];
	long p_kararsonucu;


	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13, ind14;

	long esssno;
	long essno;
	long karno;

	char buf[1000];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	int waswhere = 0;
	int returnvalue = 0;



	nthareket("hukuk: dosya sor");
yenidensor:
	csor->ifs[0].edit = 1;
	csor->ifs[1].edit = 1;
	csor->ifs[2].edit = 1;
	csor->ifs[3].edit = 1;
	csor->ifs[4].edit = 1;
	csor->ifs[5].edit = 1;
	csor->ifs[6].edit = 1;
	csor->ifs[7].edit = 1;
	csor->ifs[8].edit = 1;
	csor->ifs[9].edit = 1;
	csor->ifs[10].edit = 1;
	csor->ifs[11].edit = 1;
	csor->ifs[12].edit = 1;
	csor->ifs[13].edit = 1;
	csor->ifs[14].edit = 1;
	csor->ifs[15].edit = 1;
	csor->ifs[16].edit = 1;
	clearform(csor);
	csor->ifs[13].edit = 0;
	csor->ifs[14].edit = 0;
	csor->ifs[15].edit = 0;
	csor->ifs[16].edit = 0;
	showform(csor);

        strcpy(csor->ifs[0].text, daire);
        /*csor->ifs[0].edit = 1;*/
	outputform(csor);

	i = inputform(csor);
	if(i == 0)return 0;
	strcpy(daireno,		csor->ifs[0].text);
	strcpy(esassirayil,	csor->ifs[1].text);
	strcpy(esassirano,	csor->ifs[2].text);
	strcpy(geldigitarih,	csor->ifs[3].text);
	strcpy(tarihi,		csor->ifs[4].text);
	strcpy(esasno,		csor->ifs[5].text);
	strcpy(kararno,		csor->ifs[6].text);
	strcpy(gonderenmahkeme,	csor->ifs[7].text);
	strcpy(temyizeden,	csor->ifs[8].text);
	strcpy(aleyhinetemyiz,	csor->ifs[9].text);
	strcpy(davaninturu,	csor->ifs[10].text);
	strcpy(dusunceler,	csor->ifs[11].text);
	strcpy(gonderendaire,	csor->ifs[12].text);
	

        strcpy(buf,"select "
                "daireno, esassirayil, esassirano, geldigitarih,"
                "tarihi, esasno, kararno, gonderenmahkeme,"
                "temyizeden, aleyhinetemyiz, davaninturu,"
                "dusunceler, gonderendaire, kararsonucu "
                "from gelendosya "); 
	/***********************/
	if(strcmp(esassirayil,"19")==0||strcmp(esassirayil,"20")==0)esassirayil[0]=0;
        if(daireno[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," daireno = '");
                strcat(buf,quote(daireno));
                strcat(buf,"'");
        }
        if(esassirayil[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," esassirayil = '");
                strcat(buf,quote(esassirayil));
                strcat(buf,"'");
        }
        if(esassirano[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," esassirano =");
                strcat(buf,esassirano);
        }
        if(geldigitarih[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," geldigitarih ='");
                strcat(buf,quote(geldigitarih));
                strcat(buf,"'");
        }
        if(tarihi[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," tarihi = '");
                strcat(buf,quote(tarihi));
                strcat(buf,"'");
        }
        if(esasno[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," esasno = ");
                strcat(buf,quote(esasno));
        }
        if(kararno[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," kararno =");
                strcat(buf,kararno);
        }
        if(gonderenmahkeme[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," gonderenmahkeme like '");
                strcat(buf,quote(gonderenmahkeme));
		strcat(buf,"%'");
        }
        if(temyizeden[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," temyizeden like '");
                strcat(buf,quote(temyizeden));
		strcat(buf,"%'");
        }
        if(aleyhinetemyiz[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," aleyhinetemyiz like '");
                strcat(buf,quote(aleyhinetemyiz));
                strcat(buf,"%'");
        }
        if(davaninturu[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," davaninturu like '");
                strcat(buf,quote(davaninturu));
                strcat(buf,"%'");
        }
        if(dusunceler[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," dusunceler like '");
                strcat(buf,quote(dusunceler));
                strcat(buf,"%'");
        }
        if(gonderendaire[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," gonderendaire like '");
                strcat(buf,quote(gonderendaire));
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
		:daireno:ind1, :esassirayil:ind2, :esssno:ind3,
		:geldigitarih:ind4, :tarihi:ind5, :essno:ind6,
		:karno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13,
		:p_kararsonucu:ind14; */ 

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
 sqlstm.sqhstv[2] = (         void  *)&esssno;
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
 sqlstm.sqhstv[4] = (         void  *)tarihi;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&essno;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&karno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[7] = (unsigned int  )32;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)temyizeden;
 sqlstm.sqhstl[8] = (unsigned int  )32;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[9] = (unsigned int  )32;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)davaninturu;
 sqlstm.sqhstl[10] = (unsigned int  )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)dusunceler;
 sqlstm.sqhstl[11] = (unsigned int  )32;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderendaire;
 sqlstm.sqhstl[12] = (unsigned int  )32;
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


	if (SQL_NOTFOUND){
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
	}
	if (SQL_ERROR){
		ntlog2(LOG_HUKUK,"kayit_sor.SQL_FETCH_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	clearform(csor);

	if(ind1 >= 0) strncpy(csor->ifs[0].text,daireno,90);
	else csor->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(csor->ifs[1].text,esassirayil,90);
	else csor->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(csor->ifs[2].text,"%lu",esssno);
	else csor->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(csor->ifs[3].text,geldigitarih,90);
	else csor->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(csor->ifs[4].text,tarihi,90);
	else csor->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(csor->ifs[5].text,"%lu",essno);
	else csor->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(csor->ifs[6].text,"%lu",karno);
	else csor->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(csor->ifs[7].text,gonderenmahkeme,90);
	else csor->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(csor->ifs[8].text,temyizeden,90);
	else csor->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(csor->ifs[9].text,aleyhinetemyiz,90);
	else csor->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(csor->ifs[10].text,davaninturu,90);
	else csor->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(csor->ifs[11].text,dusunceler,90);
	else csor->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(csor->ifs[12].text,gonderendaire,90);
	else csor->ifs[12].text[0]=0;
/**********************************************************************/
        /* simdi sonuc var mi bakalim... */

	if(p_kararsonucu != 0){
	/* EXEC SQL SELECT 
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi

	INTO 	
		:skarsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7

	FROM kararsonucu
	WHERE
		
		kararsonucu.id = :p_kararsonucu
		/okararsonucu.daireno = :daireno AND 
		kararsonucu.esassirayil = :esassirayil AND
		kararsonucu.esassirano = :esssnoo/

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
 sqlstm.sqhstv[0] = (         void  *)skarsonucu;
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


	} /* if */

	csor->ifs[13].text[0] = 0;
	csor->ifs[14].text[0] = 0;
	csor->ifs[15].text[0] = 0;
	csor->ifs[16].text[0] = 0;

	if (p_kararsonucu == 0 || SQL_NOTFOUND){
		strcpy(csor->ifs[13].text,"Bu dosya sonuca baðlanmamýþtýr");
	}else{
	        if(sind4 >= 0) strncpy(csor->ifs[13].text,skarsonucu,90);
       		else csor->ifs[13].text[0]=0;
        	if(sind5 >= 0) strncpy(csor->ifs[14].text,skarartarihi,90);
        	else csor->ifs[14].text[0]=0;
        	if(sind6 >= 0) sprintf(csor->ifs[15].text,"%lu",
				skararnumarasi,90);
        	else csor->ifs[15].text[0]=0;
        	if(sind7 >= 0) strncpy(csor->ifs[16].text,
				sgonderilistarihi,90);
        	else csor->ifs[16].text[0]=0;
	}

/**********************************************************************/

	outputform(csor);
	i = yfquestion("Sonraki kayýt görmek için herhangi tuþa basýnýz"
			" Çýkmak için x basýnýz");
	if(i == 'x' || i == 'X') break;
	}
	return returnvalue;

}
/**************************** Kayit Duzeltme ************************/
kayitduzelt()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 


        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];


	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;


/* EXEC SQL END DECLARE SECTION; */ 



	char buf[10];
	int stat;

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
kdyineden:
	stat = inputform(cgir);
	if(stat == 0){
		return 1;
	}
	if(cgir->ifs[0].text[0]==0 ||
	   cgir->ifs[1].text[0]==0 ||
	   cgir->ifs[2].text[0]==0){
		yfmessage("2 alaný doldurunuz");
		goto kdyineden;
	}

	strcpy(daireno, cgir->ifs[0].text);
	dress(daireno,3);
	strcpy(esassirayil,     cgir->ifs[1].text);
	dress(esassirayil,4);
	esassirano = atol(cgir->ifs[2].text);


	yfmessage("Lütfen bekleyiniz...");
        /* EXEC SQL DECLARE kdgdcur CURSOR FOR SELECT
                daireno, esassirayil, esassirano, geldigitarih,
                tarihi, esasno, kararno, gonderenmahkeme,
                temyizeden, aleyhinetemyiz, davaninturu,
                dusunceler, gonderendaire 
	FROM gelendosya
	WHERE
		daireno = :daireno AND
		esassirayil = :esassirayil AND
		esassirano = :esassirano
	FOR UPDATE
	; */ 

	if (SQL_ERROR){
		ntlog2(LOG_HUKUK, "kayit_duzelt.SQL_SELECT_FROM", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
	}
	if (SQL_NOTFOUND){
	        yfmessage("Öyle bir dosya bulunmadý");
		goto kdyineden;
	}
	/* EXEC SQL OPEN kdgdcur; */ 

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


	/* EXEC SQL FETCH kdgdcur
		INTO
		:daireno:ind1, :esassirayil:ind2, :esassirano:ind3,
		:geldigitarih:ind4, :tarihi:ind5, :esasno:ind6,
		:kararno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13
	; */ 

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
 sqlstm.sqhstv[2] = (         void  *)&esassirano;
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
 sqlstm.sqhstv[4] = (         void  *)tarihi;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&esasno;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&kararno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[7] = (unsigned int  )32;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)temyizeden;
 sqlstm.sqhstl[8] = (unsigned int  )32;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[9] = (unsigned int  )32;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)davaninturu;
 sqlstm.sqhstl[10] = (unsigned int  )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)dusunceler;
 sqlstm.sqhstl[11] = (unsigned int  )32;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderendaire;
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
	/*-------------------------------------*/
kyineden1:
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
	if(ind3 >= 0) sprintf(cgir->ifs[2].text,"%lu",esassirano);
	else cgir->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(cgir->ifs[3].text,geldigitarih,90);
	else cgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(cgir->ifs[4].text,tarihi,90);
	else cgir->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(cgir->ifs[5].text,"%lu",esasno);
	else cgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(cgir->ifs[6].text,"%lu",kararno);
	else cgir->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(cgir->ifs[7].text,gonderenmahkeme,90);
	else cgir->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(cgir->ifs[8].text,temyizeden,90);
	else cgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(cgir->ifs[9].text,aleyhinetemyiz,90);
	else cgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(cgir->ifs[10].text,davaninturu,90);
	else cgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(cgir->ifs[11].text,dusunceler,90);
	else cgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(cgir->ifs[12].text,gonderendaire,90);
	else cgir->ifs[12].text[0]=0;
	/*-------------------------------------*/
	outputform(cgir);
kdyenidendene:
	stat = inputform(cgir);
	if (stat == 0){
		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )363;
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
	dress(daireno,3);

	strcpy(esassirayil,	cgir->ifs[1].text);
	dress(esassirayil,4);

	esassirano = atol(cgir->ifs[2].text);

	strcpy(geldigitarih,cgir->ifs[3].text);
	geldigitarih[10]=0;

	strcpy(tarihi,	cgir->ifs[4].text);
	tarihi[10]=0;
	if(tarihi[0]==0){
		yfmessage("Mahkeme tarihi geçersiz");
		goto kdyenidendene;
	}

	esasno = atol(cgir->ifs[5].text);
	if(esasno == 0){
		yfmessage("Mahkeme esas numarasý geçersiz");
		goto kdyenidendene;
	}

	kararno = atol(cgir->ifs[6].text);
	if(kararno == 0){
		yfmessage("Mahkeme karar numarasý geçersiz");
		goto kdyenidendene;
	}

	strcpy(gonderenmahkeme,cgir->ifs[7].text);
	gonderenmahkeme[31]=0;
	if(gonderenmahkeme[0]==0){
		yfmessage("Geldiði mahkeme geçersiz");
		goto kdyenidendene;
	}

	strcpy(temyizeden,	cgir->ifs[8].text);
	temyizeden[31]=0;
	if(temyizeden[0]==0){
		yfmessage("Temyiz eden geçersiz");
		goto kdyenidendene;
	}

	strcpy(aleyhinetemyiz,	cgir->ifs[9].text);
	aleyhinetemyiz[31]=0;
	/*if(aleyhinetemyiz[0]==0){
		yfmessage("Aleyhine temyiz geçersiz");
		goto kdyenidendene;
	}*/

	strcpy(davaninturu,	cgir->ifs[10].text);
	davaninturu[31]=0;
	if(davaninturu[0]==0){
		yfmessage("Davanýn türü geçersiz");
		goto kdyenidendene;
	}
	
	strcpy(dusunceler,	cgir->ifs[11].text);
	dusunceler[31]=0;

	strcpy(gonderendaire,	cgir->ifs[12].text);
	gonderendaire[31]=0;
/*********************************************************************/
	stat = yfquestion("Bu kayýt girilsin mi? (e/h)");
        if (stat == 'e' || stat == 'E'){
	
	
	
	/* EXEC SQL UPDATE gelendosya SET
		geldigitarih 	= :geldigitarih, 
		tarihi	 	= :tarihi, 
		esasno	 	= :esasno,
		kararno 	= :kararno, 
		gonderenmahkeme	= :gonderenmahkeme, 
		temyizeden 	= :temyizeden,
		aleyhinetemyiz	= :aleyhinetemyiz, 
		davaninturu	= :davaninturu, 
		dusunceler	= :dusunceler, 
		gonderendaire	= :gonderendaire
	WHERE 
		CURRENT OF kdgdcur
	/o	daireno 	= :daireno AND
		esassirayil	= :esassirayil AND
		esassirano	= :esassirano
	o/
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update gelendosya  set geldigitarih=:b0,tarihi=:b1,esasno=:b\
2,kararno=:b3,gonderenmahkeme=:b4,temyizeden=:b5,aleyhinetemyiz=:b6,davanintur\
u=:b7,dusunceler=:b8,gonderendaire=:b9 where rowid = :x";
 sqlstm.iters = (unsigned int  )6;
 sqlstm.offset = (unsigned int  )378;
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
 sqlstm.sqhstv[1] = (         void  *)tarihi;
 sqlstm.sqhstl[1] = (unsigned int  )11;
 sqlstm.sqhsts[1] = (         int  )11;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&esasno;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )4;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&kararno;
 sqlstm.sqhstl[3] = (unsigned int  )4;
 sqlstm.sqhsts[3] = (         int  )4;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[4] = (unsigned int  )32;
 sqlstm.sqhsts[4] = (         int  )32;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)temyizeden;
 sqlstm.sqhstl[5] = (unsigned int  )32;
 sqlstm.sqhsts[5] = (         int  )32;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[6] = (unsigned int  )32;
 sqlstm.sqhsts[6] = (         int  )32;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)davaninturu;
 sqlstm.sqhstl[7] = (unsigned int  )32;
 sqlstm.sqhsts[7] = (         int  )32;
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)dusunceler;
 sqlstm.sqhstl[8] = (unsigned int  )32;
 sqlstm.sqhsts[8] = (         int  )32;
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)gonderendaire;
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
		ntlog2(LOG_HUKUK, "kayit_duzelt.SQL_UPDATE", SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto kyineden1;
	}
		{
		char	x1[1024];
		char	x2[1024];
		char	x3[1024];
		char	x4[1024];
		char	x5[1024];
		char	x6[1024];
		/*char	x7[1024];
		char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(gonderenmahkeme));
		strcpy(x2, quote(temyizeden));
		strcpy(x3, quote(aleyhinetemyiz));
		strcpy(x4, quote(davaninturu));
		strcpy(x5, quote(dusunceler));
		strcpy(x6, quote(gonderendaire));
        ntchanges("UPDATE gelendosya SET\n"
                "\tgeldigitarih = '%s', \n"
                "\ttarihi  = '%s', \n"
                "\tesasno   = %lu,\n"
                "\tkararno     = %lu, \n"
                "\tgonderenmahkeme      = '%s', \n"
                "\ttemyizeden    = '%s', \n"
                "\taleyhinetemyiz   = '%s', \n"
                "\tdavaninturu      = '%s',\n"
		"\tdusunceler = '%s',\n"
		"\tgonderendaire = '%s'\n"
                "WHERE\n"
                "\tdaireno      = '%s' AND\n"
                "\tesassirayil  = '%s' AND\n"
                "\tesassirano   = %lu;\n",
		geldigitarih, 
		tarihi, 
		esasno,
		kararno, 
		x1, 
		x2,
		x3, 
		x4, 
		x5, 
		x6,
		/*gonderenmahkeme, 
		temyizeden,
		aleyhinetemyiz, 
		davaninturu, 
		dusunceler, 
		gonderendaire,*/
			/* WHERE */
		daireno,
		esassirayil,
		esassirano
	);
	}
	nthareket("hukuk: dosya duzeltme");

	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL CLOSE kdgdcur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )433;
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
 sqlstm.offset = (unsigned int  )448;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else {
		/* EXEC SQL CLOSE kdgdcur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )463;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* EXEC sQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )478;
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
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skarsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7;
	/*------------- Gelendosya ------------*/

        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];
	long p_kararsonucu;


	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13, ind14;

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
sgyenikayit:
	sgir->ifs[0].edit = 0;
	sgir->ifs[1].edit = 0;
	sgir->ifs[2].edit = 0;
	sgir->ifs[3].edit = 0;
	sgir->ifs[4].edit = 0;
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
sgyineden:
	stat = inputform(sgir);
	if (stat == 0)return 1;
	/*---------------------*/
	strcpy(sdaireno, sgir->ifs[0].text);
	dress(sdaireno,3);

	strcpy(sesassirayil, sgir->ifs[1].text);
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto sgyineden;
	}
	dress(esassirayil,4);

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		goto sgyineden;
	}
	/* EXEC SQL SELECT daireno  
	INTO :sdaireno
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
 sqlstm.stmt = "select daireno into :b0  from kararsonucu where ((daireno=:b\
0 and esassirayil=:b2) and esassirano=:b3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )493;
 sqlstm.selerr = (unsigned short)1;
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


	if (sqlca.sqlcode != 1403){
		yfmessage("Bu sonuç zaten girilmiþ");
		goto sgyineden;
	}
	/*------------- Get data from gelendosya --------------*/
	yfmessage("Lütfen bekleyiniz...");
        /* EXEC SQL DECLARE sggdcur CURSOR FOR SELECT
                daireno, esassirayil, esassirano, geldigitarih,
                tarihi, esasno, kararno, gonderenmahkeme,
                temyizeden, aleyhinetemyiz, davaninturu,
                dusunceler, gonderendaire , kararsonucu
		FROM gelendosya
		WHERE
		daireno = :sdaireno and esassirayil = :sesassirayil and
		esassirano = :sesassirano
		FOR UPDATE OF kararsonucu
	; */ 

	/* EXEC SQL OPEN sggdcur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )524;
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


	/* EXEC SQL FETCH sggdcur
		INTO
		:daireno:ind1, :esassirayil:ind2, :esassirano:ind3,
		:geldigitarih:ind4, :tarihi:ind5, :esasno:ind6,
		:kararno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )551;
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
 sqlstm.sqhstv[2] = (         void  *)&esassirano;
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
 sqlstm.sqhstv[4] = (         void  *)tarihi;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&esasno;
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)&ind6;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&kararno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)&ind7;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[7] = (unsigned int  )32;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)temyizeden;
 sqlstm.sqhstl[8] = (unsigned int  )32;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[9] = (unsigned int  )32;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)davaninturu;
 sqlstm.sqhstl[10] = (unsigned int  )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)dusunceler;
 sqlstm.sqhstl[11] = (unsigned int  )32;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderendaire;
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
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tarihi,90);
	else sgir->ifs[8].text[0]=0;
	if(ind6 >= 0) sprintf(sgir->ifs[9].text,"%lu",esasno);
	else sgir->ifs[9].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",kararno);
	else sgir->ifs[10].text[0]=0;
	if(ind8 >= 0) strncpy(sgir->ifs[11].text,gonderenmahkeme,90);
	else sgir->ifs[11].text[0]=0;
	if(ind9 >= 0) strncpy(sgir->ifs[12].text,temyizeden,90);
	else sgir->ifs[12].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,aleyhinetemyiz,90);
	else sgir->ifs[13].text[0]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,davaninturu,90);
	else sgir->ifs[14].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,dusunceler,90);
	else sgir->ifs[15].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,gonderendaire,90);
	else sgir->ifs[16].text[0]=0;


	/*-------------------------------------*/
	outputform(sgir);
sgyine2:
	stat = inputform(sgir);
	if(stat == 0){
		/* EXEC SQL ROLLBACK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )618;
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
	dress(sdaireno,3);

	strcpy(sesassirayil,	sgir->ifs[1].text);
	dress(sdaireno,2);

	sesassirano = atol(sgir->ifs[2].text);

        strcpy(skarsonucu,    sgir->ifs[3].text);
        skarsonucu[30]=0;
	if(skarsonucu[0]==0){
		yfmessage("Karar geçersiz\n");
		goto sgyine2;
	}

	strcpy(skarartarihi,sgir->ifs[4].text);
	skarartarihi[10]=0;
	if(skarartarihi[0]==0){
		yfmessage("Karar tarihi geçersiz\n");
		goto sgyine2;
	}

	skararnumarasi = atol(sgir->ifs[5].text);
	if(skararnumarasi == 0){
		yfmessage("Karar numarasý geçersiz");
		goto sgyine2;
	}

	strcpy(sgonderilistarihi,	sgir->ifs[6].text);
	sgonderilistarihi[10]=0;
	if(sgonderilistarihi[0] == 0){
		yfmessage("PTT teslim tarihi geçersiz");
		goto sgyine2;
	}

	
	stat = yfquestion("Bu kayýt girilsin mi? (e/h)");
        if (stat == 'e' || stat == 'E'){
	/* EXEC SQL INSERT INTO kararsonucu 
		(
		DAIRENO, ESASSIRAYIL, ESASSIRANO,
		KARSONUCU, KARARTARIHI, 
		KARARNUMARASI, GONDERILISTARIHI
		)
		VALUES(
		:sdaireno, :sesassirayil, :sesassirano,
		:skarsonucu,
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
 sqlstm.offset = (unsigned int  )633;
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
 sqlstm.sqhstv[3] = (         void  *)skarsonucu;
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
		ntlog2(LOG_HUKUK, "sonuc_gir.SQL_INSERT_INTO", SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
/*
	EXEC SQL SELECT id INTO p_kararsonucu FROM kararsonucu
		WHERE
			daireno = :sdaireno AND
			esassirayil = :sesassirayil AND
			esassirano = :sesassirano
	;
	if (SQL_ERROR){
		ntlog2(LOG_HUKUK, "sonuc_gir.SQL_INSERT_INTO1", SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
*/
	/* EXEC SQL UPDATE gelendosya SET kararsonucu = 
			(
				SELECT id FROM kararsonucu
				WHERE
					daireno = :sdaireno AND
					esassirayil = :sesassirayil AND
					esassirano = :sesassirano
			)
		WHERE CURRENT OF sggdcur
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
 sqlstm.offset = (unsigned int  )676;
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
		ntlog2(LOG_HUKUK, "sonuc_gir.SQL_INSERT_INTO2", SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sgyine2;
	}
		{
		char	x1[1024];
		char	x2[1024];
		char	x3[1024];
		char	x4[1024];
		/*char	x5[1024];
		char	x6[1024];
		char	x7[1024];
		char	x8[1024];
		char	x9[1024];
		char	x10[1024];
		char	x11[1024];
		char	x12[1024];*/
		strcpy(x1, quote(sdaireno));
		strcpy(x2, quote(sesassirayil));
		strcpy(x3, quote(skarsonucu));
		strcpy(x4, quote(sgonderilistarihi));
	ntchanges("INSERT INTO kararsonucu VALUES(\n"
		"\t'%s',\t'%s',\t%lu,\n"
		"\t'%s',\n"
		"\t'%s',\t%lu,\n"
		"\t'%s');\n",
		x1, x2, sesassirano,
		x3,
		skarartarihi, skararnumarasi,
		sgonderilistarihi
		/*
		sdaireno, sesassirayil, sesassirano,
		skarsonucu,
		skarartarihi, skararnumarasi,
		sgonderilistarihi
		*/
	);
	}
	nthareket("hukuk: karar girme");

	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL CLOSE sggdcur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )703;
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
 sqlstm.offset = (unsigned int  )718;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else {
		/* EXEC SQL CLOSE sggdcur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )733;
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
  sqlstm.offset = (unsigned int  )748;
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
	long sid;
	char sdaireno[4];
	char sesassirayil[5];
	long sesassirano;
	char skarsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7,sind8;
	/*------------- Gelendosya ------------*/

        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];


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

	strcpy(sesassirayil, sgir->ifs[1].text);
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto ssyineden;
	}
	dress(sesassirayil,4);

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
                gelendosya.tarihi, 
		gelendosya.esasno, 
		gelendosya.kararno, 
		gelendosya.gonderenmahkeme,
                gelendosya.temyizeden, 
		gelendosya.aleyhinetemyiz, 
		gelendosya.davaninturu,
                gelendosya.dusunceler, 
		gelendosya.gonderendaire 
	INTO 	
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skarsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

		:geldigitarih:ind4, :tarihi:ind5, :esasno:ind6,
		:kararno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13

	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		kararsonucu.id = gelendosya.kararsonucu
		/okararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassirano
		o/
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
a.tarihi ,gelendosya.esasno ,gelendosya.kararno ,gelendosya.gonderenmahkeme ,g\
elendosya.temyizeden ,gelendosya.aleyhinetemyiz ,gelendosya.davaninturu ,gelen\
dosya.dusunceler ,gelendosya.gonderendaire into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b\
8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:\
b26:b27,:b28:b29,:b30:b31,:b32:b33  from kararsonucu ,gelendosya where (((kara\
rsonucu.daireno=:b0 and kararsonucu.esassirayil=:b2) and kararsonucu.esassiran\
o=:b4) and kararsonucu.id=gelendosya.kararsonucu)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )763;
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
 sqlstm.sqhstv[3] = (         void  *)skarsonucu;
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
 sqlstm.sqhstv[8] = (         void  *)tarihi;
 sqlstm.sqhstl[8] = (unsigned int  )11;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind5;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&esasno;
 sqlstm.sqhstl[9] = (unsigned int  )4;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind6;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&kararno;
 sqlstm.sqhstl[10] = (unsigned int  )4;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind7;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[11] = (unsigned int  )32;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind8;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)temyizeden;
 sqlstm.sqhstl[12] = (unsigned int  )32;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind9;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[13] = (unsigned int  )32;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind10;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)davaninturu;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind11;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)dusunceler;
 sqlstm.sqhstl[15] = (unsigned int  )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind12;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)gonderendaire;
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
	if(SQL_ERROR){
		ntlog2(LOG_HUKUK, "sonuc_sor.SQL_SELECT_FROM_kararsonucu",  SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
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
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skarsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;

	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(sgir->ifs[9].text,"%lu",esasno);
	else sgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",kararno);
	else sgir->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(sgir->ifs[11].text,gonderenmahkeme,90);
	else sgir->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(sgir->ifs[12].text,temyizeden,90);
	else sgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,aleyhinetemyiz,90);
	else sgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,davaninturu,90);
	else sgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,dusunceler,90);
	else sgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,gonderendaire,90);
	else sgir->ifs[12].text[0]=0;

	/*-------------------------------------*/
	nthareket("hukuk: sonuc sorgulama");
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
	char skarsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7, sind8;
	/*------------- Gelendosya ------------*/

        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];

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
	dress(sdaireno,3);

	strcpy(sesassirayil, sgir->ifs[1].text);
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto sdyineden;
	}
	dress(sesassirayil,4);

	sesassirano=atol(sgir->ifs[2].text);
	if(sesassirano == 0){
		yfmessage("Geçersiz esas sýra numarasý");
		goto sdyineden;
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
                gelendosya.tarihi, 
		gelendosya.esasno, 
		gelendosya.kararno, 
		gelendosya.gonderenmahkeme,
                gelendosya.temyizeden, 
		gelendosya.aleyhinetemyiz, 
		gelendosya.davaninturu,
                gelendosya.dusunceler, 
		gelendosya.gonderendaire 
	INTO 	
		:sid:sind8,
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skarsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

		:geldigitarih:ind4, :tarihi:ind5, :esasno:ind6,
		:kararno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13

	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		kararsonucu.id = gelendosya.kararsonucu
	/o	kararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassirano
	o/
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
tarih ,gelendosya.tarihi ,gelendosya.esasno ,gelendosya.kararno ,gelendosya.go\
nderenmahkeme ,gelendosya.temyizeden ,gelendosya.aleyhinetemyiz ,gelendosya.da\
vaninturu ,gelendosya.dusunceler ,gelendosya.gonderendaire into :b0:b1,:b2:b3,\
:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b2\
2:b23,:b24:b25,:b26:b27,:b28:b29,:b30:b31,:b32:b33,:b34:b35  from kararsonucu \
,gelendosya where (((kararsonucu.daireno=:b2 and kararsonucu.esassirayil=:b4) \
and kararsonucu.esassirano=:b6) and kararsonucu.id=gelendosya.kararsonucu)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )858;
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
 sqlstm.sqhstv[4] = (         void  *)skarsonucu;
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
 sqlstm.sqhstv[9] = (         void  *)tarihi;
 sqlstm.sqhstl[9] = (unsigned int  )11;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind5;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&esasno;
 sqlstm.sqhstl[10] = (unsigned int  )4;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind6;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&kararno;
 sqlstm.sqhstl[11] = (unsigned int  )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind7;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[12] = (unsigned int  )32;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind8;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)temyizeden;
 sqlstm.sqhstl[13] = (unsigned int  )32;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind9;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind10;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)davaninturu;
 sqlstm.sqhstl[15] = (unsigned int  )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind11;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)dusunceler;
 sqlstm.sqhstl[16] = (unsigned int  )32;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         void  *)&ind12;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)gonderendaire;
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
		goto sdyineden;
	}
	if (SQL_ERROR){
		ntlog2(LOG_HUKUK, "sonuc_duzelt.SQL_SELECT_FROM_KARARSONUCU", SQL_MESSAGE); 
		yfquestion(SQL_MESSAGE);
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
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skarsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;

	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(sgir->ifs[9].text,"%lu",esasno);
	else sgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",kararno);
	else sgir->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(sgir->ifs[11].text,gonderenmahkeme,90);
	else sgir->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(sgir->ifs[12].text,temyizeden,90);
	else sgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,aleyhinetemyiz,90);
	else sgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,davaninturu,90);
	else sgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,dusunceler,90);
	else sgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,gonderendaire,90);
	else sgir->ifs[12].text[0]=0;

	outputform(sgir);
sdyine2:
	stat = inputform(sgir);
	if(stat == 0)return 0;
	/*-----------------------------------------------------*/
	/* Insert new values */
	/*strcpy(sdaireno,	sgir->ifs[0].text);
	dress(sdaireno,3);

	strcpy(sesassirayil,	sgir->ifs[1].text);
	dress(sesassirayil,4);

	sesassirano = atol(sgir->ifs[2].text);*/

        strcpy(skarsonucu,    sgir->ifs[3].text);
        skarsonucu[30]=0;
	if(skarsonucu[0] == 0){
		yfmessage("Karar sonucu geçersiz");
		goto sdyine2;
	}

	strcpy(skarartarihi,sgir->ifs[4].text);
	skarartarihi[10]=0;
	if(skarartarihi[0] == 0){
		yfmessage("Karar tarihi geçersiz");
		goto sdyine2;
	}

	skararnumarasi = atol(sgir->ifs[5].text);
	if(skararnumarasi == 0){
		yfmessage("Karar numarasý geçersiz");
		goto sdyine2;
	}

	strcpy(sgonderilistarihi,	sgir->ifs[6].text);
	sgonderilistarihi[10]=0;
	if(sgonderilistarihi[0] == 0){
		yfmessage("PTT teslim tarihi geçersiz");
		goto sdyine2;
	}

	
	stat = yfquestion("Bu kayýt girilsin mi? (e/h)");
        if (stat == 'e' || stat == 'E'){
	/* EXEC SQL UPDATE kararsonucu SET
		karsonucu = :skarsonucu,
		karartarihi = :skarartarihi,
		kararnumarasi =  :skararnumarasi,
		gonderilistarihi = :sgonderilistarihi
	WHERE 
		id = :sid
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
 sqlstm.stmt = "update kararsonucu  set karsonucu=:b0,karartarihi=:b1,kararn\
umarasi=:b2,gonderilistarihi=:b3 where id=:b4";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )957;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)skarsonucu;
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



	if (SQL_ERROR || SQL_NOTFOUND){
		ntlog2(LOG_HUKUK, "sonuc_duzelt.SQL_UPDATE", SQL_MESSAGE);
		yfmessage(SQL_MESSAGE);
		goto sdyine2;
	}
		{
		char	x1[1024];
		char	x2[1024];/*
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
		strcpy(x1, quote(skarsonucu));
		strcpy(x2, quote(sgonderilistarihi));
	ntchanges("UPDATE kararsonucu SET\n"
		"\tkarsonucu\t=\t'%s',\n"
		"\tkarartarihi\t=\t'%s',\n"
		"\tkararnumarasi\t=\t%lu,\n"
		"\tgonderilistarihi\t=\t'%s'\n"
		"WHERE\n"
		"\tdaireno\t=\t'%s' AND\n"
		"\tesassirayil\t=\t'%s' AND\n"
		"\tesassirano\t=\t%lu;\n",
		x1,
		/*skarsonucu,*/
		skarartarihi,
		skararnumarasi,
		sgonderilistarihi,
		/* WHERE */
		sdaireno,
		sesassirayil,
		sesassirano
	);
	}
		
	nthareket("hukuk: sonuc duzeltme");
	yfmessage("Kayýt kaydedildi");
	/* EXEC SQL COMMIT WORK ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )992;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else yfmessage("Kayýt iptal edildi");
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
	char skarsonucu[31];
	char skarartarihi[11];
	long skararnumarasi;
	char sgonderilistarihi[11];
	short sind1,sind2,sind3,sind4,sind5,sind6,sind7, sind8;
	/*------------- Gelendosya ------------*/

        char daireno[4];
        char esassirayil[5];
        long esassirano;
        char geldigitarih[11];
        char tarihi[11];
	long esasno;
        long kararno;
	char gonderenmahkeme[32];
	char temyizeden[32];
	char aleyhinetemyiz[32];
	char davaninturu[32];
	char dusunceler[32];
	char gonderendaire[32];

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

	strcpy(sesassirayil, sgir->ifs[1].text);
	sesassirayil[4]=0;
	if(sesassirayil[0]==0){
		yfmessage("Geçersiz esas sýra yýl");
		goto ssilyineden;
	}
	dress(sesassirayil,4);

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
                gelendosya.tarihi, 
		gelendosya.esasno, 
		gelendosya.kararno, 
		gelendosya.gonderenmahkeme,
                gelendosya.temyizeden, 
		gelendosya.aleyhinetemyiz, 
		gelendosya.davaninturu,
                gelendosya.dusunceler, 
		gelendosya.gonderendaire 
	INTO 	
		:sid:sind8,
		:sdaireno:sind1, :sesassirayil:sind2,
		:sesassirano:sind3, :skarsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7,

		:geldigitarih:ind4, :tarihi:ind5, :esasno:ind6,
		:kararno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13

	FROM kararsonucu,gelendosya
	WHERE
		
		kararsonucu.daireno = :sdaireno AND 
		kararsonucu.esassirayil = :sesassirayil AND
		kararsonucu.esassirano = :sesassirano	AND

		kararsonucu.id = gelendosya.kararsonucu
		/okararsonucu.daireno = gelendosya.daireno AND
		kararsonucu.esassirayil = gelendosya.esassirayil AND
		kararsonucu.esassirano = gelendosya.esassirano
		o/
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
tarih ,gelendosya.tarihi ,gelendosya.esasno ,gelendosya.kararno ,gelendosya.go\
nderenmahkeme ,gelendosya.temyizeden ,gelendosya.aleyhinetemyiz ,gelendosya.da\
vaninturu ,gelendosya.dusunceler ,gelendosya.gonderendaire into :b0:b1,:b2:b3,\
:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b2\
2:b23,:b24:b25,:b26:b27,:b28:b29,:b30:b31,:b32:b33,:b34:b35  from kararsonucu \
,gelendosya where (((kararsonucu.daireno=:b2 and kararsonucu.esassirayil=:b4) \
and kararsonucu.esassirano=:b6) and kararsonucu.id=gelendosya.kararsonucu)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1007;
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
 sqlstm.sqhstv[4] = (         void  *)skarsonucu;
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
 sqlstm.sqhstv[9] = (         void  *)tarihi;
 sqlstm.sqhstl[9] = (unsigned int  )11;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind5;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&esasno;
 sqlstm.sqhstl[10] = (unsigned int  )4;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind6;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&kararno;
 sqlstm.sqhstl[11] = (unsigned int  )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind7;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderenmahkeme;
 sqlstm.sqhstl[12] = (unsigned int  )32;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind8;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)temyizeden;
 sqlstm.sqhstl[13] = (unsigned int  )32;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&ind9;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[14] = (unsigned int  )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         void  *)&ind10;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)davaninturu;
 sqlstm.sqhstl[15] = (unsigned int  )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         void  *)&ind11;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)dusunceler;
 sqlstm.sqhstl[16] = (unsigned int  )32;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         void  *)&ind12;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)gonderendaire;
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
	if (SQL_ERROR){
		ntlog2(LOG_HUKUK, "sonuc_sil.SQL_SELECT_FROM_KARARSONUCU",  SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
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
	if(sind4 >= 0) strncpy(sgir->ifs[3].text,skarsonucu,90);
	else sgir->ifs[3].text[0]=0;
	if(sind5 >= 0) strncpy(sgir->ifs[4].text,skarartarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(sind6 >= 0) sprintf(sgir->ifs[5].text,"%lu",skararnumarasi,90);
	else sgir->ifs[5].text[0]=0;
	if(sind7 >= 0) strncpy(sgir->ifs[6].text,sgonderilistarihi,90);
	else sgir->ifs[6].text[0]=0;

	if(ind4 >= 0) strncpy(sgir->ifs[7].text,geldigitarih,90);
	else sgir->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(sgir->ifs[8].text,tarihi,90);
	else sgir->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(sgir->ifs[9].text,"%lu",esasno);
	else sgir->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(sgir->ifs[10].text,"%lu",kararno);
	else sgir->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(sgir->ifs[11].text,gonderenmahkeme,90);
	else sgir->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(sgir->ifs[12].text,temyizeden,90);
	else sgir->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(sgir->ifs[13].text,aleyhinetemyiz,90);
	else sgir->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(sgir->ifs[14].text,davaninturu,90);
	else sgir->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(sgir->ifs[15].text,dusunceler,90);
	else sgir->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(sgir->ifs[16].text,gonderendaire,90);
	else sgir->ifs[12].text[0]=0;
	/*-------------------------------------*/
	outputform(sgir);
ssilyine2:
	stat = yfquestion("Bu kayýt silinsin mi? (e/h)");
	if (stat == 'e' || stat == 'E'){
	
		/* EXEC SQL UPDATE gelendosya
			SET kararsonucu = 0
			WHERE kararsonucu = :sid
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update gelendosya  set kararsonucu=0 where kararsonucu=:b0";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1106;
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


		/* EXEC SQL DELETE FROM kararsonucu 
		WHERE 
			id = :sid
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
  sqlstm.stmt = "delete  from kararsonucu  where id=:b0";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1125;
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
			ntlog2(LOG_HUKUK, "sonuc_sil.SQL_DELETE", SQL_MESSAGE);
			yfmessage(SQL_MESSAGE);
			goto ssilyine2;
		}
		/* EXEC SQL COMMIT WORK ; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1144;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		ntchanges("DELETE FROM kararsonucu\n"
			"WHERE\n"
			"\tdaireno\t=\t'%s' AND\n"
			"\tesassirayil\t=\t'%s' AND\n"
			"\tesassirano\t=\t%lu;\n",
			sdaireno,
			sesassirayil,
			sesassirano
		);
		nthareket("hukuk: sonuc silme");
		yfmessage("Kayýt silindi");
	}else yfmessage("Silme iptal edildi");
	goto ssilyenisor;
}
