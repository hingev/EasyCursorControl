
PRG = tcc_test
LIBS = easy_tcc.c

all:
	gcc -o $(PRG) $(PRG).c $(LIBS)
	./$(PRG)
