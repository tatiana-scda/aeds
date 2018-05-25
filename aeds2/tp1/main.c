//TP0 AEDsII – 2015086298 – Tatiana Santos Camelo de Araujo
//      Pokemon Go     //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "maps.h"
#include "player.h"

//COMPILAR: gcc *.c -Wall -o main

int main(int argc, char *argv[]){
    
    int players_total;
    type_player *players_on_game;
    int **map;
    int i;
    int size;
    type_player player;
    
    FILE *entrada;
    FILE *saida;
    
    //Inicialmente, o programa vai conferir se ambos arquivos (entrada e saida) podem ser lidos.
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL){
        printf("Erro ao ler arquivo de entrada\n");
    }
    
    saida = fopen("saida.txt", "w");
    if (saida == NULL){
        printf("Erro ao criar arquivo de saida\n");
    }

    //Ler e salvar o tamanho da matriz do mapa
    fscanf(entrada, "%d", &size);
    map = (int**)malloc(size*sizeof(int*));
    for(i=0; i<size; i++){
        map[i] = (int*)malloc(size*sizeof(int));
    }
    map_fill (size, map, entrada);
    
    //Ler e salvar o número de jogadores
    fscanf(entrada, "%d", &players_total);
    players_on_game = (type_player *)malloc(players_total*sizeof(type_player));

    player_data(*player, *entrada);
    
    
    
    
    fclose(entrada);
    fclose(saida);
    
    return 0;
}

