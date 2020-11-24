conways_game : main.o conways_game.o
	gcc -o conways_game main.o conways_game.o

main.o : main.c conways_game.c conways_game.h
	gcc -c main.c

conways_game.o: conways_game.c conways_game.h
	gcc -c conways_game.c


