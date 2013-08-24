all: CezaSorgu.class HukukSorgu.class EmsalCtx.class EmsalKavram.class EmsalKanun.class

ENCODING=ISO8859_9

CezaSorgu.class: CezaSorgu.java
	javac -encoding $(ENCODING) CezaSorgu.java
HukukSorgu.class: HukukSorgu.java
	javac -encoding $(ENCODING) HukukSorgu.java
EmsalCtx.class: EmsalCtx.java
	javac -encoding $(ENCODING) EmsalCtx.java
EmsalKavram.class: EmsalKavram.java
	javac -encoding $(ENCODING) EmsalKavram.java
EmsalKanun.class: EmsalKanun.java
	javac -encoding $(ENCODING) EmsalKanun.java


clean:
	rm -f *.class
