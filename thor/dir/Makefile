CFLAGS:=$(BASECFLAGS)
all:	dir.o

dir.o: dir.c
	cc $(CFLAGS) -c  -I$(THORDIR) dir.c

clean:
	rm -f dir.o
