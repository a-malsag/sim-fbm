P=simbm
OBJECTS=
CFLAGS= -Wall -g -O3
LDLIBS= `pkg-config --libs gsl`
CC=gcc

$(P): $(OBJECTS)

remove:
	rm $(P)
