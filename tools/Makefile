CFLAGS=$(BASECFLAGS)

all: yf.o tools.o

yf.o: yf.c
	cc -c $(CFLAGS) yf.c

tools.o: tools.c
	cc -c $(CFLAGS) tools.c
clean:
	rm -f yf.o tools.o
