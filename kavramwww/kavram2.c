
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "kavram2.pc"
};


static unsigned long sqlctx = 75419;


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
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {10,4};

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

 static char *sq0002 = 
"select esasno ,daireno  from emsal.kavram where kavram=:b0           ";

 static char *sq0003 = 
"select esasno ,daireno  from emsal.kavram where (daireno=:b0 and kavram=:b1)\
           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4146,0,0,0,
5,0,0,1,0,0,27,133,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,5,0,0,1,10,0,0,
36,0,0,2,69,0,9,170,0,0,1,1,0,1,0,1,5,0,0,
55,0,0,3,87,0,9,172,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
78,0,0,2,0,0,13,182,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
101,0,0,3,0,0,13,186,0,0,2,0,0,1,0,2,5,0,0,2,5,0,0,
};


#include <stdio.h>
#include <stdlib.h>
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

char    dbname[10]="y1";

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


char textdaire[30];

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


/*----------------------------------*/

/*----------------------------------*/
typedef struct dt{
	char	*code;
	char	*name;
}daireler_t;

daireler_t daireler[]={
/*	"",	"Tüm daireler",*/
	"1c",	"1. Ceza dairesi",
	"2c",	"2. Ceza dairesi",
	"3c",	"3. Ceza dairesi",
	"4c",	"4. Ceza dairesi",
	"5c",	"5. Ceza dairesi",
	"6c",	"6. Ceza dairesi",
	"7c",	"7. Ceza dairesi",
	"8c",	"8. Ceza dairesi",
	"9c",	"9. Ceza dairesi",
	"10c",	"10. Ceza dairesi",
	"11c",	"11. Ceza dairesi",
	"1h",	"1. Hukuk dairesi",
	"2h",	"2. Hukuk dairesi",
	"3h",	"3. Hukuk dairesi",
	"4h",	"4. Hukuk dairesi",
	"5h",	"5. Hukuk dairesi",
	"6h",	"6. Hukuk dairesi",
	"7h",	"7. Hukuk dairesi",
	"8h",	"8. Hukuk dairesi",
	"9h",	"9. Hukuk dairesi",
	"10h",	"10. Hukuk dairesi",
	"11h",	"11. Hukuk dairesi",
	"12h",	"12. Hukuk dairesi",
	"13h",	"13. Hukuk dairesi",
	"14h",	"14. Hukuk dairesi",
	"15h",	"15. Hukuk dairesi",
	"16h",	"16. Hukuk dairesi",
	"17h",	"17. Hukuk dairesi",
	"18h",	"18. Hukuk dairesi",
	"19h",	"19. Hukuk dairesi",
	"20h",	"20. Hukuk dairesi",
	"21h",	"21. Hukuk dairesi",
	"cgk",	"Ceza Genel Kurulu",
	"hgk",	"Hukuk Genel Kurulu",
	"yik",	"Ýçtihadý Birleþtirme Kurulu",
	NULL,NULL
};
/*----------------------------------*/
/*----------------------------------*/
char *cgiDebug;

cgiMain()
{
	int i;
	int waswhere = 0;
	int nosonuc = 0;
	int firsttime = 1;
	int nodaire=1;


        putenv("ORACLE_SID=yargitay");
        putenv("ORACLE_HOME=/u01/oracle/product/8.0.5");
        putenv("LD_LIBRARY_PATH=/u01/oracle/product/8.0.5/lib");
        putenv("NLS_LANG=TURKISH_TURKEY.WE8ISO8859P9");

        strcpy (uid.arr,"sorgu");
        uid.len=strlen(uid.arr);
        strcpy (pwd.arr,"sorgu");
        pwd.len=strlen(pwd.arr);

        cgiHeaderContent("text/html");
        cgiHtmlHead("T.C. Yargýtay Emsal kararlarý kavrama göre arama");
        cgiPrintf(
        "<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	cgiPrintf(
	"<BODY TEXT=\"#ffffff\" BGCOLOR=\"#000000\" LINK=\"#FF0000\""
	" VLINK=\"#3333FF\""
	"ALINK=\"#FF0000\">"
	"<center>"
	"</img><img src=\"http://yargitay.gov.tr/images/yargi.JPG\"></img>"
	"<br>"
	"Ana sayfa için <a href=\"http://www.yargitay.gov.tr/\">http://www.yargitay.gov.tr</a>"
	" týklayýnýz" 
        "</center>"
	"<HR>");

        cgiPrintf("<h2>Emsal Kararlarý Kavrama Göre Arama</h2>");
        cgiPrintf("Esas Numarasýna týklayarak karara "
                "ulaþabilirsiniz.<br>"
                "Görüþ ve önerileriniz için <a href=\"mailto:teknik@yargitay.gov.tr\">"
                "teknik@yargitay.gov.tr</a><br><br>");

        /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd USING :dbname; */ 

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
        sqlstm.sqhstv[2] = (         void  *)dbname;
        sqlstm.sqhstl[2] = (unsigned int  )10;
        sqlstm.sqhsts[2] = (         int  )10;
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
		cgiPrintf("Veritabaný þu an bakým altýnda. Sonra deneyin. <p>BÝM");
		exit(0);
	}
	if(cgiFormGetVal("daire")){
		strcpy(textdaire,          cgiFormGetVal("daire"));
		if(textdaire[0]!=0){
        		for(i=0;daireler[i].code;i++){
                		if(strcmp(daireler[i].code,textdaire)==0){
					cgiPrintf("<strong>Daire:</strong> %s<br>",daireler[i].name);
                        		break;
				}
                	}
			nodaire = 0;
		}else nodaire = 1;
	}else nodaire = 1;
	if(cgiFormGetVal("kavram")){
		strcpy(kavram,          cgiFormGetVal("kavram"));
		cgiPrintf("<strong>Kavram:</strong> %s<br>", kavram);
	}
	if(nodaire){
		/* EXEC SQL DECLARE kcurnd CURSOR FOR
			SELECT esasno, daireno
			FROM emsal.kavram
			WHERE kavram=:kavram
		; */ 

	}else{
		/* EXEC SQL DECLARE kcur CURSOR FOR
			SELECT esasno, daireno
			FROM emsal.kavram
			WHERE daireno=:textdaire AND
				kavram=:kavram
		; */ 

	}

	if(nodaire){
		/* EXEC SQL OPEN kcurnd; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0002;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )36;
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
		/* EXEC SQL OPEN kcur; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0003;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )55;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)textdaire;
  sqlstm.sqhstl[0] = (unsigned int  )30;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
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
		
	
	/*cgiPrintf("nodaire=%d",nodaire);*/
	cgiPrintf("<TABLE>");
	cgiPrintf("<TR><TD><strong>Daire</strong></TD><TD><strong>Esas sýra numarasý</strong>"
		  "</TD></TR>");
	while(1){
		if(nodaire){
			/* EXEC SQL FETCH kcurnd
				INTO :kesasno:ind0, :kdaireno:ind1
			; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )78;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)kesasno;
   sqlstm.sqhstl[0] = (unsigned int  )10;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)&ind0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)kdaireno;
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


		}else{
			/* EXEC SQL FETCH kcur 
				INTO :kesasno:ind0, :kdaireno:ind1
			; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )101;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)kesasno;
   sqlstm.sqhstl[0] = (unsigned int  )10;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)&ind0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)kdaireno;
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


		}
		if(SQL_ERROR){
			cgiPrintf("Holario");
			exit(1);
		}
		if(SQL_NOTFOUND)break;
		cgiPrintf("<TR><TD>");
        	for(i=0;daireler[i].code;i++){
                	if(strcmp(daireler[i].code,kdaireno)==0){
				cgiPrintf(daireler[i].name);
                       		break;
			}
                }
		cgiPrintf("</TD><TD>"
			"<A HREF=\"kavram3?daire=%s&esasno=%s\">%s</A></TD></TR>",
			cgiEncodeUrl(kdaireno),cgiEncodeUrl(kesasno), kesasno);

	}
	cgiPrintf("</TABLE>");

}
errprint()
{
   /* EXEC SQL WHENEVER SQLERROR CONTINUE;*/
    cgiPrintf("<b>Veritabaný hatasý:</b>");
    cgiPrintf("%s\n",sqlca.sqlerrm.sqlerrmc);
    exit(1);
}

