#include "map.h"
#pragma warning(disable:4996)
int r = 0;
int c = 0;

#define SMALL_MAP 3
#define MED_MAP 5
#define LARGE_MAP 10
int thread(int** MAT) {

	int counter = 0;
	int n_vuoto = 0;

	int x = 0;
	int y = 0;
	bool ended = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (MAT[i][j] == 0) n_vuoto++;
				printf(" * ");
			}
			printf("\n");
		}
		while(ended == false){
		printf("Inserisci coordinate(x,y): \n");
		printf(" X> ");
		scanf("%d", &x);
		printf(" Y> ");
		scanf("%d", &y);

		if (MAT[x][y] == 1) {
			printf("OPS! Hai trovato una bomba..\n");
			printf("-----------------------------FINE-----------------------------\n");
			ended = true;
		}
		else {
			counter++;
			if (counter < n_vuoto) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {

						if (i == x && j == y) {
							printf(" %d ", MAT[i][j]);
						}
						else
							printf(" * ");
					}
					printf("\n");
				}
			}
			else
			{
				printf("-----------------------------------> Hai vinto!\n");
				ended = true;
			}
		}
	}
	return ended;
}
int** initialize(int* lvl) {

	if (*lvl == 0) r = c = SMALL_MAP;
	if (*lvl == 1) r = c = MED_MAP;
	if (*lvl == 2) r = c = LARGE_MAP;
	int** MAT = (int**)malloc(r * sizeof(int));
	if (MAT) {
		for (int i = 0; i < r; i++) {
			MAT[i] = (int*)malloc(c * sizeof(int));
		}
	}
	else
		printf("---------------------> errore nella creazione della matrice!");

	return MAT;
}
int set_lvl(int** MAT,int *lvl) {
	int set = 0;
	if (*lvl == 0) set = SMALL_MAP;
	else if (*lvl == 1) set = MED_MAP;
	else if (*lvl == 2) set = LARGE_MAP;

	for (int i = 0; i < set; i++) {
		for (int j = 0; j < set; j++) {
			MAT[i][j] = rand() % 2;
		}
	}
	return 0;
}

void stampa(int** MAT,int lvl) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf(" %d ", MAT[i][j]);
		}
		printf("\n");
	}
}
