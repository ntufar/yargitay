all: kanun1 kanun2 kanun3 kanun4
include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=sorgu/sorgu@y1
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING  DBMS=V8

kanun1: kanun1.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kanun1.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kanun1.c wwwtools.o -o kanun1 -lcgi 

kanun2: kanun2.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kanun2.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kanun2.c wwwtools.o -o kanun2 -lcgi 

kanun3: kanun3.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kanun3.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kanun3.c wwwtools.o -o kanun3 -lcgi 

kanun4: kanun4.pc wwwtools.o
	$(ORACLE_HOME)/bin/proc  $(PROCPLSFLAGS) iname=kanun4.pc
	$(CC) $(CFLAGS) $(PRECOMPPUBLIC)  -L$(LIBHOME) -L. $(LLIBSQL) $(TTLIBS)  kanun4.c wwwtools.o -o kanun4 -lcgi 

clean: 
	rm -f *.lis *.o core kanun1 kanun1.c kanun2 kanun2.c kanun3 kanun3.c kanun4 kanun4.c 
