//TP0 AEDsII – 2015086298 – Tatiana Santos Camelo de Araujo
//      Pokemon Go     //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef header_h
#define header_h


//TAD player (jogador)

typedef struct{
    
    char id[20];
    int pokeball;
    int x, y; //Variáveis para a localização inicial do jogador na matrix
    int pokedex[6];
    int path_x[100];
    int path_y[100];
    
}type_player;


void player_data(type_player *player, FILE *entrada);

int ** explore(type_player *player, int **map, int size);

void where_to(type_player *player, int** neighbourhood, int maior, int maior_x, int maior_y);

void walkthrough (type_player *player, int local, int maior_x, int maior_y, int **neighbourhood, int size);

int print_path(type_player *player, int **map, int size);


#endif /* header_h */
