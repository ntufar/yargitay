all: kavram1 kavram2 kavram3
include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=sorgu/sorgu@y1
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING  DBMS=V8

kavram1: kavram1.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kavram1.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kavram1.c wwwtools.o -o kavram1 -lcgi 

kavram2: kavram2.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kavram2.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kavram2.c wwwtools.o -o kavram2 -lcgi 

kavram3: kavram3.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kavram3.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kavram3.c wwwtools.o -o kavram3 -lcgi 

clean: 
	rm -f *.lis *.o core kavram1 kavram1.c kavram2 kavram2.c kavram3 kavram3.c
