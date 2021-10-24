#include <stdio.h>
#include <stdlib.h>
#include "conways_game.h"

int **make_matrix (int N) {
	int i,j;
	int **matrix = malloc(sizeof(int *) * N);
	for (i = 0; i < N; i++) {
		matrix[i] = malloc(sizeof(int) * N);
	}
	return matrix;
}
int neighbours_alive (int **matrix, int l, int c, int N) {
	int i,j, r = 0;
	for (i = l-1; i <= l + 1; i++)
		for (j = c-1; j <= c+1; j++)
			if ((i!=l || j != c) && matrix[round_robin(i,N)][round_robin(j,N)]) r++; 
	return r;
}

int round_robin(int n, int N) {
	int r = 0;
	if (n < 0) (n += N);
	r = n%N;
	return r;
}

void play (int **matrix, int N) {
	int i,j, state, neighbours;
	int **copy = make_matrix(N);
	
	for (i = 0; i < N/2; i++)
		for (j = 0; j < N/2; j++)
			copy[i][j] = matrix[i][j];
	
	for (i = 0; i < N/2; i++)
		for (j = N/2; j < N; j++)
			copy[i][j] = matrix[i][j];



	for (i = N/2; i < N; i++)
		for (j = 0; j < N/2; j++)
			copy[i][j] = matrix[i][j];

	for (i = N/2; i < N; i++)
		for (j = N/2; j < N; j++)
			copy[i][j] = matrix[i][j];





	for (i = 0; i < N/2; i++) {
		for (j = 0; j < N; j++) {
			state = copy[i][j];		
			neighbours = neighbours_alive(copy, i, j, N);
			if (!state && neighbours == 3) matrix[i][j] = 1;  
			else if (state && neighbours != 2 && neighbours != 3) matrix[i][j] = 0;
		}
	}
	for (i = N/2; i < N; i++) {
		for (j = 0; j < N; j++) {
			state = copy[i][j];		
			neighbours = neighbours_alive(copy, i, j, N);
			if (!state && neighbours == 3) matrix[i][j] = 1;  
			else if (state && neighbours != 2 && neighbours != 3) matrix[i][j] = 0;
		}
	}








}

void show (int **matrix, int N) {
	int i,j;

	for (i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
        		if (matrix[i][j] == 0) putchar(' ');
			else putchar('O');
			putchar(' ');
        	}
		putchar('\n');
	}
}
