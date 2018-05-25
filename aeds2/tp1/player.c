//TP0 AEDsII – 2015086298 – Tatiana Santos Camelo de Araujo
//      Pokemon Go     //

#include <stdio.h>
#include <string.h>

#include "maps.h"
#include "player.h"

void player_data(type_player *player, FILE *entrada){
    char infos[20];
    char *aux;
    int i=0;
    
    fscanf(entrada, "%s ", infos);
    
    aux = strtok(infos, ": ,");
    while (aux != NULL){
        if (i == 0){
            strcpy(player->id, aux);
        }
        else if (i == 2){
            player->x = (int)aux;
        }
        else if (i == 3){
            player->y = (int)aux;
        }
        aux = strtok(NULL, ": ,");
        i++;
    }
}

/*
void walkthrough_pokestop(type_player *player, int **map){
    if (map[player->x][player->y] == 6){
            if (player->pokeball == 0){
                player->pokeball = 1;
            }
    }
} */

//explorar(vizinhos)
int ** explore(type_player *player, int **map, int size){
    int i = player->x;
    int j = player->y;
    int x = i;
    int y = j;
    int a;
    int **neighbourhood;
    
    neighbourhood = (int**)malloc(3*sizeof(int*));
    for(a=0; a<3; a++){
        neighbourhood[a] = (int*)malloc(3*sizeof(int));
    }
    
    if (i == 0){
        if (j == 0){
            neighbourhood[i+1][j-1] = 10; //O valor 10 foi escolhido apenas para preencher a matriz, já que não há definição no mapa para este valor
            neighbourhood[i+1][j] = map[x+1][y];
            neighbourhood[i+1][j+1] = map[x+1][y+1];
            neighbourhood[i][j+1] = map[x][y+1];
            neighbourhood[i-1][j+1] = 10;
            neighbourhood[i-1][j] = 10;
            neighbourhood[i-1][j-1] = 10;
            neighbourhood[i][j-1] = 10;
            
        }
        else if(j == size){
            neighbourhood[i+1][j-1] = map[x+1][y-1];
            neighbourhood[i+1][j] = map[x+1][y];
            neighbourhood[i+1][j+1] = 10;
            neighbourhood[i][j+1] = 10;
            neighbourhood[i-1][j+1] = 10;
            neighbourhood[i-1][j] = 10;
            neighbourhood[i-1][j-1] = 10;
            neighbourhood[i][j-1] = map[x-1][y-1];
            
        }
        else{
            neighbourhood[i+1][j-1] = map[x+1][y-1];
            neighbourhood[i+1][j] = map[x+1][y];
            neighbourhood[i+1][j+1] = map[x+1][y+1];
            neighbourhood[i][j+1] = map[x][y+1];
            neighbourhood[i-1][j+1] = 10;
            neighbourhood[i-1][j] = 10;
            neighbourhood[i-1][j-1] = 10;
            neighbourhood[i][j-1] = map[x-1][y-1];
        }
    }
    if (i == size){
        if (j == 0){
            neighbourhood[i+1][j-1] = 10;
            neighbourhood[i+1][j] = 10;
            neighbourhood[i+1][j+1] = 10;
            neighbourhood[i][j+1] = map[x][y+1];
            neighbourhood[i-1][j+1] = map[x-1][y+1];
            neighbourhood[i-1][j] = map[x-1][y];
            neighbourhood[i-1][j-1] = 10;
            neighbourhood[i][j-1] = 10;
            
        }
        else if(j == size){
            neighbourhood[i+1][j-1] = 10;
            neighbourhood[i+1][j] = 10;
            neighbourhood[i+1][j+1] = 10;
            neighbourhood[i][j+1] = 10;
            neighbourhood[i-1][j+1] = 10;
            neighbourhood[i-1][j] = map[x-1][y];
            neighbourhood[i-1][j-1] = map[x-1][y-1];
            neighbourhood[i][j-1] = map[x-1][y-1];
            
        }
        else{
            neighbourhood[i+1][j-1] = 10;
            neighbourhood[i+1][j] = 10;
            neighbourhood[i+1][j+1] = 10;
            neighbourhood[i][j+1] = map[x][y+1];
            neighbourhood[i-1][j+1] = map[i-1][j+1];
            neighbourhood[i-1][j] = map[x-1][y];
            neighbourhood[i-1][j-1] = map[x-1][y-1];
            neighbourhood[i][j-1] = map[x-1][y-1];
        }
    }
    if ((j == 0) && (i != 0) && (i != size)){
        neighbourhood[i+1][j-1] = 10;
        neighbourhood[i+1][j] = map[x+1][y];
        neighbourhood[i+1][j+1] = map[x+1][y+1];
        neighbourhood[i][j+1] = map[x][y+1];
        neighbourhood[i-1][j+1] = map[i-1][j+1];
        neighbourhood[i-1][j] = map[x-1][y];
        neighbourhood[i-1][j-1] = 10;
        neighbourhood[i][j-1] = 10;
    }
    
    if ((j == size) && (i != 0) && (i != size)){
        neighbourhood[i+1][j-1] = map[x+1][y-1];
        neighbourhood[i+1][j] = map[x+1][y];
        neighbourhood[i+1][j+1] = 10;
        neighbourhood[i][j+1] = 10;
        neighbourhood[i-1][j+1] = 10;
        neighbourhood[i-1][j] = map[x-1][y];
        neighbourhood[i-1][j-1] = map[x-1][y-1];
        neighbourhood[i][j-1] = map[x-1][y-1];
        
    }
    return neighbourhood;
}


//Escolha do lugar para ir (maior valor de CP//menor dano)
void where_to(type_player *player, int** neighbourhood, int maior, int maior_x, int maior_y){
    
    int i, j;
    maior = -1000;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if(neighbourhood[i][j] > maior){
                maior = neighbourhood[i][j];
                maior_x = i;
                maior_y = j;
            }
        }
    }
}

//andar(vizinhanca)
void walkthrough (type_player *player, int local, int maior_x, int maior_y, int **neighbourhood, int size){
    
    int i, j, a, b;
    i = maior_x;
    j = maior_y;
    local = neighbourhood[i][j];
    
    if (local == 6){
        if (player->pokeball == 0){
            player->x = i;
            player->y = j;
            player->pokeball = 1;
        }
        
    else if((local > 0) && (local < 6)){
            player->x = i;
            player->y = j;
            player->pokeball--;
            player->pokedex[0] = (player->pokedex[0] + local);
            player->pokedex[local]++;
        }
    else if (local == 0){
            player->x = i;
            player->y = j;
        }
    else if (local < 0){
            player->x = i;
            player->y = j;
            player->pokedex[0] = (player->pokedex[0] + local);
        }
    }
    
    for (a = 0; a <size; a++){
        if(player->path_x[a] != NULL){
            player->path_x[a] = i;
        }
    }
    for (b = 0; b < size; b++){
        if(player->path_y[b] != NULL){
            player->path_y[b] = j;
        }
    }
}

/*
void walkthrough (type_player *player, int valor, int **map, int size){
    
    int **neighbourhood;
    int i, j;
    
    neighbourhood = explore(player, map, size);

    
    cell_points = where_to(player, map, size);
    
        if (player->pokeball == 0){
            for (i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    if(neighbourhood[i][j] == 6){ //Pokestop
                        player->x = i;
                        player->y = j;
                        player->pokeball = 1;
                    }
                }
            }
        }
        else if((cell_points > 0) && (cell_points < 6)){
            player->x = i;
            player->y = j;
            player->pokeball--;
            player->pokedex[0] = (player->pokedex[0] + cell_points);
            player->pokedex[cell_points]++;
        }
        else if (cell_points == 0){
            player->x = i;
            player->y = j;
        }
        else if (cell_points < 0){
            player->x = i;
            player->y = j;
            player->pokedex[0] = (player->pokedex[0] + cell_points);
        }
    
}

//consequencias
 
 if(neighbourhood[i][j] == 6){ //Pokestop
    if (player->pokeball == 0){
        player->x = i;
        player->y = j;
        player->pokeball = 1;
    }
 }

 
 else if((cell_points > 0) && (cell_points < 6)){
 player->x = i;
 player->y = j;
 player->pokeball--;
 player->pokedex[0] = (player->pokedex[0] + cell_points);
 player->pokedex[cell_points]++;
 }
 else if (cell_points == 0){
 player->x = i;
 player->y = j;
 }
 else if (cell_points < 0){
 player->x = i;
 player->y = j;
 player->pokedex[0] = (player->pokedex[0] + cell_points);
 }
 
 
                 //ou..
 
                 if ((i == 0) && (j == 0)){
                 cell_points = neighbourhood[i][j];
                 }
                 else
                 if (neighbourhood[i][j] > cell_points){
                 cell_points = neighbourhood[i][j];
                 }
                 
                 
                //por caso de > = < que 0
                
                if(){
                cell_points = neighbourhood[i][j];
                    if((cell_points > 0) && (cell_points < 6)){
                        player->x = i;
                        player->y = j;
                        player->pokeball--;
                        player->pokedex[0] = (player->pokedex[0] + cell_points);
                        player->pokedex[cell_points]++;
                        }
                    else if (cell_points == 0){
                        player->x = i;
                        player->y = j;
                    }
                    else if (cell_points < 0){
                        player->x = i;
                        player->y = j;
                        player->pokedex[0] = (player->pokedex[0] + cell_points);
                    }
                 }
                
                //por caso de pontuacao
                
                if(neighbourhood[i][j] == 5){ //Pikachu
                    player->x = i;
                    player->y = j;
                    player->pokeball--;
                    player->pokedex[0] = (player->pokedex[0] + 5);
                    player->pokedex[5]++;
                }
                else if(neighbourhood[i][j] == 4){ //Eevee
                    player->x = i;
                    player->y = j;
                    player->pokeball--;
                    player->pokedex[0] = (player->pokedex[0] + 4);
                    player->pokedex[4]++;
                }
                else if(neighbourhood[i][j] == 3){ //Magmar
                    player->x = i;
                    player->y = j;
                    player->pokeball--;
                    player->pokedex[0] = (player->pokedex[0] + 3);
                    player->pokedex[3]++;
                }
                else if(neighbourhood[i][j] == 2){ //Alakazam
                    player->x = i;
                    player->y = j;
                    player->pokeball--;
                    player->pokedex[0] = (player->pokedex[0] + 2);
                    player->pokedex[2]++;
                }
                else if(neighbourhood[i][j] == 1){ //Dragonite
                    player->x = i;
                    player->y = j;
                    player->pokeball--;
                    player->pokedex[0] = (player->pokedex[0] + 1);
                    player->pokedex[1]++;
                }
                else if(neighbourhood[i][j] == 0){ //Célua vazia
                    player->x = i;
                    player->y = j;
                }
                else if(neighbourhood[i][j] == -1){ //Começa os casos em que player recebe dano de 1 a 12
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 1);
                 }
                 
                 else if(neighbourhood[i][j] == -2){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 2);
                 }
                 
                 else if(neighbourhood[i][j] == -3){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 3);
                 }
                 
                 else if(neighbourhood[i][j] == -4){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 4);
                 }
                 
                 else if(neighbourhood[i][j] == -5){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 5);
                 }
                 
                 else if(neighbourhood[i][j] == -6){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 6);
                 }
                 
                 else if(neighbourhood[i][j] == -7){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 7);
                 }
                 
                 else if(neighbourhood[i][j] == -8){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 8);
                 }
                 
                 else if(neighbourhood[i][j] == -9){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 9);
                 }
                 
                 else if(neighbourhood[i][j] == -10){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 10);
                 }
                 
                 else if(neighbourhood[i][j] == -11){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 11);
                 }
                 
                 else if(neighbourhood[i][j] == -12){
                    player->x = i;
                    player->y = j;
                    player->pokedex[0] = (player->pokedex[0] - 12);
                 }
                 
                 
                }*/

//caminho_percorrido()
void print_path(type_player *player, int **map, int size){
    
    int i;
    int path[size*size];
    
    for (i = 0; i < size; i++){
        path[2*i + 0] = player->path_x[i];
        path[2*i + 1] = player->path_y[i];
    }
    
    for(i = 0; i < size; i++){
            printf("%d ", path[i]);
    }
    
}


void score_winner(type_player *player, int players_on_game){
    type_player *winner;
    int i;
    
    winner->pokedex[0] = -1000;
    while (winner->pokedex[0] > player->[0]){
        for(i = 0; i < players_on_game, i++){
            winner = players_on_game[i];
            
        }
    }
    
    
}
