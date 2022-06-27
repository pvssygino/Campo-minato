#include <stdio.h>
#include "map.h"
#define MAX_LENGHT_NAME 20
#define MAX_SIZE 10

#pragma warning(disable:4996)
int main() {
	enum { FACILE, MEDIO, DIFFICILE };

	int** map;

	char player_name[20];
	int lvl = 0;
	printf("Benvenuto nel gioco di PRATO FIORITO!\n");
	printf("Inserisci il tuo nome: \n");
	printf(" >");

	scanf("%s", player_name);

	printf("Seleziona un livello: \n");
	printf(" 0. (FACILE)\n");
	printf(" 1. (MEDIO)\n");
	printf(" 2. (DIFFICILE)\n");
	printf(" >");
	scanf("%d", &lvl);

	map = initialize(&lvl);

	
		set_lvl(map, &lvl);

		int done = thread(map);
		if (done == 1) {
			stampa(map, lvl);
		}

		free(*map);
	return 0;
}
