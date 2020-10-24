P=test_simbm
OBJECTS= simbm.o
CFLAGS= -Wall -g -O3 -DMODELONE_LIB
LDLIBS= `pkg-config --libs gsl`
CC=gcc

$(P): $(OBJECTS)

remove:
	rm $(P)
