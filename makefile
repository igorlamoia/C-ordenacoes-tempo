IDIR=bibliotecas
CC=gcc
CFLAGS=-I$(IDIR)
 
ODIR=_objs
LDIR =bibliotecas

LIBS=-lm

_DEPS = menu.h metodosOrdenacao.h inicializacao.h escolhas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = menu.o metodosOrdenacao.o inicializacao.o escolhas.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: bibliotecas/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o build/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ rm build/main

run:
	./build/main