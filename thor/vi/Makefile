CFLAGS:=$(BASECFLAGS)

all: vi.o

vi.o: vi.c
	cc $(CFLAGS)  -c  -I$(THORDIR) vi.c

clean:
	rm -f vi.o
