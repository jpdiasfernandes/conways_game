#ifndef CONWAYS_H
#define CONWAYS_H
int **make_matrix (int N);
int neighbours_alive (int **matrix, int l, int c, int N);
int inbounds (int l, int c, int N);
void play (int **matrix, int N);
void show (int **matrix, int N);
#endif
