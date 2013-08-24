all: aktar

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=emsal/emsal@y1
TOOLS=$(TOPDIR)/tools
THOR=$(TOPDIR)/thor

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V7 

aktar: aktar.o $(TOPDIR)/thor
	$(CC) -I$(TOOLS) -I$(THOR) -L$(THOR) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) aktar.o -o aktar $(TOOLS)/yf.o $(TOOLS)/tools.o -lthor -lcurses



aktar.o: aktar.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) include=$(THOR) $(PROCPLSFLAGS) iname=aktar.pc
	$(CC) -I$(TOOLS) -I$(THOR) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  aktar.c -c -g -o aktar.o



clean: 
	rm -f aktar  *.o *.lis aktar.c core
