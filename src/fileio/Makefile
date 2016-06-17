ROOT = ../..

include $(ROOT)/Makefile.inc

PROGS = copy seek_io

all : ${PROGS}

%: %.c $(ROOT)/lib/libtlpi.a
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -fr $(PROGS) *.out *.o *.dSYM
