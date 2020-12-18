#include "conways_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define N 512

int main () {
	int **matrix = make_matrix(N);
	int i,j;
	time_t t;

	srand((unsigned) time(&t));
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			matrix[i][j] = (rand() % 11 == 1)? 1 : 0;
			printf("%d ", matrix[i][j]);
		}
		putchar('\n');
	}
	
	do {
		system("clear");
		play(matrix, N);
		show(matrix, N);
		sleep(1);
	} while (1);

	return 0;
}
