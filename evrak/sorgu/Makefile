all: sorgu

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=sorgu/sorgu@y1
TOOLS=$(TOPDIR)/tools
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V7 

sorgu: sorgu.o sorgu1.o initsorgu.o $(TOOLS)/yf.o $(TOOLS)/tools.o
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) sorgu.o $(TOOLS)/yf.o  initsorgu.o sorgu1.o $(TOOLS)/tools.o -o sorgu -lcurses 

sorgu.o: sorgu.c
	$(CC) $(CFLAGS) -I$(TOOLS) sorgu.c -c -o sorgu.o

sorgu1.o: sorgu1.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=sorgu1.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) sorgu1.c -c -o sorgu1.o

initsorgu.o: initsorgu.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=initsorgu.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  initsorgu.c -c -o initsorgu.o

clean: 
	rm -f sorgu  *.o *.lis sorgu1.c initsorgu.c core
