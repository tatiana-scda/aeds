//TP0 AEDsII – 2015086298 – Tatiana Santos Camelo de Araujo
//      Pokemon Go     //

#include <stdio.h>

#include "maps.h"
#include "player.h"

void map_fill (int size, int **map, FILE *entrada){
    
    int i, j;
    
    for (i=0; i < size; i++){
        for (j=0; j < size; j++){
            fscanf(entrada, "%d ", &map[i][j]);
        }
    }
}
