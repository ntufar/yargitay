CFLAGS:=$(BASECFLAGS)

all: text.o line.o paragraph.o

text.o: text.c
	cc $(CFLAGS) -I$(THORDIR) -c text.c

line.o: line.c
	cc $(CFLAGS) -I$(THORDIR) -c line.c

paragraph.o: paragraph.c
	cc $(CFLAGS) -I$(THORDIR) -c paragraph.c

clean:
	rm -f text.o line.o paragraph.o

test: t.c line.c paragraph.c line.h paragraph.h
	cc -o t t.c line.c paragraph.c -I../






	

