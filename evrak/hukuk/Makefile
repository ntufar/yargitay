all: hukuk

include $(ORACLE_HOME)/plsql/lib/env_plsql.mk
USERID=hukuk/hukuk@y1
TOOLS=$(TOPDIR)/tools
CFLAGS=$(BASECFLAGS)

.SUFFIXES: .pc .c .o

PROCPLSFLAGS= sqlcheck=full userid=$(USERID) CHAR_MAP=STRING DBMS=V7 


hukuk: hukuk.c hukuk1.o hukuk5.o inithukuk.o $(TOOLS)/yf.o $(TOOLS)/tools.o
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) $(LLIBSQL) $(TTLIBS) hukuk.c $(TOOLS)/yf.o  inithukuk.o hukuk1.o hukuk5.o $(TOOLS)/tools.o -o hukuk -lcurses 

hukuk.o: hukuk.c
	$(CC) $(CFLAGS) -I$(TOOLS) hukuk.c -c -o hukuk.o

hukuk1.o: hukuk1.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=hukuk1.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) hukuk1.c -c -o hukuk1.o

inithukuk.o: inithukuk.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=inithukuk.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME)  inithukuk.c -c -o inithukuk.o

hukuk5.o: hukuk5.pc
	$(ORACLE_HOME)/bin/proc include=$(TOOLS) $(PROCPLSFLAGS) iname=hukuk5.pc
	$(CC) -I$(TOOLS) $(CFLAGS) $(PRECOMPPUBLIC) -L$(LIBHOME) hukuk5.c -c -o hukuk5.o

toolsall: $(TOOLS)
	make -C $(TOOLS)

clean: 
	rm -f hukuk  *.o *.lis hukuk1.c inithukuk.c hukuk5.c core
