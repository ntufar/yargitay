
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "hukuksorgu.pc"
};


static unsigned long sqlctx = 629043;


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
{10,4146,0,0,0,
5,0,0,1,0,0,27,88,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,17,216,0,0,1,1,0,1,0,1,5,0,0,
55,0,0,2,0,0,45,226,0,0,0,0,0,1,0,
70,0,0,2,0,0,13,238,0,0,14,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,
0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
141,0,0,3,132,0,4,275,0,0,5,1,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,3,0,0,
176,0,0,2,0,0,15,356,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include "cgi.h"
#include "wwwtools.h"

#define SQL_ERROR       sqlca.sqlcode < 0
#define SQL_NOTFOUND    sqlca.sqlcode == 1403
#define SQL_MESSAGE     sqlca.sqlerrm.sqlerrmc

/* EXEC SQL BEGIN DECLARE SECTION; */ 

/* VARCHAR uid[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } uid;

/* VARCHAR pwd[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } pwd;


        /*------------- Kararsonucu ------------*/
	long sid;
        char sdaireno[4];
        char sesassirayil[3];
        long sesassirano;
        char skarsonucu[31];
        char skarartarihi[11];
        long skararnumarasi;
        char sgonderilistarihi[11];
        short sind1,sind2,sind3,sind4,sind5,sind6,sind7, sind8;
        /*------------- Gelendosya ------------*/
        char daireno[100];
        char esassirayil[100];
        char esassirano[100];
        char geldigitarih[100];
        char tarihi[100];
        char esasno[100];
        char kararno[100];
        char gonderenmahkeme[100];
        char temyizeden[100];
        char aleyhinetemyiz[100];
        char davaninturu[100];
        char dusunceler[100];
        char gonderendaire[100];

	long esssno;
	long essno;
	long karno;

	char buf[1000];
	short ind1,ind2,ind3,ind4,ind5,ind6,ind7,ind8,ind9,
		ind10, ind11, ind12, ind13;

/* EXEC SQL END DECLARE SECTION; */ 

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


char *cgiDebug;

cgiMain()
{
	int i;
	int waswhere = 0;
	int nosonuc = 0;
	int firsttime = 1;


        putenv("ORACLE_SID=yargitay");
        putenv("ORACLE_HOME=/u01/oracle/product/8.0.5");
        putenv("LD_LIBRARY_PATH=/u01/oracle/product/8.0.5/lib");
        putenv("NLS_LANG=TURKISH_TURKEY.WE8ISO8859P9");

        strcpy (uid.arr,"sorgu");
        uid.len=strlen(uid.arr);
        strcpy (pwd.arr,"sorgu");
        pwd.len=strlen(pwd.arr);

        cgiHeaderContent("text/html");
        cgiHtmlHead("Hukuk Daireleri Sorgu Sonucu");
        cgiPrintf(
        "<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
        cgiPrintf(
        "<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	cgiPrintf(
	"<BODY TEXT=\"#000000\" BGCOLOR=\"#FFFFFF\" LINK=\"#FF0000\""
	" VLINK=\"#3333FF\""
	"ALINK=\"#FF0000\">"
	"<center>"
	"</img><img src=\"http://yargitay.gov.tr/images/yargi.JPG\"></img>"
        "<br>"
        "Ana sayfa için <a href=\"http://www.yargitay.gov.tr/\">http://www.yargitay.gov.tr</a>"
        " týklayýnýz"
	"</center>"
	"<HR>");

        /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd; */ 

{
        struct sqlexd sqlstm;

        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )10;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlstm.sqhstv[0] = (         void  *)&uid;
        sqlstm.sqhstl[0] = (unsigned int  )12;
        sqlstm.sqhsts[0] = (         int  )12;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&pwd;
        sqlstm.sqhstl[1] = (unsigned int  )12;
        sqlstm.sqhsts[1] = (         int  )12;
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


        if(SQL_ERROR){
		cgiPrintf("Veritabaný þu an bakým altýnda. Sonra deneyin. <p>BÝM");
                /*cgiPrintf(SQL_MESSAGE);*/
                exit(0);
        }

	strcpy(daireno, 	 cgiFormGetVal("daireno"));
	strcpy(esassirayil,	 cgiFormGetVal("esassirayil"));
	strcpy(esassirano,	 cgiFormGetVal("esassirano"));
	strcpy(geldigitarih,	 cgiFormGetVal("geldigitarih"));
	strcpy(tarihi,		 cgiFormGetVal("tarihi"));
	strcpy(esasno,		 cgiFormGetVal("esasno"));
	strcpy(kararno,		 cgiFormGetVal("kararno"));
	strcpy(gonderenmahkeme,	 cgiFormGetVal("gonderenmahkeme"));
	strcpy(temyizeden,	 cgiFormGetVal("temyizeden"));
	strcpy(aleyhinetemyiz,	 cgiFormGetVal("aleyhinetemyiz"));
	strcpy(davaninturu,	 cgiFormGetVal("davaninturu"));
	strcpy(dusunceler,	 cgiFormGetVal("dusunceler"));
	strcpy(gonderendaire,	 cgiFormGetVal("gonderendaire"));
	

        /*strcpy(buf,"select "
                "daireno, esassirayil, esassirano, geldigitarih,"
                "tebligtarih, tebligmasa, tebligno, esasno,"
                "kararno, gonderenmahkeme, sucunturu,"
                "temyizeden, tutuklu "
                "from cgelendosya "); */
	/***********************/
        strcpy(buf,"select "
                "daireno, esassirayil, esassirano, geldigitarih,"
                "tarihi, esasno, kararno, gonderenmahkeme,"
                "temyizeden, aleyhinetemyiz, davaninturu,"
                "dusunceler, gonderendaire, kararsonucu "
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
                strcat(buf,quote(esassirayil));
                strcat(buf,"'");
        }
        if(esassirano[0]!=0){
                if(!waswhere){strcat(buf," where ");waswhere=1;}
                else strcat(buf," and ");
                strcat(buf," esassirano =");
                strcat(buf,quote(esassirano));
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
                strcat(buf,quote(kararno));
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

	/***********************/


	/* EXEC SQL PREPARE s1 FROM :buf; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
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
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }
	/* EXEC SQL declare cur cursor for s1; */ 

        if(SQL_ERROR){
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }
	/* EXEC SQL open cur ; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if(SQL_ERROR){
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }
	/*EXEC SQL WHENEVER NOT FOUND DO break;*/
        if(SQL_ERROR){
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }

	for(i=0;i<55;i++){
	/* EXEC SQL fetch cur into
                :daireno:ind1, :esassirayil:ind2, :esssno:ind3,
                :geldigitarih:ind4, :tarihi:ind5, :essno:ind6,
                :karno:ind7, :gonderenmahkeme:ind8, :temyizeden:ind9,
                :aleyhinetemyiz:ind10, :davaninturu:ind11,
                :dusunceler:ind12, :gonderendaire:ind13,
		:sid:sind8; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )70;
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
 sqlstm.sqhstv[2] = (         void  *)&esssno;
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
 sqlstm.sqhstv[4] = (         void  *)tarihi;
 sqlstm.sqhstl[4] = (unsigned int  )100;
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
 sqlstm.sqhstl[7] = (unsigned int  )100;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)&ind8;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)temyizeden;
 sqlstm.sqhstl[8] = (unsigned int  )100;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)&ind9;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)aleyhinetemyiz;
 sqlstm.sqhstl[9] = (unsigned int  )100;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)&ind10;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)davaninturu;
 sqlstm.sqhstl[10] = (unsigned int  )100;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)&ind11;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)dusunceler;
 sqlstm.sqhstl[11] = (unsigned int  )100;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         void  *)&ind12;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)gonderendaire;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         void  *)&ind13;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)&sid;
 sqlstm.sqhstl[13] = (unsigned int  )4;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         void  *)&sind8;
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


        if(SQL_ERROR){
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }
        if(SQL_NOTFOUND){
		if(firsttime){
			cgiPrintf("<p>Hiçbir kayýt bulunamadý");
		}
                break;
        }
	firsttime = 0;


	if(ind1 >= 0) daireno[3]=0; else daireno[0]=0;
	if(ind2 >= 0) esassirayil[2]=0;else esassirayil[2]=0;
	if(ind3 >= 0) sprintf(esassirano, "%u", esssno); else esassirano[0] = 0;
	if(ind4 >= 0) geldigitarih[10]=0; else geldigitarih[0]=0;
	if(ind5 >= 0) tarihi[10]=0; else tarihi[0]=0;
	if(ind6 >= 0) sprintf(esasno, "%u", essno); else esasno[0]=0;
	if(ind7 >= 0) sprintf(kararno, "%u", karno); else kararno[0] = 0;
	if(ind8 >=  0) gonderenmahkeme[31]=0; else gonderenmahkeme[0]=0;
	if(ind9 >=  0) temyizeden[31]=0; else temyizeden[0]=0;
	if(ind10 >= 0) aleyhinetemyiz[31]=0; else aleyhinetemyiz[0]=0;
	if(ind11 >= 0) davaninturu[31]=0; else davaninturu[0]=0;
	if(ind12 >= 0) dusunceler[31]=0; else dusunceler[0]=0;
	if(ind13 >= 0) gonderendaire[31]=0; else gonderendaire[0]=0;
/**********************************************************************/
        /* simdi sonuc var mi bakalim... */

	if(sid != 0 ){
        /* EXEC SQL SELECT
                karsonucu,
                karartarihi,
                kararnumarasi,
                gonderilistarihi

        INTO
                :skarsonucu:sind4,
                :skarartarihi:sind5, :skararnumarasi:sind6,
                :sgonderilistarihi:sind7

        FROM hukuk.kararsonucu
        WHERE

		id = :sid
                /odaireno = :daireno AND
                esassirayil = :esassirayil AND
                esassirano = :esssnoo/

        ; */ 

{
        struct sqlexd sqlstm;

        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select karsonucu ,karartarihi ,kararnumarasi ,gonderi\
listarihi into :b0:b1,:b2:b3,:b4:b5,:b6:b7  from hukuk.kararsonucu where id=:b\
8";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )141;
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


       if(SQL_ERROR){
                cgiPrintf(SQL_MESSAGE);
                exit(0);
        }
	} /* if */
        if(sid == 0 || SQL_NOTFOUND){
                nosonuc = 1;
        } else nosonuc = 0;


        cgiPrintf(
	"<table>"
	"<tr><td><td><b>Daire Numarasý	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Esas Sýra Yýl	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Esas Sýra No	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Kayýt Tarihi	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Mahkeme Tarihi	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Mahkeme Esas No.</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Mahkeme Karar No.</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Geldiði Mahkeme	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Temyiz Eden	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Aleyhine Temyiz</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Davanýn Türü	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Düþünceler	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Gönderen Daire	</b></td><td>%s</td></tr>"
        "</table>",

                daireno, esassirayil, esassirano,
                geldigitarih, tarihi, esasno,
                kararno, gonderenmahkeme, temyizeden,
                aleyhinetemyiz, davaninturu,
                dusunceler, gonderendaire);
        cgiPrintf(
        "------------ Karar sonucu -------------<br>");
        if(nosonuc){
                cgiPrintf("<b>Bu dosya sonuca baðlanmamýþtýr</b>");
        }else{
        cgiPrintf(
        "<table>"
	"<tr><td><td><b>Karar	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Karar tarihi	</b></td><td>%s</td></tr>"
	"<tr><td><td><b>Karar numarasý	</b></td><td>%d</td></tr>"
	"<tr><td><td><b>Gönderiliþ tarihi	</b></td><td>%s</td></tr>"
	"</table>",
                skarsonucu,
                skarartarihi, skararnumarasi,
                sgonderilistarihi
	);
	}
        cgiPrintf("<hr>");
        nosonuc = 0;


	if(i==20){
		cgiPrintf("<br>Girdýðýnýz sorgu 20 kayýttan fazla getirdi"
		"<br>Sorguyu daraltýnýz ve yeniden deneyiniz");
		break;
	}
		

	}
	/* EXEC SQL CLOSE cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )176;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	cgiPrintf("</body></html>");

}
errprint()
{
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    cgiPrintf("<b>Veritabaný hatasý:</b>");
    cgiPrintf("%s\n",sqlca.sqlerrm.sqlerrmc);
    exit(1);
}

