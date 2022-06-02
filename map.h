#ifndef MAP_H
#define MAP_H

#define MAX_LENGHT_NAME 20
#define FIORE 0;
#define BOMBA 1;

#include <stdio.h>
#include <stdlib.h>

int **initialize(int *lvl);
int set_lvl(int** MAT, int *lvl);

int thread(int** MAT);
void stampa(int** MAT,int lvl);


#endif