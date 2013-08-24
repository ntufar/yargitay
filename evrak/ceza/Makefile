all: ceza

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=ceza/ceza@y1
TOOLS=$(TOPDIR)/tools
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V7 

ceza: ceza.c ceza1.o ceza5.o initceza.o $(TOOLS)/yf.o $(TOOLS)/tools.o
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) ceza.c $(TOOLS)/yf.o  initceza.o ceza1.o ceza5.o $(TOOLS)/tools.o -o ceza -lcurses 

#yf.o: yf.c
#	$(CC) yf.c -c -o yf.o
ceza.o: ceza.c
	$(CC) $(CFLAGS) -I$(TOOLS) ceza.c -c -o ceza.o

ceza1.o: ceza1.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=ceza1.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) ceza1.c -c -o ceza1.o

initceza.o: initceza.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=initceza.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  initceza.c -c -o initceza.o

ceza5.o: ceza5.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=ceza5.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) ceza5.c -c -o ceza5.o

toolsall: $(TOOLS)
	make -C $(TOOLS)

clean: 
	rm -f ceza *.o *.lis ceza1.c initceza.c ceza5.c core
