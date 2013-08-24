
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "emsalgir1.pc"
};


static unsigned long sqlctx = 298019;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4114,0,0,0,
5,0,0,1,39,0,3,138,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,
32,0,0,2,0,0,31,142,0,0,0,0,0,1,0,
47,0,0,3,0,0,31,148,0,0,0,0,0,1,0,
62,0,0,4,0,0,29,156,0,0,0,0,0,1,0,
77,0,0,5,55,0,4,244,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
100,0,0,6,55,0,4,295,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
123,0,0,7,0,0,31,302,0,0,0,0,0,1,0,
138,0,0,8,50,0,3,305,0,0,5,5,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
173,0,0,9,0,0,31,315,0,0,0,0,0,1,0,
188,0,0,10,0,0,29,321,0,0,0,0,0,1,0,
203,0,0,11,38,0,3,344,0,0,2,2,0,1,0,1,3,0,0,1,5,0,0,
226,0,0,12,0,0,29,352,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <malloc.h>
#include "yf.h"
#include "tools.h"
#include "emsalgir.h"
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


/* 4 global degisken su an calistigimiz karar  
 * hakkinda bilgi tutuyor
 */
static char Daireno[4] = {0,0,0,0};
static char Esasno[10] = {0,0,0,0,0,0,0,0,0,0};
static char Kararno[9] = {0,0,0,0,0,0,0,0,0};
static char Tarih[11]  = {0,0,0,0,0,0,0,0,0,0};

kavramgir()
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char daireno[5];
char esasno[10];
char kavram[76];

/*char kmetin[1024*100];
*/
char kdaireno[5];
char skdaireno[5];
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


	int stat;
	int cevap;
	int i;
	int start = 0;

	strcpy(fkavram->ifs[0].text,daire);
	strcpy(fkavram->ifs[1].text, Esasno);
	strcpy(fkavram->ifs[2].text, Kararno);
	strcpy(fkavram->ifs[3].text, Tarih);
	fkavram->ifs[0].edit=0;
	showform(fkavram);

kavramyeniden:
	outputform(fkavram);
	stat = superinputform(fkavram, start);
	if (stat == 0) return 0;

	if(fkavram->ifs[1].text[0]==0){
		yfmessage("Esas numarasý boþ");
		start = 1;
		goto kavramyeniden;
	}
	if(fkavram->ifs[2].text[0]==0){
		yfmessage("Karar numarasý boþ");
		start = 2;
		goto kavramyeniden;
	}
	if(fkavram->ifs[3].text[0]==0){
		yfmessage("Tarihi boþ");
		start = 3;
		goto kavramyeniden;
	}
	
	/*--------------------------------*/
	strcpy(Daireno, fkavram->ifs[0].text);
	strcpy(Esasno, fkavram->ifs[1].text);
	strcpy(Kararno, fkavram->ifs[2].text);
	strcpy(Tarih, fkavram->ifs[3].text);
	/*--------------------------------*/
/***************************************************
 * Emsal girdiklerinde karar sadece sisteme
 * Aktarilip /home/proje dizinine kpyalanmis
 * oluyor varitabaninda onun olup olmadigini
 * kontrol etmek anlamsizdir
 ***************************************************
	/* check if the karar exists 
	strcpy(kdaireno,fkavram->ifs[0].text);
	strcpy(skdaireno,fkavram->ifs[0].text);
	dress(kdaireno,4);
	strip(skdaireno);
	strcpy(kesasno,Esasno);
	dress(kesasno,9);
	strcpy(kkararno,Kararno);
	dress(kkararno,8);
	strcpy(ktarih,Tarih);
	
	yfmessage("Lütfen bekleyiniz");

	EXEC SQL SELECT esasno INTO :kesasno
		FROM karar
		WHERE
			(daireno = :kdaireno OR
			 daireno = :skdaireno) AND 
			esasno = :kesasno AND
			kararno = :kkararno AND
			tarih = :ktarih
		;
	if(SQL_ERROR){
		yfquestion(SQL_MESSAGE);
		return 0;
	}
	if(SQL_NOTFOUND){
		yfquestion("Kararýn metni bulunmadý. Devam etmek istiyor musunuz?");
	}
***************************************************/
			
		

	cevap = yfquestion("Girdiðiniz bilgiler doðru mu? (e/h)");
	if(cevap != 'e' && cevap != 'E'){
		yfmessage("");
		start = 4;
		goto kavramyeniden;
	}


	for(i=4; i< 15+4; i++){
		if(fkavram->ifs[i].text[0]!=0){
			strcpy(daireno,Daireno);
			strcpy(esasno,Esasno);
			strcpy(kavram,fkavram->ifs[i].text);
			strip(kavram);

			/* EXEC SQL INSERT INTO kavram VALUES(
				:daireno, :esasno, :kavram
			); */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 3;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "insert into kavram values (:b0,:b1,:b2)";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)daireno;
   sqlstm.sqhstl[0] = (unsigned int  )5;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)esasno;
   sqlstm.sqhstl[1] = (unsigned int  )10;
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
				/* EXEC SQL ROLLBACK WORK; */ 

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
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				nthareket("ROLLBACK edildi");
				yfquestion(SQL_MESSAGE);
				return 0;
			}
			if(SQL_NOTFOUND){
				/* EXEC SQL ROLLBACK WORK; */ 

{
    struct sqlexd sqlstm;

    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )47;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				nthareket("ROLLBACK edildi");
				yfquestion(SQL_MESSAGE);
				return 0;
			}
			nthareket("'%s' kavrami girildi",kavram);
		}
	}
	/* EXEC SQL COMMIT WORK; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )62;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	nthareket("COMMIT edildi");
	for(i=4; i<15+4;i++){
		fkavram->ifs[i].text[0]=0;
	}
	yfquestion("Bilgiler girildi. RETURN basýnýz");

}

/*-------------------------------------------------*/
kanungir()
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

long kkanunno;
char kkanun[256];
char kmadde[16];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[5];
/* EXEC SQL END DECLARE SECTION; */ 

	int stat;
	int i;
	int cevap;
	int start = 0;
	char *b;

	for(i=6;i<51;i+=3)fkanun->ifs[i].edit=0;
	strcpy(fkanun->ifs[1].text, Esasno);
	strcpy(fkanun->ifs[2].text, Kararno);
	strcpy(fkanun->ifs[3].text, Tarih);
	fkanun->ifs[0].edit=0;
	showform(fkanun);
kanunyeniden:

	strcpy(fkanun->ifs[0].text, daire);
	outputform(fkanun);
	stat = superinputform(fkanun, start);
	if (stat == 0) return 0;

	if(fkanun->ifs[1].text[0]==0){
		yfmessage("Esas numarasý boþ");
		start = 1;
		goto kanunyeniden;
	}
	if(fkanun->ifs[2].text[0]==0){
		yfmessage("Karar numarasý boþ");
		start = 2;
		goto kanunyeniden;
	}
	if(fkanun->ifs[3].text[0]==0){
		yfmessage("Tarihi boþ");
		start = 3;
		goto kanunyeniden;
	}

	strcpy(Esasno, fkanun->ifs[1].text);
	strcpy(Kararno, fkanun->ifs[2].text);
	strcpy(Tarih, fkanun->ifs[3].text);
	
	/* display the names of kanuns */
	yfmessage("Lütfen bekleyiniz");
	for (i=4;i<15*3;i+=3){
		if (fkanun->ifs[i].text[0] == 0)continue;
		if (fkanun->ifs[i+1].text[0] == 0){
			yfmessage("Madde boþ olamaz");
			start = i+1;
			goto kanunyeniden;
		}
		kkanunno = atol(fkanun->ifs[i].text);
		strcpy(kmadde,fkanun->ifs[i+1].text);
		if (kkanunno == 0) continue;
		/* EXEC SQL SELECT kanun
			INTO :kkanun
			FROM kanunlist
			WHERE kanunno = :kkanunno
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select kanun into :b0  from kanunlist where kanunno=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )77;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)kkanun;
  sqlstm.sqhstl[0] = (unsigned int  )256;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&kkanunno;
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

	
		if(SQL_ERROR){
			yfquestion(SQL_MESSAGE);
			break;
		}
		if(SQL_NOTFOUND){
			strcpy(fkanun->ifs[i+2].text,"Kanun bulunamadý");
			cevap = yfquestion("Girdiðiniz kanun kayýtlý deðil. Girmek istiyor musunuz? (e/h)");
			if(cevap != 'e' && cevap != 'E'){
				yfmessage("");
				start = 4;
				goto kanunyeniden;
			}
			b = yenikanun(kkanunno);
			if(b != NULL)strcpy(fkanun->ifs[i+2].text,b);
			else {
				showform(fkanun);
				outputform(fkanun);
				goto kanunyeniden;
			}
			showform(fkanun);
			outputform(fkanun);
			goto kanunyeniden;
		/* asagidaki 99 - ifs[].text degiskenin boyutu - 100
		   karakter. tools/yf.h'den */
		} else strncpy(fkanun->ifs[i+2].text,kkanun,99);
	}
	outputform(fkanun);
	cevap = yfquestion("Girdiðiniz bilgiler doðru mu? (e/h)");
	if(cevap != 'e' && cevap != 'E'){
		yfmessage("");
		start = 4;
		goto kanunyeniden;
	}
	/* okay, kanunlar kontrol edildi, simdi onlari Oracle'a 
	 * aktaralim
	 */
	strcpy(kdaireno, daire);
	strcpy(kesasno, Esasno);
	strip(kesasno);
	strip(kdaireno);
	for (i=4;i<15*3;i+=3){
		if (fkanun->ifs[i].text[0] == 0)continue;
		kkanunno = atol(fkanun->ifs[i].text);
		strcpy(kmadde,fkanun->ifs[i+1].text);
		strip(kmadde);
		if (kkanunno == 0) continue;
		/* EXEC SQL SELECT kanun
			INTO :kkanun
			FROM kanunlist
			WHERE kanunno = :kkanunno
		; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select kanun into :b0  from kanunlist where kanunno=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )100;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)kkanun;
  sqlstm.sqhstl[0] = (unsigned int  )256;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&kkanunno;
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

	
		if(SQL_ERROR || SQL_NOTFOUND){
			yfquestion(SQL_MESSAGE);
			/* EXEC SQL ROLLBACK WORK; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 3;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )123;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			break;
		}
		/* EXEC SQL INSERT INTO kanun VALUES(
			:kdaireno,
			:kesasno,
			'D',
			:kmadde,
			:kkanun,
			:kkanunno
		); */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into kanun values (:b0,:b1,'D',:b2,:b3,:b4)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )138;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)kdaireno;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
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
  sqlstm.sqhstv[2] = (         void  *)kmadde;
  sqlstm.sqhstl[2] = (unsigned int  )16;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)kkanun;
  sqlstm.sqhstl[3] = (unsigned int  )256;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&kkanunno;
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


		if(SQL_ERROR || SQL_NOTFOUND){
			yfquestion(SQL_MESSAGE);
			/* EXEC SQL ROLLBACK WORK; */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )173;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			break;
		}
		nthareket("'%s' kanun girildi",kkanun);
		
	}
	/* EXEC SQL COMMIT WORK; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )188;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	yfquestion("Bilgiler girildi. RETURN basýnýz");

}
/*-------------------------------------------------*/
char *yenikanun(long ikanunno)
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

long kkanunno;
char kkanun[256];
/* EXEC SQL END DECLARE SECTION; */ 


	int stat;

	showform(fyenikanun);
	sprintf(fyenikanun->ifs[0].text, "%ld",ikanunno);
	fyenikanun->ifs[0].edit = 0;
	fyenikanun->ifs[1].text[0] = 0;
	outputform(fyenikanun);
	stat = inputform(fyenikanun);
	if (stat){
		kkanunno = ikanunno;
		strcpy(kkanun, fyenikanun->ifs[1].text);
		/* EXEC SQL INSERT INTO kanunlist VALUES(
			:kkanunno, :kkanun
		); */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into kanunlist values (:b0,:b1)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )203;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&kkanunno;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)kkanun;
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


		if(SQL_ERROR || SQL_NOTFOUND){
			yfquestion(SQL_MESSAGE);
			return NULL;
		}
		nthareket("'%s' yeni kanun girildi",kkanun);
		/* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )226;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	return stat? fyenikanun->ifs[1].text:NULL;
}
/*-------------------------------------------------*/
tuzegir()
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

long kkanunno;
char kkanun[256];

short ind0, ind1, ind2, ind3, ind4, ind5, ind6, ind7;

long count;
long count1;
char nakeddaire[4];
char dresseddaire[5];
/* EXEC SQL END DECLARE SECTION; */ 

	int stat;
	int i;

	strcpy(ftuze->ifs[0].text, daire);
	strcpy(ftuze->ifs[1].text, Esasno);
	strcpy(ftuze->ifs[2].text, Kararno);
	strcpy(ftuze->ifs[3].text, Tarih);
	ftuze->ifs[0].edit=0;
	showform(ftuze);
	outputform(ftuze);
	stat = inputform(ftuze);
	if (stat == 0) return 0;
	strcpy(Esasno, ftuze->ifs[1].text);
	strcpy(Kararno, ftuze->ifs[2].text);
	strcpy(Tarih, ftuze->ifs[3].text);
	
}
