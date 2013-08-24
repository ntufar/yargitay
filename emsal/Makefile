all: emsal

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=emsal/emsal@y1
TOOLS=$(TOPDIR)/tools
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V8 

emsal: emsal.o $(TOOLS)/tools.o $(TOOLS)/yf.o initemsal.o emsal1.o
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) $(TOOLS)/yf.o emsal.o initemsal.o $(TOOLS)/tools.o emsal1.o -o emsal -lcurses 


initemsal.o: initemsal.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=initemsal.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  initemsal.c -c -o initemsal.o

emsal1.o: emsal1.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=emsal1.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  emsal1.c -c -g -o emsal1.o



emsal.o: emsal.c
	$(CC) -I$(TOOLS) -c emsal.c

clean: 
	rm -f emsal  *.o *.lis emsal1.c initemsal.c core





	

