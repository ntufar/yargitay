
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
  1,1,0,
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
    "emsal1.pc"
};


static unsigned long sqlctx = 36931;


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
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {10,5};

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

 static char *sq0003 = 
"select kavram ,count(kavram)  from kavram where (daireno=:b0 or daireno=:b1)\
 group by kavram order by kavram            ";

 static char *sq0004 = 
"select kavram ,count(kavram)  from kavram  group by kavram order by kavram  \
          ";

 static char *sq0007 = 
"select esasno ,daireno  from kavram where ((daireno=:b0 or daireno=:b1) and \
(kavram=:b2 or kavram=:b3)) order by esasno            ";

 static char *sq0008 = 
"select esasno ,daireno  from kavram where (kavram=:b0 or kavram=:b1) order b\
y esasno            ";

 static char *sq0012 = 
"select kanun ,count(kanun) ,kanunno  from kanun where (daireno=:b0 or dairen\
o=:b1) group by kanun,kanunno order by kanun            ";

 static char *sq0013 = 
"select kanun ,count(kanun) ,kanunno  from kanun  group by kanun,kanunno orde\
r by kanun            ";

 static char *sq0016 = 
"select madde ,count(madde)  from kanun where ((daireno=:b0 or daireno=:b1) a\
nd kanun=:b2) group by madde order by madde            ";

 static char *sq0017 = 
"select madde ,count(madde)  from kanun where kanun=:b0 group by madde order \
by madde            ";

 static char *sq0020 = 
"select esasno ,daireno  from kanun where (((daireno=:b0 or daireno=:b1) and \
kanun=:b2) and madde=:b3)           ";

 static char *sq0021 = 
"select esasno ,daireno  from kanun where (kanun=:b0 and madde=:b1)          \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4146,0,0,0,
5,0,0,1,89,0,4,61,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
32,0,0,2,55,0,4,66,0,0,1,0,0,1,0,2,3,0,0,
51,0,0,3,120,0,9,105,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
74,0,0,4,86,0,9,106,0,0,0,0,0,1,0,
89,0,0,3,0,0,13,115,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
112,0,0,4,0,0,13,116,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
135,0,0,3,0,0,15,126,0,0,0,0,0,1,0,
150,0,0,4,0,0,15,127,0,0,0,0,0,1,0,
165,0,0,5,130,0,4,241,0,0,5,4,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
200,0,0,6,95,0,4,250,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
227,0,0,7,131,0,9,295,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
258,0,0,8,96,0,9,296,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
281,0,0,7,0,0,13,305,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
304,0,0,8,0,0,13,307,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
327,0,0,7,0,0,15,318,0,0,0,0,0,1,0,
342,0,0,8,0,0,15,319,0,0,0,0,0,1,0,
357,0,0,9,104,0,4,429,0,0,5,4,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
392,0,0,10,87,0,4,505,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
419,0,0,11,53,0,4,511,0,0,1,0,0,1,0,2,3,0,0,
438,0,0,12,132,0,9,557,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
461,0,0,13,98,0,9,558,0,0,0,0,0,1,0,
476,0,0,12,0,0,13,569,0,0,3,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,
503,0,0,13,0,0,13,571,0,0,3,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,
530,0,0,12,0,0,15,585,0,0,0,0,0,1,0,
545,0,0,13,0,0,15,586,0,0,0,0,0,1,0,
560,0,0,14,103,0,4,701,0,0,4,3,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
591,0,0,15,68,0,4,708,0,0,2,1,0,1,0,2,3,0,0,1,5,0,0,
614,0,0,16,131,0,9,753,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,
641,0,0,17,96,0,9,754,0,0,1,1,0,1,0,1,5,0,0,
660,0,0,16,0,0,13,764,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
683,0,0,17,0,0,13,765,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
706,0,0,16,0,0,15,776,0,0,0,0,0,1,0,
721,0,0,17,0,0,15,777,0,0,0,0,0,1,0,
736,0,0,18,120,0,4,901,0,0,5,4,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
771,0,0,19,85,0,4,910,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,
798,0,0,20,112,0,9,956,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
829,0,0,21,77,0,9,957,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
852,0,0,20,0,0,13,966,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
875,0,0,21,0,0,13,969,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
898,0,0,20,0,0,15,982,0,0,0,0,0,1,0,
913,0,0,21,0,0,15,983,0,0,0,0,0,1,0,
928,0,0,22,88,0,4,1086,0,0,4,3,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <malloc.h>
#include "yf.h"
#include "tools.h"
#include "emsal.h"
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



int karagoster(char *ikavram, int kendi);
int kgmetin(char *iesas, char *idaire);

kara(kendi)
int kendi;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[4];
char esasno[10];
char kavram[76];

/*char kmetin[1024*100];
*/
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[5];
/* EXEC SQL END DECLARE SECTION; */ 


	char **mbuf;
	long *mcount;
	int i,k;
	int stat;
	int quit;
	int pointer;

	nthareket("emsal: kavram arama");
karabootstrap:
	if(daire[0]=='t')kendi = 0;
	else kendi = 1;
	stat=quit=pointer=0;
	clearform(fkara);
	
	strcpy(nakeddaire,daire);
	strcpy(dresseddaire,daire);
	strip(nakeddaire);
	dress(dresseddaire,3);
        yfmessage("Lütfen bekleyiniz...");
	if(kendi){
		/* EXEC SQL SELECT count(distinct kavram) INTO :count:ind0
			FROM kavram	
			WHERE daireno = :dresseddaire OR daireno=:nakeddaire
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct kavram) into :b0:b1  from kavram wher\
e (daireno=:b2 or daireno=:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)dresseddaire;
  sqlstm.sqhstl[1] = (unsigned int  )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)nakeddaire;
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


	}else{
		/* EXEC SQL SELECT count(distinct kavram) INTO :count:ind0
			FROM kavram	
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct kavram) into :b0:b1  from kavram ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
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


	}
        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
          	yfquestion(SQL_MESSAGE);
         	return 0;
  	}
      	if(SQL_NOTFOUND || count == 0){
               	yfquestion("Hiçbir kavram bulunmamýþtýr");
		strcpy(daire,"tüm");
               	return 0;
       	}
	if((mbuf = (char**)malloc(count*sizeof(char*)))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	if((mcount = (long*)malloc(count*sizeof(long)))==NULL){
		yfquestion("Bellek yetersiz");
		free(mbuf);
		return 0;
	}
	if(kendi){
		/* EXEC SQL DECLARE kcur CURSOR FOR
			SELECT kavram, count(kavram)
			FROM kavram
			WHERE daireno = :dresseddaire OR daireno=:nakeddaire
			GROUP BY kavram
			ORDER BY kavram; */ 

		;
	}else{
		/* EXEC SQL DECLARE kkendicur CURSOR FOR
			SELECT kavram, count(kavram)
			FROM kavram
			GROUP BY kavram
			ORDER BY kavram; */ 

		;	
	}
	if(kendi)/* EXEC SQL OPEN kcur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 3;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = sq0003;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )51;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlstm.sqhstv[0] = (         void  *)dresseddaire;
          sqlstm.sqhstl[0] = (unsigned int  )5;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         void  *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned int  )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (         void  *)nakeddaire;
          sqlstm.sqhstl[1] = (unsigned int  )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         void  *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned int  )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
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


	else /* EXEC SQL OPEN kkendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 3;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = sq0004;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )74;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if(SQL_ERROR || SQL_NOTFOUND){
               	yfquestion(SQL_MESSAGE);
		free(mbuf);
		free(mcount);
               	return 0;
       	}

	for(i=0; i < count; i++){
		if(kendi)/* EXEC SQL FETCH kcur INTO :kavram:ind0, :count1:ind2; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 3;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )89;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlstm.sqhstv[0] = (         void  *)kavram;
           sqlstm.sqhstl[0] = (unsigned int  )76;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)&ind0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned int  )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (         void  *)&count1;
           sqlstm.sqhstl[1] = (unsigned int  )4;
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         void  *)&ind2;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned int  )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
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


		else /* EXEC SQL FETCH kkendicur INTO :kavram:ind0, :count1:ind2; */ 

{
       struct sqlexd sqlstm;

       sqlstm.sqlvsn = 10;
       sqlstm.arrsiz = 3;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )112;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)0;
       sqlstm.sqhstv[0] = (         void  *)kavram;
       sqlstm.sqhstl[0] = (unsigned int  )76;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         void  *)&ind0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned int  )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (         void  *)&count1;
       sqlstm.sqhstl[1] = (unsigned int  )4;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         void  *)&ind2;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned int  )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
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
			free(mbuf);
			free(mcount);
               		return 0;
       		}
		mbuf[i]=strdup(kavram);
		mcount[i]=count1;
	}
	if(kendi)/* EXEC SQL CLOSE kcur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 3;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )135;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	else /* EXEC SQL CLOSE kkendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 3;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )150;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	yfmessage(" ");
	while(1){
		for(i=0; i<15;i++){
			strcpy(fkara->ifs[i].text,"");
			fkara->ifs[i].show = 1;
		}
		for(i = pointer;i<pointer+15;i++){
			if(i>=count){
				sprintf(fkara->ifs[i-pointer].text, "");
				fkara->ifs[i-pointer].show = 0;
			}else{
			sprintf(fkara->ifs[i-pointer].text,"%4u | ",mcount[i]);
			strncat(fkara->ifs[i-pointer].text,mbuf[i],60);
			}
		}
		sprintf(fkara->lines[0],
				"Kavram ile Arama          "
				"                                     "
				" Sayfa: %u/%u",pointer/15+1, (count-1)/15+1);
		sprintf(fkara->lines[1],
				"Daire: %s      ",kendi?daire:"tüm daireler");
			
		showform(fkara);
		outputform(fkara);
		stat = supermenu(fkara,stat);
		if(stat == 0xffff){
			pointer+=15;
			if(pointer>=count-1)pointer-=15;
			stat = 0;
			continue;
		}
		if(stat == 0xfffd){
			pointer-=15;
			if(pointer<0)pointer=0;
			stat = 0;
			continue;
		}
		if(stat == 0xfffc){
			dosetdaire();
			goto karabootstrap;
		}
		if(stat == 0xfffe)break;
		if(stat > 0xf000 && stat < (0xf000 + 0xfff)){
			quit = 0;
			for(i = 0; i <count;i++){
				if((unsigned char)mbuf[i][0]==(stat - 0xf000)){
					pointer = i - i%15;	
					quit = 1;
					break;
				}
			}
			if(quit)stat = i%15;
			else stat = 0;
			continue;
		}
		karagoster(mbuf[pointer+stat],kendi);
	}
	for(i = 0;i<count;i++)free(mbuf[i]);
	free(mbuf);
	free(mcount);
		
}
/*--------------------------------------------*/
karagoster(ikavram,kendi)
char *ikavram;
int kendi;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[4];
char esasno[10];
char kavram[76];
char dkavram[76];

char kmetin[1024*100];
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[4];
/* EXEC SQL END DECLARE SECTION; */ 


	int i, k;
	int quit = 0;
	int stat = 0;
	char **mbuf;
	char **mdaire;
	int pointer=0;
	char buf[100];

	strcpy(kavram, ikavram);
	dress(kavram,75);

	clearform(fkara1);

	dress(kavram,75);
        yfmessage("Lütfen bekleyiniz...");
	strcpy(nakeddaire,daire);
	strcpy(dresseddaire,daire);
	strip(nakeddaire);
	dress(dresseddaire,3);

	strip(kavram);
	strcpy(dkavram,kavram);
	dress(dkavram,75);
	if(kendi){
		/* EXEC SQL 
			SELECT count(esasno) INTO :count:ind1
			FROM kavram
			WHERE
			(daireno=:nakeddaire OR daireno = :dresseddaire) AND
		  	(kavram = :kavram OR kavram = :dkavram)
			ORDER BY esasno; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(esasno) into :b0:b1  from kavram where ((daire\
no=:b2 or daireno=:b3) and (kavram=:b4 or kavram=:b5)) order by esasno ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )165;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)nakeddaire;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)dresseddaire;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)kavram;
  sqlstm.sqhstl[3] = (unsigned int  )76;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)dkavram;
  sqlstm.sqhstl[4] = (unsigned int  )76;
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


		;
	}else{
		/* EXEC SQL 
			SELECT count(esasno) INTO :count:ind1
			FROM kavram
			WHERE
		  	(kavram = :kavram OR kavram = :dkavram)
			ORDER BY esasno; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(esasno) into :b0:b1  from kavram where (kavram\
=:b2 or kavram=:b3) order by esasno ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )200;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)kavram;
  sqlstm.sqhstl[1] = (unsigned int  )76;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)dkavram;
  sqlstm.sqhstl[2] = (unsigned int  )76;
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


		;
	}
        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
          	yfquestion(SQL_MESSAGE);
         	return 0;
  	}
      	if(SQL_NOTFOUND){
               	yfquestion("Hiçbir esas bulunmamýþtýr");
               	return 0;
       	}
	if((mbuf = (char**)malloc(count*sizeof(char*)))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	if((mdaire = (char**)malloc(count*sizeof(char*)))==NULL){
		yfquestion("Bellek yetersiz");
		free(mbuf);
		return 0;
	}
	if (kendi){
		/* EXEC SQL DECLARE kgkendicur CURSOR FOR
			SELECT esasno,daireno
			FROM kavram
			WHERE
				(daireno=:nakeddaire OR 
				daireno = :dresseddaire) AND
		  		(kavram = :kavram OR kavram = :dkavram)
			ORDER BY esasno; */ 

		;
	}else{
		/* EXEC SQL DECLARE kgcur CURSOR FOR
			SELECT esasno,daireno
			FROM kavram
			WHERE
		  		(kavram = :kavram OR kavram = :dkavram)
			ORDER BY esasno; */ 

		;
	}
	if(kendi)/* EXEC SQL OPEN kgkendicur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 5;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = sq0007;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )227;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlstm.sqhstv[0] = (         void  *)nakeddaire;
          sqlstm.sqhstl[0] = (unsigned int  )4;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         void  *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned int  )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (         void  *)dresseddaire;
          sqlstm.sqhstl[1] = (unsigned int  )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         void  *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned int  )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (         void  *)kavram;
          sqlstm.sqhstl[2] = (unsigned int  )76;
          sqlstm.sqhsts[2] = (         int  )0;
          sqlstm.sqindv[2] = (         void  *)0;
          sqlstm.sqinds[2] = (         int  )0;
          sqlstm.sqharm[2] = (unsigned int  )0;
          sqlstm.sqadto[2] = (unsigned short )0;
          sqlstm.sqtdso[2] = (unsigned short )0;
          sqlstm.sqhstv[3] = (         void  *)dkavram;
          sqlstm.sqhstl[3] = (unsigned int  )76;
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


	else /* EXEC SQL OPEN kgcur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = sq0008;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )258;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (         void  *)kavram;
      sqlstm.sqhstl[0] = (unsigned int  )76;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         void  *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned int  )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (         void  *)dkavram;
      sqlstm.sqhstl[1] = (unsigned int  )76;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         void  *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned int  )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
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
		ntlog(LOG_EMSAL, SQL_MESSAGE);
               	yfquestion(SQL_MESSAGE);
		free(mbuf);
		free(mdaire);
               	return 0;
       	}
	for(i=0; i < count; i++){
		if(kendi)/* EXEC SQL 
			FETCH kgkendicur INTO :esasno:ind0, :daireno:ind1; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )281;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlstm.sqhstv[0] = (         void  *)esasno;
           sqlstm.sqhstl[0] = (unsigned int  )10;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)&ind0;
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


		else /* EXEC SQL FETCH kgcur INTO :esasno:ind0, :daireno:ind1; */ 

{
       struct sqlexd sqlstm;

       sqlstm.sqlvsn = 10;
       sqlstm.arrsiz = 5;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )304;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)0;
       sqlstm.sqhstv[0] = (         void  *)esasno;
       sqlstm.sqhstl[0] = (unsigned int  )10;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         void  *)&ind0;
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
			ntlog(LOG_EMSAL, SQL_MESSAGE);
               		yfquestion(SQL_MESSAGE);
			free(mbuf);
			free(mdaire);
               		return 0;
       		}
		mbuf[i] = strdup(esasno);
		mdaire[i] = strdup(daireno);
	}
	if(kendi)/* EXEC SQL CLOSE kgkendicur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 5;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )327;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	else /* EXEC SQL CLOSE kgcur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )342;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	while(1){
		for(i=0; i<16;i++){
			strcpy(fkara1->ifs[i].text,"");
			fkara1->ifs[i].show = 1;
		}
		for(i = pointer;i<pointer+16;i++){
			if(i>=count){
				sprintf(fkara1->ifs[i-pointer].text, "");
				fkara1->ifs[i-pointer].show = 0;
			}else{
			sprintf(fkara1->ifs[i-pointer].text,"%3s | ",mdaire[i]);
			strncat(fkara1->ifs[i-pointer].text,mbuf[i],9);
			}
		}
		sprintf(fkara1->lines[0],
				"Kavram ile Arama          "
				"                                     "
				" Sayfa: %u/%u",pointer/16+1, (count-1)/16+1);
		sprintf(fkara1->lines[1],
				"Daire: %s      ",kendi?daire:"tüm daireler");
		strncpy(buf,kavram,40);
		buf[40]=0;
		strip(buf);
		if(strlen(buf)>40)strcat(buf,"...");
		sprintf(fkara1->lines[2],
				"Kavram: %s",buf);
		showform(fkara1);
		outputform(fkara1);
		stat = supermenu(fkara1,stat);
		if(stat == 0xffff){
			pointer+=16;
			if(pointer>=count-1)pointer-=16;
			stat = 0;
			continue;
		}
		if(stat == 0xfffd){
			pointer-=16;
			if(pointer<0)pointer=0;
			stat = 0;
			continue;
		}
		if(stat == 0xfffe)break;
		if(stat > 0xf000 && stat < (0xf000 + 0xff)){
			quit = 0;
			for(i = 0; i <count;i++){
				if((unsigned char)mbuf[i][0]==(stat - 0xf000)){
					pointer = i - i%16;	
					quit=1;
					break;
				}
			}
			if(quit)stat = i%16;
			else stat = 0;
			continue;
		}
		if(stat > 0xf000){stat=0;continue;}
		kgmetin(mbuf[pointer+stat], mdaire[pointer+stat]);
	}
	for(i = 0;i<count;i++){
		free(mbuf[i]);
		free(mdaire[i]);
	}
	free(mbuf);
	free(mdaire);
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------*/
int
kgmetin(iesas, idaire)
char *iesas;
char *idaire;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[5];
char esasno[10];
char kavram[76];

char kmetin[1024*100];
char kdaireno[5];
char kesasno[10];
char dkesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
char nakeddaire[5];
char dresseddaire[5];
/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(kesasno,iesas);
	strcpy(kdaireno,idaire);
	strcpy(dkesasno,kesasno);
	dress(dkesasno,9);
	strip(kesasno);
	strcpy(nakeddaire,kdaireno);
	strcpy(dresseddaire,kdaireno);
	strip(nakeddaire);
	/* it should be 4 !!!!!
	 * dunno why but it works with 3.
	 * a loosy code, I know it.
	 */
	dress(dresseddaire,3);
        yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL SELECT metin INTO :kmetin:ind0
		FROM karar
		WHERE
			(esasno = :kesasno OR esasno = :dkesasno) AND
			(daireno = :nakeddaire OR daireno = :dresseddaire)
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select metin into :b0:b1  from karar where ((esasno=:b2 or e\
sasno=:b3) and (daireno=:b4 or daireno=:b5))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )357;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)kmetin;
 sqlstm.sqhstl[0] = (unsigned int  )102400;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)kesasno;
 sqlstm.sqhstl[1] = (unsigned int  )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)dkesasno;
 sqlstm.sqhstl[2] = (unsigned int  )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)nakeddaire;
 sqlstm.sqhstl[3] = (unsigned int  )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)dresseddaire;
 sqlstm.sqhstl[4] = (unsigned int  )5;
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


        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
          	yfquestion(SQL_MESSAGE);
         	return 0;
  	}
       	if(SQL_NOTFOUND){
       		yfquestion(SQL_MESSAGE);
       		return 0;
  	}
	yfmessage(" ");
	
	yfmore(kmetin,"Devam etmek için RETURN ");
}
/*-------------------------------------------------------------
	        ************ kanun *************
-------------------------------------------------------------*/
int kanaragoster(char *ikanun);
int kanaragoster2(char *ikanun, char *madde);
int kangmetin(char *dno, char *iesas);

kanara()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[3];
char esasno[10];
char donem[2];
char madde[16];
char kanun[256];
long kanunno;

/*char kmetin[1024*100];
*/
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[4];
/* EXEC SQL END DECLARE SECTION; */ 


	char **mbuf;
	long *mcount;
	long *mkanunno;
	int i,k;
	int stat = 0;
	int quit = 0;
	int pointer;
	int kendi;

	nthareket("emsal: kanun arama");
kanarabootstrap:
	if(daire[0]=='t')kendi = 0;
	else kendi = 1;

	stat = quit = pointer = 0;
	clearform(fkanara);

	strcpy(nakeddaire,daire);
	strcpy(dresseddaire,daire);
	strip(nakeddaire);
	dress(dresseddaire,3);
        yfmessage("Lütfen bekleyiniz...");
	if(kendi){
		/* EXEC SQL SELECT COUNT(DISTINCT kanun) INTO :count:ind0
			FROM kanun
			WHERE (daireno = :dresseddaire OR
				daireno = :nakeddaire)
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct kanun) into :b0:b1  from kanun where \
(daireno=:b2 or daireno=:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )392;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)dresseddaire;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)nakeddaire;
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


	}else{
		/* EXEC SQL SELECT COUNT(DISTINCT kanun) INTO :count:ind0
			FROM kanun
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct kanun) into :b0:b1  from kanun ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )419;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
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


	}
        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
          	yfquestion(SQL_MESSAGE);
         	return 0;
  	}
      	if(SQL_NOTFOUND || count == 0){
               	yfquestion("Hiçbir kanun bulunmamýþtýr");
		strcpy(daire,"tüm");
               	return 0;
       	}
	if((mbuf = (char**)malloc(count*sizeof(char*)))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	if((mcount = (long*)malloc(count*sizeof(long)))==NULL){
		free(mbuf);
		yfquestion("Bellek yetersiz");
		return 0;
	}
	if((mkanunno = (long*)malloc(count*sizeof(long)))==NULL){
		free(mbuf);
		free(mcount);
		yfquestion("Bellek yetersiz");
		return 0;
	}

	if(kendi){
		/* EXEC SQL DECLARE kancur CURSOR FOR
			SELECT kanun, count(kanun), kanunno
			FROM kanun
			WHERE (daireno = :dresseddaire OR daireno=:nakeddaire)
			GROUP BY kanun,kanunno
			ORDER BY kanun
		; */ 

	}else{
		/* EXEC SQL DECLARE kankendicur CURSOR FOR
			SELECT kanun, count(kanun), kanunno
			FROM kanun
			GROUP BY kanun,kanunno
			ORDER BY kanun
		; */ 

	}
	if(kendi)/* EXEC SQL OPEN kancur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 5;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = sq0012;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )438;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlstm.sqhstv[0] = (         void  *)dresseddaire;
          sqlstm.sqhstl[0] = (unsigned int  )4;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         void  *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned int  )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (         void  *)nakeddaire;
          sqlstm.sqhstl[1] = (unsigned int  )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         void  *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned int  )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
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


	else /* EXEC SQL OPEN kankendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = sq0013;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )461;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if(SQL_ERROR || SQL_NOTFOUND){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
		free(mbuf);
		free(mcount);
		free(mkanunno);
               	yfquestion(SQL_MESSAGE);
               	return 0;
       	}
	for(i = 0; i < count; i++){
		if(kendi)/* EXEC SQL FETCH kancur INTO :kanun:ind0, :count1:ind2,
					:kanunno:ind3; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )476;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlstm.sqhstv[0] = (         void  *)kanun;
           sqlstm.sqhstl[0] = (unsigned int  )256;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)&ind0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned int  )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (         void  *)&count1;
           sqlstm.sqhstl[1] = (unsigned int  )4;
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         void  *)&ind2;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned int  )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (         void  *)&kanunno;
           sqlstm.sqhstl[2] = (unsigned int  )4;
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         void  *)&ind3;
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


		else /* EXEC SQL FETCH kankendicur INTO :kanun:ind0, :count1:ind2,
					:kanunno:ind3; */ 

{
       struct sqlexd sqlstm;

       sqlstm.sqlvsn = 10;
       sqlstm.arrsiz = 5;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )503;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)0;
       sqlstm.sqhstv[0] = (         void  *)kanun;
       sqlstm.sqhstl[0] = (unsigned int  )256;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         void  *)&ind0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned int  )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (         void  *)&count1;
       sqlstm.sqhstl[1] = (unsigned int  )4;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         void  *)&ind2;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned int  )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (         void  *)&kanunno;
       sqlstm.sqhstl[2] = (unsigned int  )4;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         void  *)&ind3;
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


        	if(SQL_ERROR || SQL_NOTFOUND){
			ntlog(LOG_EMSAL, SQL_MESSAGE);
			free(mbuf);
			free(mcount);
			free(mkanunno);
               		yfquestion(SQL_MESSAGE);
               		return 0;
		}
		mbuf[i] = strdup(kanun);
		mcount[i] = count1;
		mkanunno[i] = kanunno;
	}
	if(kendi) /* EXEC SQL CLOSE kancur; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )530;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	else /* EXEC SQL CLOSE kankendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )545;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	while(1){
		for(i=0; i<15;i++){
			strcpy(fkanara->ifs[i].text,"");
			fkanara->ifs[i].show = 1;
		}
		for(i = pointer; i < pointer + 15; i++){
			if(i >= count){
				strcpy(fkanara->ifs[i-pointer].text,"");
				fkanara->ifs[i-pointer].show = 0;
			}else{
			sprintf(fkanara->ifs[i-pointer].text,
				"%4u | %8u | ",mcount[i], mkanunno[i]);
			strncat(fkanara->ifs[i-pointer].text,mbuf[i],57);
			}
		}
		sprintf(fkanara->lines[0],
				"Kanun ile Arama          "
				"                                     "
				" Sayfa: %u/%u",pointer/15+1, (count-1)/15+1);
		sprintf(fkanara->lines[1],
				"Daire: %s      ",kendi?daire:"tüm daireler");
		showform(fkanara);
		outputform(fkanara);
		stat = supermenu(fkanara,stat);
		if(stat == 0xffff){
			pointer+=15;
			if(pointer>=count-1)pointer-=15;
			stat = 0;
			continue;
		}
		if(stat == 0xfffd){
			pointer-=15;
			if(pointer<0)pointer=0;
			stat = 0;
			continue;
		}
		if(stat == 0xfffc){
			dosetdaire();
			goto kanarabootstrap;
		}
		if(stat == 0xfffe)break;
		if(stat > 0xf000 && stat < (0xf000 + 0xfff)){
			quit = 0;
			for(i = 0; i <count;i++){
				if((unsigned char)mbuf[i][0]==(stat - 0xf000)){
					pointer = i - i%15;	
					quit = 1;
					break;
				}
			}
			if(quit)stat = i%15;
			else stat = 0;
			continue;
		}
		kanaragoster(mbuf[pointer+stat]);
	}
	for(i = 0;i<count;i++)free(mbuf[i]);
	free(mbuf);
	free(mcount);
}
/*--------------------------------------------*/
kanaragoster(ikanun)
char *ikanun;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[3];
char esasno[10];
char donem[2];
char madde[16];
char kanun[256];

/*
char kmetin[1024*100];
*/
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[4];
char buf[256];
/* EXEC SQL END DECLARE SECTION; */ 


	char **mbuf;
	long *mcount;
	int i,k;
	int stat = 0;
	int quit = 0;
	int pointer;
	int kendi;

	strcpy(kanun, ikanun);
	kanun[255]=0;

kangarabootstrap:
	if(daire[0]=='t')kendi = 0;
	else kendi = 1;

	stat = quit = pointer = 0;
	clearform(fkanara);

	strcpy(nakeddaire,daire);
	strcpy(dresseddaire,daire);
	strip(nakeddaire);
	dress(dresseddaire,3);
        yfmessage("Lütfen bekleyiniz...");
	if(kendi){
		/* EXEC SQL SELECT COUNT(DISTINCT madde) INTO :count:ind0
			FROM kanun
			WHERE (daireno = :dresseddaire OR
				daireno = :nakeddaire)
				AND kanun = :kanun
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct madde) into :b0:b1  from kanun where \
((daireno=:b2 or daireno=:b3) and kanun=:b4)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )560;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)dresseddaire;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)nakeddaire;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)kanun;
  sqlstm.sqhstl[3] = (unsigned int  )256;
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


	}else{
		/* EXEC SQL SELECT COUNT(DISTINCT madde) INTO :count:ind0
			FROM kanun
			WHERE kanun = :kanun
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct madde) into :b0:b1  from kanun where \
kanun=:b2";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )591;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)kanun;
  sqlstm.sqhstl[1] = (unsigned int  )256;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
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


	}
        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
          	yfquestion(SQL_MESSAGE);
         	return 0;
  	}
      	if(SQL_NOTFOUND || count == 0){
               	yfquestion("Bu kanunla ilgili hiçbir madde bulunmamýþtýr");
		strcpy(daire,"tüm");
               	return 0;
       	}
	if((mbuf = (char**)malloc(count*sizeof(char*)))==NULL){
		yfquestion("Bellek yetersiz");
		return 0;
	}
	if((mcount = (long*)malloc(count*sizeof(long)))==NULL){
		free(mbuf);
		yfquestion("Bellek yetersiz");
		return 0;
	}

	if(kendi){
		/* EXEC SQL DECLARE kangcur CURSOR FOR
			SELECT madde, count(madde)
			FROM kanun
			WHERE 
				(daireno = :dresseddaire OR daireno=:nakeddaire)
				AND
				kanun = :kanun
			GROUP BY madde
			ORDER BY madde
		; */ 

	}else{
		/* EXEC SQL DECLARE kangkendicur CURSOR FOR
			SELECT madde, count(madde)
			FROM kanun
			WHERE kanun = :kanun
			GROUP BY madde
			ORDER BY madde
		; */ 

	}
	if(kendi)/* EXEC SQL OPEN kangcur; */ 

{
          struct sqlexd sqlstm;

          sqlstm.sqlvsn = 10;
          sqlstm.arrsiz = 5;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = sq0016;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )614;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)0;
          sqlstm.sqhstv[0] = (         void  *)dresseddaire;
          sqlstm.sqhstl[0] = (unsigned int  )4;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         void  *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned int  )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (         void  *)nakeddaire;
          sqlstm.sqhstl[1] = (unsigned int  )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         void  *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned int  )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (         void  *)kanun;
          sqlstm.sqhstl[2] = (unsigned int  )256;
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


	else /* EXEC SQL OPEN kangkendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = sq0017;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )641;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (         void  *)kanun;
      sqlstm.sqhstl[0] = (unsigned int  )256;
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
		ntlog(LOG_EMSAL, SQL_MESSAGE);
		free(mbuf);
		free(mcount);
               	yfquestion(SQL_MESSAGE);
               	return 0;
       	}
	for(i = 0; i < count; i++){
		if(kendi)/* EXEC SQL FETCH kangcur INTO :madde:ind0, :count1:ind2; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )660;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlstm.sqhstv[0] = (         void  *)madde;
           sqlstm.sqhstl[0] = (unsigned int  )16;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)&ind0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned int  )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (         void  *)&count1;
           sqlstm.sqhstl[1] = (unsigned int  )4;
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         void  *)&ind2;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned int  )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
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


		else /* EXEC SQL FETCH kangkendicur INTO :madde:ind0, :count1:ind2; */ 

{
       struct sqlexd sqlstm;

       sqlstm.sqlvsn = 10;
       sqlstm.arrsiz = 5;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )683;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)0;
       sqlstm.sqhstv[0] = (         void  *)madde;
       sqlstm.sqhstl[0] = (unsigned int  )16;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         void  *)&ind0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned int  )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (         void  *)&count1;
       sqlstm.sqhstl[1] = (unsigned int  )4;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         void  *)&ind2;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned int  )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
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
			ntlog(LOG_EMSAL, SQL_MESSAGE);
			free(mbuf);
			free(mcount);
               		yfquestion(SQL_MESSAGE);
               		return 0;
		}
		mbuf[i] = strdup(madde);
		mcount[i] = count1;
	}
	if(kendi) /* EXEC SQL CLOSE kangcur; */ 

{
           struct sqlexd sqlstm;

           sqlstm.sqlvsn = 10;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )706;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)0;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	else /* EXEC SQL CLOSE kangkendicur; */ 

{
      struct sqlexd sqlstm;

      sqlstm.sqlvsn = 10;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )721;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	while(1){
		for(i=0; i<16;i++){
			strcpy(fkanara1->ifs[i].text,"");
			fkanara1->ifs[i].show = 1;
		}
		for(i = pointer; i < pointer + 16; i++){
			if(i >= count){
				strcpy(fkanara1->ifs[i-pointer].text,"");
				fkanara1->ifs[i-pointer].show = 0;
			}else{
			sprintf(fkanara1->ifs[i-pointer].text,
				"%3u | %s",mcount[i],mbuf[i]);
			}
		}
		sprintf(fkanara1->lines[0],
				"Kanun ile Arama          "
				"                                     "
				" Sayfa: %u/%u",pointer/16+1, (count-1)/16+1);
		sprintf(fkanara1->lines[1],
				"Daire: %s      ",kendi?daire:"tüm daireler");
		strncpy(buf,kanun,40);
		buf[40]=0;
		if(strlen(kanun)>40)strcat(buf,"...");
		sprintf(fkanara1->lines[2],
				"Kanun: %s",buf);
		showform(fkanara1);
		outputform(fkanara1);
		stat = supermenu(fkanara1,stat);
		if(stat == 0xffff){
			pointer+=16;
			if(pointer>=count-1)pointer-=16;
			stat = 0;
			continue;
		}
		if(stat == 0xfffd){
			pointer-=16;
			if(pointer<0)pointer=0;
			stat = 0;
			continue;
		}
		if(stat == 0xfffc){
			/*dosetdaire();
			goto kangarabootstrap;*/
			stat = 0;
			continue;
		}
		if(stat == 0xfffe)break;
		if(stat > 0xf000 && stat < (0xf000 + 0xfff)){
			quit = 0;
			for(i = 0; i <count;i++){
				if((unsigned char)mbuf[i][0]==(stat - 0xf000)){
					pointer = i - i%16;	
					quit = 1;
					break;
				}
			}
			if(quit)stat = i%16;
			else stat = 0;
			continue;
		}
		kanaragoster2(kanun,mbuf[pointer+stat]);
	}
	for(i = 0;i<count;i++)free(mbuf[i]);
	free(mbuf);
	free(mcount);

}
/*--------------------------------------------*/
kanaragoster2(ikanun,imadde)
char *ikanun;
char *imadde;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[4];
char esasno[10];
char donem[2];
char madde[16];
char kanun[256];

char kmetin[1024*100];
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[4];
char buf[256];
/* EXEC SQL END DECLARE SECTION; */ 


	int i, k;
	int quit = 0;
	int stat = 0;
	int pointer;
	char **mbuf;
	char **mbuf1;
	int kendi;

	strcpy(kanun, ikanun);
	strcpy(madde, imadde);
	/*dress(kanun,255);*/

k2bootstrap:
	if(daire[0]=='t') kendi = 0;
	else kendi = 1;

	stat = quit = pointer = 0;
	showform(fkanara2);
	clearform(fkanara2);

        yfmessage("Lütfen bekleyiniz...");
	strcpy(nakeddaire,daire);
	strcpy(dresseddaire,daire);
	strip(nakeddaire);
	dress(dresseddaire,3);
        yfmessage("Lütfen bekleyiniz...");
	if(kendi){
		/* EXEC SQL SELECT COUNT(DISTINCT esasno) INTO :count:ind0
			FROM kanun
			WHERE
				(daireno=:nakeddaire OR 
				 daireno = :dresseddaire) AND
		  		kanun = :kanun AND
		  		madde = :madde
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct esasno) into :b0:b1  from kanun where\
 (((daireno=:b2 or daireno=:b3) and kanun=:b4) and madde=:b5)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )736;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)nakeddaire;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)dresseddaire;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)kanun;
  sqlstm.sqhstl[3] = (unsigned int  )256;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)madde;
  sqlstm.sqhstl[4] = (unsigned int  )16;
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


	}else{
		/* EXEC SQL SELECT COUNT(DISTINCT esasno) INTO :count:ind0
			FROM kanun
			WHERE
		  		kanun = :kanun AND
		  		madde = :madde
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(distinct esasno) into :b0:b1  from kanun where\
 (kanun=:b2 and madde=:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )771;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&count;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)kanun;
  sqlstm.sqhstl[1] = (unsigned int  )256;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)madde;
  sqlstm.sqhstl[2] = (unsigned int  )16;
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


	}
        if(SQL_ERROR){
		ntlog(LOG_EMSAL, SQL_MESSAGE);
                yfquestion(SQL_MESSAGE);
                return 0;
        }
        if(SQL_NOTFOUND || count == 0){
                yfquestion(
		  "Bu kanunla ve madde ile ilgili hiçbir madde bulunmamýþtýr");
                strcpy(daire,"tüm");
                return 0;
        }
        if((mbuf = (char**)malloc(count*sizeof(char*)))==NULL){
                yfquestion("Bellek yetersiz");
                return 0;
        }
        if((mbuf1 = (char**)malloc(count*sizeof(char*)))==NULL){
		free(mbuf);
                yfquestion("Bellek yetersiz");
                return 0;
        }
	if(kendi){
		/* EXEC SQL DECLARE kang2kendicur CURSOR FOR
			SELECT esasno, daireno 
			FROM kanun
			WHERE
				(daireno=:nakeddaire OR 
				 daireno = :dresseddaire) AND
		  		kanun = :kanun AND
		  		madde = :madde
		; */ 

	}else{
		/* EXEC SQL DECLARE kang2cur CURSOR FOR
			SELECT esasno, daireno
			FROM kanun
			WHERE
		  		kanun = :kanun AND
		  		madde = :madde
		; */ 

	}
        if(kendi)/* EXEC SQL OPEN kang2kendicur; */ 

{
                 struct sqlexd sqlstm;

                 sqlstm.sqlvsn = 10;
                 sqlstm.arrsiz = 5;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.stmt = sq0020;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )798;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)0;
                 sqlstm.sqhstv[0] = (         void  *)nakeddaire;
                 sqlstm.sqhstl[0] = (unsigned int  )4;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         void  *)0;
                 sqlstm.sqinds[0] = (         int  )0;
                 sqlstm.sqharm[0] = (unsigned int  )0;
                 sqlstm.sqadto[0] = (unsigned short )0;
                 sqlstm.sqtdso[0] = (unsigned short )0;
                 sqlstm.sqhstv[1] = (         void  *)dresseddaire;
                 sqlstm.sqhstl[1] = (unsigned int  )4;
                 sqlstm.sqhsts[1] = (         int  )0;
                 sqlstm.sqindv[1] = (         void  *)0;
                 sqlstm.sqinds[1] = (         int  )0;
                 sqlstm.sqharm[1] = (unsigned int  )0;
                 sqlstm.sqadto[1] = (unsigned short )0;
                 sqlstm.sqtdso[1] = (unsigned short )0;
                 sqlstm.sqhstv[2] = (         void  *)kanun;
                 sqlstm.sqhstl[2] = (unsigned int  )256;
                 sqlstm.sqhsts[2] = (         int  )0;
                 sqlstm.sqindv[2] = (         void  *)0;
                 sqlstm.sqinds[2] = (         int  )0;
                 sqlstm.sqharm[2] = (unsigned int  )0;
                 sqlstm.sqadto[2] = (unsigned short )0;
                 sqlstm.sqtdso[2] = (unsigned short )0;
                 sqlstm.sqhstv[3] = (         void  *)madde;
                 sqlstm.sqhstl[3] = (unsigned int  )16;
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


        else /* EXEC SQL OPEN kang2cur; */ 

{
             struct sqlexd sqlstm;

             sqlstm.sqlvsn = 10;
             sqlstm.arrsiz = 5;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = sq0021;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )829;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)0;
             sqlstm.sqhstv[0] = (         void  *)kanun;
             sqlstm.sqhstl[0] = (unsigned int  )256;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)madde;
             sqlstm.sqhstl[1] = (unsigned int  )16;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
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
		ntlog(LOG_EMSAL, SQL_MESSAGE);
                free(mbuf);
                yfquestion(SQL_MESSAGE);
                return 0;
        }
	for(i = 0; i < count; i++){
		if(kendi)
			/* EXEC SQL FETCH kang2kendicur 
				INTO :esasno:ind1, :daireno:ind2; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )852;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)esasno;
   sqlstm.sqhstl[0] = (unsigned int  )10;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)&ind1;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)daireno;
   sqlstm.sqhstl[1] = (unsigned int  )4;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)&ind2;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
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


		else
			/* EXEC SQL FETCH kang2cur 
				INTO :esasno:ind1, :daireno:ind2; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )875;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)esasno;
   sqlstm.sqhstl[0] = (unsigned int  )10;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)&ind1;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)daireno;
   sqlstm.sqhstl[1] = (unsigned int  )4;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)&ind2;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
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
			ntlog(LOG_EMSAL, SQL_MESSAGE);
                        free(mbuf);
			free(mbuf1);
                        yfquestion(SQL_MESSAGE);
                        return 0;
                }
                mbuf[i] = strdup(esasno);
		mbuf1[i] = strdup(daireno);
	}

        if(kendi) /* EXEC SQL CLOSE kang2kendicur; */ 

{
                  struct sqlexd sqlstm;

                  sqlstm.sqlvsn = 10;
                  sqlstm.arrsiz = 5;
                  sqlstm.sqladtp = &sqladt;
                  sqlstm.sqltdsp = &sqltds;
                  sqlstm.iters = (unsigned int  )1;
                  sqlstm.offset = (unsigned int  )898;
                  sqlstm.cud = sqlcud0;
                  sqlstm.sqlest = (unsigned char  *)&sqlca;
                  sqlstm.sqlety = (unsigned short)0;
                  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        else /* EXEC SQL CLOSE kang2cur; */ 

{
             struct sqlexd sqlstm;

             sqlstm.sqlvsn = 10;
             sqlstm.arrsiz = 5;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )913;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)0;
             sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	while(1){
                for(i=0; i<16;i++){
                        strcpy(fkanara2->ifs[i].text,"");
                        fkanara2->ifs[i].show = 1;
                }
                for(i = pointer; i < pointer + 16; i++){
                        if(i >= count){
                                strcpy(fkanara2->ifs[i-pointer].text,"");
                                fkanara2->ifs[i-pointer].show = 0;
                        }else{
                        sprintf(fkanara2->ifs[i-pointer].text,
                                "%s",mbuf[i]);
                        }
                }
                sprintf(fkanara2->lines[0],
                                "Kanun ile Arama          "
                                "                                     "
                                " Sayfa: %u/%u",pointer/16+1, (count-1)/16+1);
                sprintf(fkanara2->lines[1],
                                "Daire: %s      ",kendi?daire:"tüm daireler");
		strncpy(buf,kanun,40);
		buf[40]=0;
		if(strlen(kanun)>40)strcat(buf,"...");
		sprintf(fkanara2->lines[2],
				"Kanun: %s",buf);
		sprintf(fkanara2->lines[3],"Madde: %s",madde);
                showform(fkanara2);
                outputform(fkanara2);
                stat = supermenu(fkanara2,stat);
                if(stat == 0xffff){
                        pointer+=16;
                        if(pointer>=count-1)pointer-=16;
                        stat = 0;
                        continue;
                }
                if(stat == 0xfffd){
                        pointer-=16;
                        if(pointer<0)pointer=0;
                        stat = 0;
                        continue;
                }
                if(stat == 0xfffc){
                        stat = 0;
                        continue;
                }
                if(stat == 0xfffe)break;
                if(stat > 0xf000 && stat < (0xf000 + 0xfff)){
                        quit = 0;
                        for(i = 0; i <count;i++){
                                if((unsigned char)mbuf[i][0]==(stat - 0xf000)){
                                        pointer = i - i%16;
                                        quit = 1;
                                        break;
                                }
                        }
                        if(quit)stat = i%16;
                        else stat = 0;
                        continue;
                }
		kangmetin(mbuf1[stat],mbuf[stat+pointer]);
        }
        for(i = 0;i<count;i++){
		free(mbuf[i]);
		free(mbuf1[i]);
	}
        free(mbuf);
	free(mbuf1);
	return 1;
}
/*--------------------------------------------*/
int
kangmetin(dno,iesas)
char *dno;
char *iesas;
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[3];
char esasno[10];
char kavram[76];

char kmetin[1024*100];
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
char nakeddaire[5];
char dresseddaire[5];
char dno1[10];
/* EXEC SQL END DECLARE SECTION; */ 

	int kendi;

	strcpy(nakeddaire,dno);
	strcpy(dresseddaire,dno);
	dress(dresseddaire,4);
	strcpy(kesasno,iesas);
        yfmessage("Lütfen bekleyiniz...");
		/* EXEC SQL SELECT metin INTO :kmetin:ind0
			FROM karar
			WHERE
				(daireno=:dresseddaire OR
				daireno=:nakeddaire)  AND
				esasno = :kesasno
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select metin into :b0:b1  from karar where ((daireno=:b2 or\
 daireno=:b3) and esasno=:b4)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )928;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)kmetin;
  sqlstm.sqhstl[0] = (unsigned int  )102400;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)dresseddaire;
  sqlstm.sqhstl[1] = (unsigned int  )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)nakeddaire;
  sqlstm.sqhstl[2] = (unsigned int  )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)kesasno;
  sqlstm.sqhstl[3] = (unsigned int  )10;
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


        		if(SQL_ERROR){
				ntlog(LOG_EMSAL, SQL_MESSAGE);
          			yfquestion(SQL_MESSAGE);
         			return 0;
  			}
        		if(SQL_NOTFOUND){
          			yfquestion("Dosya bulunamadý");
         			return 0;
  			}
	yfmessage(" ");
	
	yfmore(kmetin,"Devam etmek için RETURN ");
}
/*-----------------------------------------------------------
-----------------------------------------------------------*/
dosetdaire()
{
	int stat;
	
	clearform(setdaire);
	showform(setdaire);
	
	strcpy(setdaire->ifs[0].text,"tüm daireler");
	strcpy(setdaire->ifs[1].text,"1c");
	strcpy(setdaire->ifs[2].text,"2c");
	strcpy(setdaire->ifs[3].text,"3c");
	strcpy(setdaire->ifs[4].text,"4c");
	strcpy(setdaire->ifs[5].text,"5c");
	strcpy(setdaire->ifs[6].text,"6c");
	strcpy(setdaire->ifs[7].text,"7c");
	strcpy(setdaire->ifs[8].text,"8c");
	strcpy(setdaire->ifs[9].text,"9c");
	strcpy(setdaire->ifs[10].text,"10c");
	strcpy(setdaire->ifs[11].text,"11c");
	strcpy(setdaire->ifs[12].text,"1h");
	strcpy(setdaire->ifs[13].text,"2h");
	strcpy(setdaire->ifs[14].text,"3h");
	strcpy(setdaire->ifs[15].text,"4h");
	strcpy(setdaire->ifs[16].text,"5h");
	strcpy(setdaire->ifs[17].text,"6h");
	strcpy(setdaire->ifs[18].text,"7h");
	strcpy(setdaire->ifs[19].text,"8h");
	strcpy(setdaire->ifs[20].text,"9h");
	strcpy(setdaire->ifs[21].text,"10h");
	strcpy(setdaire->ifs[22].text,"11h");
	strcpy(setdaire->ifs[23].text,"12h");
	strcpy(setdaire->ifs[24].text,"13h");
	strcpy(setdaire->ifs[25].text,"14h");
	strcpy(setdaire->ifs[26].text,"15h");
	strcpy(setdaire->ifs[27].text,"16h");
	strcpy(setdaire->ifs[28].text,"17h");
	strcpy(setdaire->ifs[29].text,"18h");
	strcpy(setdaire->ifs[30].text,"19h");
	strcpy(setdaire->ifs[31].text,"20h");
	strcpy(setdaire->ifs[32].text,"21h");
	strcpy(setdaire->ifs[33].text,"cgk");
	strcpy(setdaire->ifs[34].text,"hgk");
	strcpy(setdaire->ifs[35].text,"yik");
	outputform(setdaire);
	for(stat = 35;stat > 0;stat--){
		if(strncmp(daire,setdaire->ifs[stat].text,
			strlen(setdaire->ifs[stat].text))==0)break;
	}
	while(1){
		outputform(setdaire);
		stat = supermenu(setdaire,stat);
		if (stat == 0xfffe)break;
		if (stat < 0xf000){
			strcpy(daire,setdaire->ifs[stat].text);
			break;
		}
		if(stat == 0xffff){
			stat = 35;
			/*stat = 0;*/
			continue;
		}
		stat = 0;
	}
}
/*-----------------------------------------------------------
-----------------------------------------------------------*/
int
esasara()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[3];
char esasno[10];
char kavram[76];

char kmetin[1024*100];
char kdaireno[4];
char kesasno[10];
char kkararno[9];
char ktarih[11];
char kgiristar[11];
char kdergi[2];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
char nakeddaire[5];
char dresseddaire[5];
char dno1[10];
/* EXEC SQL END DECLARE SECTION; */ 


	int stat = 0;
	char buf[20];



	clearform(esara);
	showform(esara);
	stat = superinputform(esara, 0);
	if ( stat == 0 )return 1;
	strcpy(buf,esara->ifs[1].text);
	dress(buf,9);
	kangmetin(esara->ifs[0].text, buf);
	return 0;
}
