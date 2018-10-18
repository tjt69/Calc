CC	=	gcc
COMPILE	=	$(CC)
#FLAGS	=	$(-g -Wall -o)

all:	calc

calc:	calc.c calc.h
	$(COMPILE) -g -Wall -o calc calc.c calc.h

clean:
	rm -rf *.o calc
