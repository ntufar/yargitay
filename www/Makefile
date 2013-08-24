all: cezasorgu hukuksorgu
include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=sorgu/sorgu@y1
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING  DBMS=V8

hukuksorgu: hukuksorgu.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=hukuksorgu.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  hukuksorgu.c wwwtools.o -o hukuksorgu -lcgi 

cezasorgu: cezasorgu.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc $(PROCPLSFLAGS) iname=cezasorgu.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  cezasorgu.c wwwtools.o -o cezasorgu -lcgi

clean: 
	rm -f cezasorgu.c cezasorgu hukuksorgu.c hukuksorgu cezasorgu.lis hukuksorgu.lis
