all: emsalgir

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=emsal/emsal@y1
TOOLS=$(TOPDIR)/tools
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V7 

emsalgir: emsalgir.o $(TOOLS)/tools.o $(TOOLS)/yf.o initemsalgir.o emsalgir1.o
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) $(TOOLS)/yf.o emsalgir.o initemsalgir.o $(TOOLS)/tools.o emsalgir1.o -o emsalgir -lcurses 


initemsalgir.o: initemsalgir.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=initemsalgir.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  initemsalgir.c -c -o initemsalgir.o

emsalgir1.o: emsalgir1.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=emsalgir1.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  emsalgir1.c -c -g -o emsalgir1.o



emsalgir.o: emsalgir.c
	$(CC) $(CFLAGS) -I$(TOOLS) -c emsalgir.c

clean: 
	rm -f emsalgir  *.o *.lis emsalgir1.c initemsalgir.c core
