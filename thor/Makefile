.EXPORT_ALL_VARIABLES:
CFLAGS:=$(BASECFLAGS)
THORDIR  := $(shell if [ "$$PWD" != "" ]; then echo $$PWD; else pwd; fi)

DEPS = visual textual directory globals.o
OBJS = $(THORDIR)/vi/vi.o $(THORDIR)/text/text.o $(THORDIR)/text/line.o $(THORDIR)/dir/dir.o $(THORDIR)/text/paragraph.o

all: libthor.a

#libthor.a: textual video directory globals.o
libthor.a: ${DEPS}
	ar cr libthor.a ${OBJS} globals.o

#globals.o: globals.c
	#cc -c globals.c

thor: textual video directory main.o globals.o
	cc $(CFLAGS) ${OBJS} -I $(THORDIR) main.c globals.c -o thor -lcurses

textual: $(THORDIR)/text
	make -C $(THORDIR)/text

visual: $(THORDIR)/vi
	make -C $(THORDIR)/vi

directory: $(THORDIR)/dir
	make -C $(THORDIR)/dir

clean:
	make -C $(THORDIR)/text clean
	make -C $(THORDIR)/vi clean
	make -C $(THORDIR)/dir clean

	rm -f thor  *.o core libthor.a
