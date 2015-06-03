
PRG = tcc_test
PRG = test_2
LIBS = easy_tcc.c

all:
	gcc -o $(PRG) $(PRG).c $(LIBS)
	./$(PRG)
