.EXPORT_ALL_VARIABLES:

#BASECFLAGS := -g -O2     for DEBUG
BASECFLAGS := -O2 -g

TOPDIR  := $(shell if [ "$$PWD" != "" ]; then echo $$PWD; else pwd; fi)

all: thorall emsalall emsalgirall emsalaktarall ceza hukuk sorgu wwwall servletsall

ceza: $(TOPDIR)/evrak/ceza
	make -C $(TOPDIR)/evrak/ceza

hukuk: $(TOPDIR)/evrak/hukuk
	make -C $(TOPDIR)/evrak/hukuk

sorgu: $(TOPDIR)/evrak/sorgu
	make -C $(TOPDIR)/evrak/sorgu

emsalall: $(TOPDIR)/emsal
	make -C $(TOPDIR)/emsal

emsalgirall: $(TOPDIR)/emsalgir
	make -C $(TOPDIR)/emsalgir

emsalaktarall: $(TOPDIR)/emsalaktar
	make -C $(TOPDIR)/emsalaktar

wwwall: $(TOPDIR)/www
	make -C $(TOPDIR)/www
	make -C $(TOPDIR)/kavramwww
	make -C $(TOPDIR)/kanunwww

toolsall:
	make -C $(TOPDIR)/tools

thorall:
	make -C $(TOPDIR)/thor libthor.a

servletsall:
	make -C $(TOPDIR)/servlets

clean:
	make -C $(TOPDIR)/evrak/ceza clean
	make -C $(TOPDIR)/evrak/hukuk clean
	make -C $(TOPDIR)/evrak/sorgu clean
	make -C $(TOPDIR)/emsal clean
	make -C $(TOPDIR)/emsalgir clean
	make -C $(TOPDIR)/tools clean
	make -C $(TOPDIR)/www clean
	make -C $(TOPDIR)/kavramwww clean
	make -C $(TOPDIR)/kanunwww clean
	make -C $(TOPDIR)/emsalaktar clean
	make -C $(TOPDIR)/thor clean
	make -C $(TOPDIR)/servlets clean
