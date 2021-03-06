
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
    "ceza5.pc"
};


static unsigned long sqlctx = 17747;


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
            void  *sqhstv[8];
   unsigned int   sqhstl[8];
            int   sqhsts[8];
            void  *sqindv[8];
            int   sqinds[8];
   unsigned int   sqharm[8];
   unsigned int   *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {10,8};

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

 static char *sq0001 = 
"select sucunturu ,count(sucunturu)  from gelendosya where (daireno=:b0 and g\
eldigitarih between :b1 and :b2) group by sucunturu order by count(sucunturu) \
           ";

 static char *sq0003 = 
"select kararsonucu.esassirayil ,kararsonucu.esassirano ,gelendosya.tebligno \
,gelendosya.tebligmasa  from kararsonucu ,gelendosya where ((gelendosya.dairen\
o=:b0 and kararsonucu.gonderilistarihi=:b1) and gelendosya.kararsonucu=kararso\
nucu.id) order by gelendosya.tebligmasa,gelendosya.esassirayil,gelendosya.esas\
sirano            ";

 static char *sq0004 = 
"select esassirano  from gelendosya where ((gelendosya.daireno=:b0 and gelend\
osya.esassirayil=:b1) and gelendosya.kararsonucu=0) order by esassirayil,esass\
irano            ";

 static char *sq0005 = 
"select esassirano  from gelendosya where (((gelendosya.daireno=:b0 and gelen\
dosya.esassirayil=:b1) and gelendosya.esassirano between :b2 and :b3) and gele\
ndosya.kararsonucu=0) order by esassirayil,esassirano            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4114,0,0,0,
5,0,0,1,165,0,9,132,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,
32,0,0,1,0,0,13,140,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
55,0,0,2,212,0,4,169,0,0,8,3,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,
102,0,0,1,0,0,15,188,0,0,0,0,0,1,0,
117,0,0,3,328,0,9,299,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
140,0,0,3,0,0,13,306,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
171,0,0,3,0,0,15,355,0,0,0,0,0,1,0,
186,0,0,4,171,0,9,445,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
209,0,0,4,0,0,13,448,0,0,1,0,0,1,0,2,3,0,0,
228,0,0,4,0,0,15,466,0,0,0,0,0,1,0,
243,0,0,5,219,0,9,564,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
274,0,0,5,0,0,13,567,0,0,1,0,0,1,0,2,3,0,0,
293,0,0,5,0,0,15,578,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include "yf.h"
#include "ceza.h"
#include "tools.h"
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


#define	KAPATILMAYAN_FILE "kap"
#define	TESLIM_FILE "tes"
#define MAHIYET_FILE "mah"

#define TL_TOTAL_END \
	fprintf(of,"\n\r\n\r       toplam =%6u\n\r\n\r"\
	"       teslim alan                   teslim eden\n",kayitno);\
	for(stat = 0;stat <  43 - lineno;stat++)\
		fprintf(of,"\n\r");\
	fprintf(of,kuyruk,tarih,sayfa);


/********************* Mahiyet List **************/
int mahiyetliste()
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
        char tebligtarih1[11];
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

	char tar1[11];
	char tar2[11];
	char mdbegin[11];
	char mdend[11];
/* EXEC SQL END DECLARE SECTION; */ 


        char buf[900];
	char *baslik=
"                           MAH�YET L�STES�"
"\n\r"
"            daire no  :   %3s                                      sayfa : %4u"
"\n\r\n\r"
"su�un  t�r�                     adet     su�un  t�r�                     adet\n\r"
"-----------                     ----     -----------                     ----\n\r";

	char *kuyruk=
"   (Yargitay Bilgi Islem Merkezi  Dokum Tarihi %s Sayfa  %u)\n\r";
	long kayitno=0;
	long topkayitno = 0;
	long entryno = 0;
	long lineno = 1;
	long sayfa = 1;
	char lastsuc[32];
	long minesas;
	long maxesas;
	int firsttime=1;
        int stat;
	FILE *of;
	char may[3];
	char myil[5];
	int imay;
	int imyil;

	strcpy(buf,home);
	strcat(buf,"/");
	strcat(buf,MAHIYET_FILE);
	of = fopen(buf,"w");
	clearform(mahlist);
	strcpy(mahlist->ifs[0].text,daire);
	mahlist->ifs[0].edit=(superuser)?1:0;
	showform(mahlist);
	outputform(mahlist);
	stat = inputform(mahlist);
	if(stat == 0)return 1;
	strcpy(daire,mahlist->ifs[0].text);
	dress(daire,3);
	strcpy(mdbegin, mahlist->ifs[1].text);
	may[2]=0;
	strcpy(mdend, mahlist->ifs[2].text);
	myil[4]=0;
	imay = atoi(may);
	snprintf(tar1,11,"01/%s/%s",may,myil);

	yfmessage("L�tfen bekleyiniz...");
	/* EXEC SQL DECLARE cur2 CURSOR FOR
		SELECT 
			sucunturu,
			count(sucunturu)
		FROM
			gelendosya
		WHERE
			daireno = :daire AND
			geldigitarih BETWEEN :mdbegin AND :mdend
		GROUP BY sucunturu
		ORDER BY count(sucunturu) 
	; */ 

	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"mahiyet_list.SQL_DECLARE_CURSOR",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		return 0;
	}

	strcpy(buf,baslik);
	striso2dos(buf);
	fprintf(of,buf,daire,sayfa);
	/* EXEC SQL OPEN cur2; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daire;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)mdbegin;
 sqlstm.sqhstl[1] = (unsigned int  )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)mdend;
 sqlstm.sqhstl[2] = (unsigned int  )11;
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
		ntlog2(LOG_CEZA,"mahiyet_list.SQL_OPEN_CURSOR",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		return 0;
	}
	
	while(1){
		/* EXEC SQL FETCH cur2 INTO 
			:sucunturu:ind1,
			:tebligno:ind2
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)sucunturu;
  sqlstm.sqhstl[0] = (unsigned int  )32;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&tebligno;
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


		if (SQL_NOTFOUND) break;
		if (SQL_ERROR){
			ntlog2(LOG_CEZA,"mahiyet_list.SQL_FETCH",SQL_MESSAGE);
			break;
		}

		if(kayitno != 0){
			if(kayitno%2==0){fprintf(of,"\n\r");lineno++;}
			else fprintf(of,"     ");
			if(lineno%55==0){
				fprintf(of,"\f");
				sayfa++;
				lineno++;
				strcpy(buf,baslik);
				fprintf(of,striso2dos(buf),daire,sayfa);
			}
		}
		kayitno++;
		fprintf(of,"%s",striso2dos(sucunturu));
		for(stat = 0; stat < 32 - strlen(sucunturu); stat++)
			fprintf(of," ");
		fprintf(of,"%4u",tebligno);
		
		
	}
	/* EXEC SQL SELECT 
		count(sucunturu),
		min(esassirano),
		max(esassirano),
		max(geldigitarih),
		min(geldigitarih)
		/oLAST_DAY(:tar1)o/
	INTO
		:tebligno:ind1,
		:esassirano:ind2,
		:sesassirano:ind3,
		:tebligtarih:ind4,
		:tebligtarih1:ind5
	FROM
                        gelendosya
        WHERE
                        daireno = :daire AND
                        geldigitarih BETWEEN :mdbegin AND :mdend
	; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(sucunturu) ,min(esassirano) ,max(esassirano) ,m\
ax(geldigitarih) ,min(geldigitarih) into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9  f\
rom gelendosya where (daireno=:b10 and geldigitarih between :b11 and :b12)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&tebligno;
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&ind1;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&esassirano;
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&ind2;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&sesassirano;
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&ind3;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)tebligtarih;
 sqlstm.sqhstl[3] = (unsigned int  )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)&ind4;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)tebligtarih1;
 sqlstm.sqhstl[4] = (unsigned int  )11;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)&ind5;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)daire;
 sqlstm.sqhstl[5] = (unsigned int  )0;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)mdbegin;
 sqlstm.sqhstl[6] = (unsigned int  )11;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)mdend;
 sqlstm.sqhstl[7] = (unsigned int  )11;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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


	/* EXEC SQL CLOSE cur2; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )102;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	sprintf(buf,"\n\r\n\r"
	"            toplam =%6u\n\r"
	"            esas�rano    : %6u - %6u\n\r"
	"            kay�t tarihi : %s - %s\n\r",
	tebligno, esassirano, sesassirano, tebligtarih1, tebligtarih);
	fprintf(of,buf);
	fprintf(of,"\f");

	
	
	fclose(of);
	nthareket("ceza: mahiyet listesi");
	return 0;

}
/********************* Teslim List **************/
int teslimlist()
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


        char buf[300];
	char lastmasa[10];
	char *baslik=
"                                YARGITAY\n\r"
"   TESLIM TUTANAGI\n\r\n\r"
"   daire no: %3s     masa :%2s     teslim tarihi : %s\n\r\n\r"
"     sira  yil esasno   tebligno             sira  yil esasno   tebligno\n\r"
"     ---- -----------   --------             ---- -----------   --------\n\r";
	char *kuyruk=
"   (Yargitay Bilgi Islem Merkezi  Dokum Tarihi %s Sayfa  %u)\n\r";
	long kayitno=0;
	long toplamkayitno=0;
	long lineno = 0;
	long sayfa = 1;
        int stat;
	FILE *of;
	int firsttime=1;

	lastmasa[0]=0;
	strcpy(buf,home);
	strcat(buf,"/");
	strcat(buf,TESLIM_FILE);
	of = fopen(buf,"w");
	clearform(teslimlst);
	showform(teslimlst);
	stat = inputform(teslimlst);
	if(stat == 0)return 1;
	strcpy(sgonderilistarihi, teslimlst->ifs[0].text);
	sgonderilistarihi[10]=0;

	yfmessage("L�tfen bekleyiniz...");
	/* EXEC SQL DECLARE cur1 CURSOR FOR
		SELECT 
			kararsonucu.esassirayil,
			kararsonucu.esassirano,
			gelendosya.tebligno,
			gelendosya.tebligmasa
		FROM
			kararsonucu,gelendosya
		WHERE
			gelendosya.daireno = :daire AND
			kararsonucu.gonderilistarihi = :sgonderilistarihi AND
			gelendosya.kararsonucu = kararsonucu.id
			/okararsonucu.daireno = gelendosya.daireno AND
			kararsonucu.esassirayil = gelendosya.esassirayil AND
			kararsonucu.esassirano = gelendosya.esassiranoo/
		ORDER BY gelendosya.tebligmasa, gelendosya.esassirayil,
			 gelendosya.esassirano 
		/oORDER BY gelendosya.tebligmasa DESCo/
	; */ 

	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"teslim_list.SQL_DECLARE_CURSOR",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		return 0;
	}

	/* EXEC SQL OPEN cur1; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )117;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daire;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sgonderilistarihi;
 sqlstm.sqhstl[1] = (unsigned int  )11;
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


	if (SQL_ERROR){
		ntlog2(LOG_CEZA,"teslim_list.SQL_OPEN_CURSOR",SQL_MESSAGE);
		yfquestion(SQL_MESSAGE);
		return 0;
	}
	while(1){
		/* EXEC SQL FETCH cur1 INTO 
			:esassirayil:ind1,
			:esassirano:ind2,
			:tebligno:ind3,
			:tebligmasa:ind4
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )140;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)esassirayil;
  sqlstm.sqhstl[0] = (unsigned int  )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&esassirano;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)&ind2;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&tebligno;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)&ind3;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)tebligmasa;
  sqlstm.sqhstl[3] = (unsigned int  )3;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)&ind4;
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


		if (SQL_NOTFOUND) break;
		if (SQL_ERROR){
			ntlog2(LOG_CEZA,"teslim_liste.SQL_FETCH_CUR",SQL_MESSAGE);
			break;
		}
		
		if(firsttime==1){
			strcpy(lastmasa,tebligmasa);firsttime=0;
			fprintf(of,baslik,daire,tebligmasa,sgonderilistarihi);
		}

		if(strcmp(lastmasa,tebligmasa)!=0){
			TL_TOTAL_END;
			strcpy(lastmasa,tebligmasa);
			toplamkayitno += kayitno;
			kayitno=0;
			lineno = 0;
			sayfa = 1;
			fprintf(of,"\f");
			fprintf(of,baslik,daire,tebligmasa,sgonderilistarihi);
		}
			
		if(kayitno != 0){
			if(kayitno%2==0){fprintf(of,"\n\r");lineno++;}
			else fprintf(of,"        ");
		}
		if(lineno != 0 && lineno%48==0){
			fprintf(of,kuyruk,tarih,sayfa);
			fprintf(of,"\f");
			fprintf(of,baslik,daire,tebligmasa,sgonderilistarihi);
			sayfa++;
			lineno = 1;
		}
		kayitno++;
		fprintf(of,"     %4u  %s %7u   %8u",
			kayitno,esassirayil,esassirano,tebligno);
	}
	TL_TOTAL_END;
	toplamkayitno += kayitno;
	sprintf(buf,"%u dosya bulundu. "
		"Devam i�in RETURN ",toplamkayitno);
	yfquestion(buf);
	
	/* EXEC SQL CLOSE cur1; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )171;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fclose(of);
	nthareket("ceza: teslim listesi");
	return 0;

}
/********************* Kapatilmayan List **************/
/********************* Kapatilmayan List **************/
int kptlmynlist(guzellik)
	int guzellik;
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


        char buf[300];
	char *baslik=
		">>>>kapatilmiyan kayitlar listesi-19%s\n\r"
		"daire no: %s\n\r\n\r";
	char *kuyruk=
			"\n\rYargitay Bilgi Islem Merkezi  (Dokum Tarihi "\
			"%s  Sayfa    %u )\n\r";
	long kayitno=0;
	long lineno = 0;
	long sayfa = 1;
        int stat;
	FILE *of;

	strcpy(buf,home);
	strcat(buf,"/");
	strcat(buf,KAPATILMAYAN_FILE);
	of = fopen(buf,"w");
	clearform(fkptlmynlist);
	showform(fkptlmynlist);
	stat = inputform(fkptlmynlist);
	if(stat == 0)return 1;
	strcpy(esassirayil, fkptlmynlist->ifs[0].text);
	esassirayil[4]=0;


	yfmessage("L�tfen bekleyiniz...");
	/* EXEC SQL DECLARE cur CURSOR FOR
		SELECT 
			esassirano 
		FROM
			gelendosya
		WHERE
			gelendosya.daireno = :daire AND
			gelendosya.esassirayil = :esassirayil AND
			gelendosya.kararsonucu = 0
			/oNOT EXISTS(
			SELECT id FROM kararsonucu
			WHERE
			gelendosya.daireno = kararsonucu.daireno AND
			gelendosya.esassirayil = kararsonucu.esassirayil AND
			gelendosya.esassirano = kararsonucu.esassirano)o/
		ORDER BY esassirayil, esassirano
	; */ 


	/* EXEC SQL OPEN cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )186;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daire;
 sqlstm.sqhstl[0] = (unsigned int  )0;
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


	fprintf(of,baslik,esassirayil,daire);
	while(1){
		/* EXEC SQL FETCH cur INTO :esassirano:ind1; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )209;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&esassirano;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
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


		if (sqlca.sqlcode == 1403) break;
		if (sqlca.sqlcode < 0) break;
		kayitno++;
		fprintf(of,"%10u",esassirano);
		if(guzellik && kayitno%(8*51)==0){
			fprintf(of,kuyruk,tarih,sayfa);
			fprintf(of,"\f");
			fprintf(of,baslik,esassirayil,daire);
			lineno = 0;
			sayfa++;
		}else if(kayitno%8==0){fprintf(of,"\n\r");lineno++;}
	}
	fprintf(of,"\n\rtoplam kapatilmiyan:  %u\n\r",kayitno);
	for(stat = 0;stat <  48 - lineno;stat++)
		fprintf(of,"\n\r");
	if(guzellik)fprintf(of,kuyruk,tarih,sayfa);
	
	/* EXEC SQL CLOSE cur; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )228;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fclose(of);
	nthareket("ceza: kapatilmayan listesi");
	sprintf(buf,"%u kapat�lmayan dosya bulundu. "
		"Devam i�in RETURN ",kayitno);
	yfquestion(buf);
	return 0;

}
/********************* Kapatilmayan Ekrana List **************/
kapatilmayan()
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


        char buf[300];
	char *baslik=
		">>>>kapatilmiyan kayitlar listesi-19%s\n\r"
		"daire no: %s\n\r\n\r";
	long kayitno=0;
	long lineno = 0;
	long sayfa = 1;
        int stat;
	FILE *of;

	strcpy(buf,home);
	strcat(buf,"/");
	strcat(buf,KAPATILMAYAN_FILE);
	of = fopen(buf,"w");
	clearform(skapatilmayan);
	showform(skapatilmayan);

	strcpy(skapatilmayan->ifs[0].text,daire);
	skapatilmayan->ifs[0].edit = 0;
	outputform(skapatilmayan);
	stat = inputform(skapatilmayan);
	if(stat == 0)return 1;

        strcpy(esassirayil, skapatilmayan->ifs[1].text);
        esassirayil[4]=0;
        esassirano = atol(skapatilmayan->ifs[2].text);
        sesassirano = atol(skapatilmayan->ifs[3].text);


	yfmessage("L�tfen bekleyiniz...");
	/* EXEC SQL DECLARE curkap CURSOR FOR
		SELECT 
			esassirano 
		FROM
			gelendosya
		WHERE
			gelendosya.daireno = :daire AND
			gelendosya.esassirayil = :esassirayil AND
                        (gelendosya.esassirano BETWEEN :esassirano
                                               AND :sesassirano) AND

			gelendosya.kararsonucu = 0
		/o	NOT EXISTS(
			SELECT id FROM kararsonucu
			WHERE
			gelendosya.daireno = kararsonucu.daireno AND
			gelendosya.esassirayil = kararsonucu.esassirayil AND
			gelendosya.esassirano = kararsonucu.esassirano)o/
		ORDER BY esassirayil, esassirano
	; */ 


	/* EXEC SQL OPEN curkap; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )243;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)daire;
 sqlstm.sqhstl[0] = (unsigned int  )0;
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


	fprintf(of,baslik,esassirayil,daire);
	while(1){
		/* EXEC SQL FETCH curkap INTO :esassirano:ind1; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )274;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&esassirano;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)&ind1;
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


		if (sqlca.sqlcode == 1403) break;
		if (sqlca.sqlcode < 0) break;
		kayitno++;
		fprintf(of,"%10u",esassirano);
		if(kayitno%8==0){fprintf(of,"\n\r");lineno++;}
	}
	fprintf(of,"\n\rtoplam kapatilmiyan:  %u\n\r",kayitno);
	for(stat = 0;stat <  48 - lineno;stat++)
		fprintf(of,"\n\r");
	
	/* EXEC SQL CLOSE curkap; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )293;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fclose(of);
	sprintf(buf,"%u kapat�lmayan dosya bulundu. "
		"Devam i�in RETURN ",kayitno);
	yfquestion(buf);
	strcpy(buf,home);
	strcat(buf,"/");
	strcat(buf,KAPATILMAYAN_FILE);
	if(kayitno)yffmore(buf,"Devam etmek i�in RETURN ");
	return 0;

}
/**************************************************************/
