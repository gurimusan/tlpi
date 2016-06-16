ROOT = ..

include $(ROOT)/Makefile.inc

all = libtlpi.a

libtlpi.a: *.c ename.c.inc
	${CC} -c -g ${CFLAGS} *.c
	rm -f libtlpi.a
	ar rs libtlpi.a *.o

ename.c.inc :
	sh Build_ename.sh > ename.c.inc
	echo 1>&2 "ename.c.inc built"

clean:
	rm -f *.o ename.c.inc libtlpi.a
