GCCFLAGS=-O0 -Wall -Werror -ansi -pedantic `xml2-config --cflags` -g
LDFLAGS=`xml2-config --libs`
EXE=sqm
OBJ=main.o ship.o

.PHONY		:	all clean


all		:	$(EXE)


$(EXE)		:	$(OBJ) h/types.h
	gcc $(LDFLAGS) -o $(EXE) $(OBJ)


main.o		:	main.c h/types.h
	gcc $(GCCFLAGS) -c $<

ship.o		:	ship.c h/ship.h
	gcc $(GCCFLAGS) -c $<

clean		:
	rm -f $(OBJ) $(EXE)
