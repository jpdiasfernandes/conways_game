conways_game : main.o conways_game.o
	gcc -o conways_game main.o conways_game.o

main.o : src/main.c src/conways_game.c src/conways_game.h
	gcc -c src/main.c

conways_game.o: src/conways_game.c src/conways_game.h
	gcc -c src/conways_game.c


