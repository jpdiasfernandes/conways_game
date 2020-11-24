#include "conways_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 50
int main () {
	int **matrix = make_matrix(N);
	int i,j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			if (i%3 == 0 || j%5 == 0) matrix[i][j] = 1;
			else matrix[i][j] = 0;
			printf("%d ", matrix[i][j]);
		}
		putchar('\n');
	}
	matrix[23][34] = 1;
	matrix[23][33] = 1;
	matrix[22][34] = 1;
	matrix[21][32] = 1;
	
	do {
		system("clear");
		play(matrix, N);
		show(matrix, N);
		sleep(1);
	} while (1);

	return 0;
}
