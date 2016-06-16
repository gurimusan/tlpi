CC = gcc
LDDIR = -L$(ROOT)/lib
LDLIBS = $(LDDIR) -ltlpi
CFLAGS = -std=c99 \
				 -D_XOPEN_SOURCE=600 \
				-D_DEFAULT_SOURCE \
				-g -I$(ROOT)/include \
				-pedantic \
				-Wall \
				-W \
				-Wmissing-prototypes \
				-Wno-sign-compare \
				-Wno-unused-parameter
