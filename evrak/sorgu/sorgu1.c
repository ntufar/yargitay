
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
    "sorgu1.pc"
};


static unsigned long sqlctx = 41043;


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
            void  *sqhstv[14];
   unsigned int   sqhstl[14];
            int   sqhsts[14];
            void  *sqindv[14];
            int   sqinds[14];
   unsigned int   sqharm[14];
   unsigned int   *sqharc[14];
   unsigned short  sqadto[14];
   unsigned short  sqtdso[14];
} sqlstm = {10,14};

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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4114,0,0,0,
5,0,0,1,0,0,17,202,0,0,1,1,0,1,0,1,5,0,0,
24,0,0,1,0,0,45,214,0,0,0,0,0,1,0,
39,0,0,1,0,0,13,227,0,0,14,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
110,0,0,1,0,0,15,235,0,0,0,0,0,1,0,
125,0,0,2,191,0,4,279,0,0,5,1,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,3,0,0,
160,0,0,1,0,0,17,535,0,0,1,1,0,1,0,1,5,0,0,
179,0,0,1,0,0,45,547,0,0,0,0,0,1,0,
194,0,0,1,0,0,13,560,0,0,13,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,
3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
261,0,0,1,0,0,15,567,0,0,0,0,0,1,0,
276,0,0,3,283,0,4,613,0,0,7,3,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,5,0,0,1,
5,0,0,1,3,0,0,
};


#include <stdio.h>
#include <string.h>
#include "yf.h"
#include "sorgu.h"

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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int cezasor()
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
	static int ilkkez = 1;
	int returnvalue = 0;




	nthareket("sorgu: ceza sorgu");
yenidensor:
	clearform(csor);
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
        csor->ifs[0].edit = 1;
	outputform(csor);

	i = inputform(csor);
	if(i == 0)return 0;
	strcpy(daireno,		csor->ifs[0].text);
	strcpy(esassirayil,	csor->ifs[1].text);
	strcpy(esassirano,	csor->ifs[2].text);
	strcpy(geldigitarih,	csor->ifs[3].text);
	strcpy(tebligtarih,	csor->ifs[4].text);
	strcpy(tebligmasa,	csor->ifs[5].text);
	strcpy(tebligno,	csor->ifs[6].text);
	strcpy(esasno,		csor->ifs[7].text);
	strcpy(kararno,		csor->ifs[8].text);
	strcpy(gonderenmahkeme,	csor->ifs[9].text);
	strcpy(sucunturu,	csor->ifs[10].text);
	strcpy(temyizeden,	csor->ifs[11].text);
	strcpy(tutuklu,		csor->ifs[12].text);
	

        strcpy(buf,"select "
                "daireno, esassirayil, esassirano, geldigitarih,"
                "tebligtarih, tebligmasa, tebligno, esasno,"
                "kararno, gonderenmahkeme, sucunturu,"
                "temyizeden, tutuklu, "
		"kararsonucu "
                "from ceza.gelendosya "); 
	/***********************/
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
        if(tebligtarih[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," tebligtarih = '");
                strcat(buf,quote(tebligtarih));
                strcat(buf,"'");
        }
        if(tebligmasa[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," tebligmasa like '");
                strcat(buf,quote(tebligmasa));
                strcat(buf,"%'");
        }
        if(tebligno[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," tebligno =");
                strcat(buf,tebligno);
        }
        if(esasno[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," esasno =");
                strcat(buf,esasno);
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
        if(sucunturu[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," sucunturu like '");
                strcat(buf,quote(sucunturu));
                strcat(buf,"%'");
        }
        if(temyizeden[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," temyizeden like '");
                strcat(buf,quote(temyizeden));
                strcat(buf,"%'");
        }
        if(tutuklu[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," tutuklu like '");
                strcat(buf,quote(tutuklu));
                strcat(buf,"%'");
        }


	/* EXEC SQL PREPARE s1 FROM :buf; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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


	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "ceza_sorgu.SQL_PREPARE_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	/* EXEC SQL declare cur cursor for s1; */ 

	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "ceza_sorgu.SQL_DECLARE_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	/* EXEC SQL OPEN cur ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "ceza_sorgu.SQL_OPEN_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}

while(1){
	csor->ifs[13].text[0]=0;
	csor->ifs[14].text[0]=0;
	csor->ifs[15].text[0]=0;
	csor->ifs[16].text[0]=0;
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL FETCH cur INTO
		:daireno:ind1, :esassirayil:ind2, :essno:ind3,
		:geldigitarih:ind4, :tebligtarih:ind5, :tebligmasa:ind6,
		:tblno:ind7, :esno:ind8, :karno:ind9,
		:gonderenmahkeme:ind10, :sucunturu:ind11,
		:temyizeden:ind12, :tutuklu:ind13, :p_kararsonucu:ind14
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
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


	if (SQL_NOTFOUND){
		/* EXEC SQL CLOSE cur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )110;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(ilkkez){
			yfquestion("Dosya bulunamadý");
			break;
		}
		yfquestion("Son kayýt. Devam için bir tuþa basýnýz");
		returnvalue = 1;
		break;
	} 
	ilkkez = 0;
	if(SQL_ERROR){
		ntlog(LOG_SORGU, SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	clearform(csor);

	if(ind1 >= 0) strncpy(csor->ifs[0].text,daireno,90);
	else csor->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(csor->ifs[1].text,esassirayil,90);
	else csor->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(csor->ifs[2].text,"%u",essno);
	else csor->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(csor->ifs[3].text,geldigitarih,90);
	else csor->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(csor->ifs[4].text,tebligtarih,90);
	else csor->ifs[4].text[0]=0;
	if(ind6 >= 0) strncpy(csor->ifs[5].text,tebligmasa,90);
	else csor->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(csor->ifs[6].text,"%u",tblno);
	else csor->ifs[6].text[0]=0;
	if(ind8 >= 0) sprintf(csor->ifs[7].text,"%u",esno);
	else csor->ifs[7].text[0]=0;
	if(ind9 >= 0) sprintf(csor->ifs[8].text,"%u",karno);
	else csor->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(csor->ifs[9].text,gonderenmahkeme,90);
	else csor->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(csor->ifs[10].text,sucunturu,90);
	else csor->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(csor->ifs[11].text,temyizeden,90);
	else csor->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(csor->ifs[12].text,tutuklu,90);
	else csor->ifs[12].text[0]=0;
	if(p_kararsonucu != 0){
	/* EXEC SQL SELECT 
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi
	INTO 	
		:skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7
	FROM ceza.kararsonucu	
	WHERE
		kararsonucu.id = :p_kararsonucu; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select kararsonucu.karsonucu ,kararsonucu.karartarihi ,karar\
sonucu.kararnumarasi ,kararsonucu.gonderilistarihi into :b0:b1,:b2:b3,:b4:b5,:\
b6:b7  from ceza.kararsonucu where kararsonucu.id=:b8";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )125;
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



	}
	/* simdi sonuc var mi bakalim... */
	/*EXEC SQL SELECT 
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi
	INTO 	
		:skararsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7

	FROM ceza.kararsonucu,ceza.gelendosya
	WHERE
		
		kararsonucu.daireno = :daireno AND 
		kararsonucu.esassirayil = :esassirayil AND
		kararsonucu.esassirano = :essno	

	;*/
	/***************************************************/

	csor->ifs[13].text[0]=0;
	csor->ifs[14].text[0]=0;
	csor->ifs[15].text[0]=0;
	csor->ifs[16].text[0]=0;

	if (p_kararsonucu == 0 || SQL_NOTFOUND){
		strcpy(csor->ifs[13].text,"Bu dosya sonuca baðlanmamýþtýr");
		csor->ifs[14].text[0]=0;
		csor->ifs[15].text[0]=0;
		csor->ifs[16].text[0]=0;
	}else{
	if(sind4 >= 0) strncpy(csor->ifs[13].text,skararsonucu,90);
	else csor->ifs[13].text[0]=0;
	if(sind5 >= 0) strncpy(csor->ifs[14].text,skarartarihi,90);
	else csor->ifs[14].text[0]=0;
	if(sind6 >= 0) sprintf(csor->ifs[15].text,"%u",skararnumarasi,90);
	else csor->ifs[15].text[0]=0;
	if(sind7 >= 0) strncpy(csor->ifs[16].text,sgonderilistarihi,90);
	else csor->ifs[16].text[0]=0;
	}

	outputform(csor);
	i = yfquestion("Sonraki kaydý görmek için herhangi bir tuþa basýnýz."
			" Çýkmak için x basýnýz");
	if(i == 'x' || i == 'X') break;
}
return returnvalue;

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int hukuksor()
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


	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

	long esssno;
	long essno;
	long karno;

	char buf[1000];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	int waswhere = 0;
	static int ilkkez = 1;
	int returnvalue = 0;



	nthareket("sorgu: hukuk sorgu");
yenidensor:
	hsor->ifs[0].edit = 1;
	hsor->ifs[1].edit = 1;
	hsor->ifs[2].edit = 1;
	hsor->ifs[3].edit = 1;
	hsor->ifs[4].edit = 1;
	hsor->ifs[5].edit = 1;
	hsor->ifs[6].edit = 1;
	hsor->ifs[7].edit = 1;
	hsor->ifs[8].edit = 1;
	hsor->ifs[9].edit = 1;
	hsor->ifs[10].edit = 1;
	hsor->ifs[11].edit = 1;
	hsor->ifs[12].edit = 1;
	hsor->ifs[13].edit = 1;
	hsor->ifs[14].edit = 1;
	hsor->ifs[15].edit = 1;
	hsor->ifs[16].edit = 1;
	clearform(hsor);
	hsor->ifs[13].edit = 0;
	hsor->ifs[14].edit = 0;
	hsor->ifs[15].edit = 0;
	hsor->ifs[16].edit = 0;
	showform(hsor);

        strcpy(hsor->ifs[0].text, daire);
        hsor->ifs[0].edit = 1;
	outputform(hsor);

	i = inputform(hsor);
	if(i == 0)return 0;
	strcpy(daireno,		hsor->ifs[0].text);
	strcpy(esassirayil,	hsor->ifs[1].text);
	strcpy(esassirano,	hsor->ifs[2].text);
	strcpy(geldigitarih,	hsor->ifs[3].text);
	strcpy(tarihi,		hsor->ifs[4].text);
	strcpy(esasno,		hsor->ifs[5].text);
	strcpy(kararno,		hsor->ifs[6].text);
	strcpy(gonderenmahkeme,	hsor->ifs[7].text);
	strcpy(temyizeden,	hsor->ifs[8].text);
	strcpy(aleyhinetemyiz,	hsor->ifs[9].text);
	strcpy(davaninturu,	hsor->ifs[10].text);
	strcpy(dusunceler,	hsor->ifs[11].text);
	strcpy(gonderendaire,	hsor->ifs[12].text);
	

        strcpy(buf,"select "
                "daireno, esassirayil, esassirano, geldigitarih,"
                "tarihi, esasno, kararno, gonderenmahkeme,"
                "temyizeden, aleyhinetemyiz, davaninturu,"
                "dusunceler, gonderendaire "
                "from hukuk.gelendosya "); 
	/***********************/
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
                strcat(buf,esassirayil);
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
                strcat(buf,esasno);
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
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )160;
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


	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "hukuk_sorgu.SQL_PREPARE_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	/* EXEC SQL declare hcur cursor for s1; */ 

	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "hukuk_sorgu.SQL_DECLARE_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	/* EXEC SQL OPEN hcur ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )179;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(SQL_ERROR){
		ntlog2(LOG_SORGU, "hukuk_sorgu.SQL_OPEN_CURSOR", SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}

	while(1){
	hsor->ifs[13].edit = 0;
	hsor->ifs[14].edit = 0;
	hsor->ifs[15].edit = 0;
	hsor->ifs[16].edit = 0;
	yfmessage("Lütfen bekleyiniz...");
	/* EXEC SQL FETCH hcur INTO
		:daireno:ind1, :esassirayil:ind2, :esssno:ind3,
		:geldigitarih:ind4, :tarihi:ind5, :essno:ind6,
		:karno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
		:aleyhinetemyiz:ind10, :davaninturu:ind11,
		:dusunceler:ind12, :gonderendaire:ind13; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )194;
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
  sqlstm.offset = (unsigned int  )261;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(ilkkez){
			yfquestion("Dosya bulunamadý");
			break;
		}
		yfquestion("Son kayýt. Devam için bir tuþa basýnýz");
		returnvalue = 1;
		break;
	} 
	ilkkez = 0;
	if(SQL_ERROR){
		ntlog(LOG_SORGU, SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		goto yenidensor;
	}
	clearform(hsor);

	if(ind1 >= 0) strncpy(hsor->ifs[0].text,daireno,90);
	else hsor->ifs[0].text[0]=0;
	if(ind2 >= 0) strncpy(hsor->ifs[1].text,esassirayil,90);
	else hsor->ifs[1].text[0]=0;
	if(ind3 >= 0) sprintf(hsor->ifs[2].text,"%u",esssno);
	else hsor->ifs[2].text[0]=0;
	if(ind4 >= 0) strncpy(hsor->ifs[3].text,geldigitarih,90);
	else hsor->ifs[3].text[0]=0;
	if(ind5 >= 0) strncpy(hsor->ifs[4].text,tarihi,90);
	else hsor->ifs[4].text[0]=0;
	if(ind6 >= 0) sprintf(hsor->ifs[5].text,"%u",essno);
	else hsor->ifs[5].text[0]=0;
	if(ind7 >= 0) sprintf(hsor->ifs[6].text,"%u",karno);
	else hsor->ifs[6].text[0]=0;
	if(ind8 >= 0) strncpy(hsor->ifs[7].text,gonderenmahkeme,90);
	else hsor->ifs[7].text[0]=0;
	if(ind9 >= 0) strncpy(hsor->ifs[8].text,temyizeden,90);
	else hsor->ifs[8].text[0]=0;
	if(ind10 >= 0) strncpy(hsor->ifs[9].text,aleyhinetemyiz,90);
	else hsor->ifs[9].text[0]=0;
	if(ind11 >= 0) strncpy(hsor->ifs[10].text,davaninturu,90);
	else hsor->ifs[10].text[0]=0;
	if(ind12 >= 0) strncpy(hsor->ifs[11].text,dusunceler,90);
	else hsor->ifs[11].text[0]=0;
	if(ind13 >= 0) strncpy(hsor->ifs[12].text,gonderendaire,90);
	else hsor->ifs[12].text[0]=0;
/**********************************************************************/
        /* simdi sonuc var mi bakalim... */

	/* EXEC SQL SELECT 
		kararsonucu.karsonucu, 
		kararsonucu.karartarihi, 
		kararsonucu.kararnumarasi, 
		kararsonucu.gonderilistarihi

	INTO 	
		:skarsonucu:sind4,
		:skarartarihi:sind5, :skararnumarasi:sind6,
		:sgonderilistarihi:sind7

	FROM hukuk.kararsonucu,hukuk.gelendosya
	WHERE
		
		kararsonucu.daireno = :daireno AND 
		kararsonucu.esassirayil = :esassirayil AND
		kararsonucu.esassirano = :esssno

	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select kararsonucu.karsonucu ,kararsonucu.karartarihi ,karar\
sonucu.kararnumarasi ,kararsonucu.gonderilistarihi into :b0:b1,:b2:b3,:b4:b5,:\
b6:b7  from hukuk.kararsonucu ,hukuk.gelendosya where ((kararsonucu.daireno=:b\
8 and kararsonucu.esassirayil=:b9) and kararsonucu.esassirano=:b10)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )276;
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
 sqlstm.sqhstv[4] = (         void  *)daireno;
 sqlstm.sqhstl[4] = (unsigned int  )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)esassirayil;
 sqlstm.sqhstl[5] = (unsigned int  )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&esssno;
 sqlstm.sqhstl[6] = (unsigned int  )4;
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



	hsor->ifs[13].edit = 0;
	hsor->ifs[14].edit = 0;
	hsor->ifs[15].edit = 0;
	hsor->ifs[16].edit = 0;

	if (SQL_NOTFOUND){
		strcpy(hsor->ifs[13].text,"Bu dosya sonuca baðlanmamýþtýr");
		hsor->ifs[14].text[0] = 0;
		hsor->ifs[15].text[0] = 0;
		hsor->ifs[16].text[0] = 0;
	}else{
	        if(sind4 >= 0) strncpy(hsor->ifs[13].text,skarsonucu,90);
       		else hsor->ifs[13].text[0]=0;
        	if(sind5 >= 0) strncpy(hsor->ifs[14].text,skarartarihi,90);
        	else hsor->ifs[14].text[0]=0;
        	if(sind6 >= 0) sprintf(hsor->ifs[15].text,"%u",
				skararnumarasi,90);
        	else hsor->ifs[15].text[0]=0;
        	if(sind7 >= 0) strncpy(hsor->ifs[16].text,
				sgonderilistarihi,90);
        	else hsor->ifs[16].text[0]=0;
	}

/**********************************************************************/

	outputform(hsor);
	i = yfquestion("Sonraki kayýt görmek için herhangi tuþa basýnýz"
			" Çýkmak için x basýnýz");
	if(i == 'x' || i == 'X') break;
	}
	return returnvalue;

}
