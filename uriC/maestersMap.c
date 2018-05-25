//
//  maestersMap.c
//  
//
//  Created by tatiana on 30/04/17.
//https://www.urionlinejudge.com.br/judge/en/problems/view/1855
//gcc maestersMap.c -Wall -o maestersMap
/*
 case 'v':
 break;
 case '>':
 break;
 case '<':
 break;
 case '^':
 break;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caminha(char **matriz, int **noLoop, char comando, int x, int y, int i, int j){
    
    if(noLoop[i][j] == 1)
        return 0;
    
    noLoop[i][j] = 1; //passei por esta casa
    
    switch(matriz[i][j]){
        case '.':
            break;

        case '*':
            printf("*\n");
            return 1;
            break;
        
        default:
            comando = matriz[i][j];
            break;
    }
    
    if(comando == '^'){
        if (i == 0){
        }
        else
            return caminha(matriz, noLoop, comando, x, y, i-1, j);
    }
    else if(comando == '<'){
        if(j == 0){
        }
        else
            return caminha(matriz, noLoop, comando, x, y, i, j-1);
    }
    else if (comando == '>'){
        if(j == x){
        }
        else
            return caminha(matriz, noLoop, comando, x, y, i, j+1);
    }
    else if (comando == 'v'){
        if(i == y){
        }
        else
            return caminha(matriz, noLoop, comando, x, y, i+1, j);
    }
    return 0;
}

int main() {
    int x, y;
    int i = 0, j = 0, flag = 0;
    char **map;
    int **noLoop;
    
    scanf("%d", &x);
    scanf("%d", &y);
    
    map = (char**)calloc (y,sizeof(char*));
    
    for (i = 0; i < y; i++){ //i refetente a y; j referente a x
        map[i] = (char*)calloc (x,sizeof(char));
    }
    
    noLoop = (int**)calloc (y,sizeof(int*));
    for (i = 0; i < y; i++)
        noLoop[i] = (int*)calloc (x,sizeof(int));
    
    //aloquei
    
    //salva mapa
    for (i = 0; i < y; i++){
        j = 0;
        scanf("%c", &map[i][j]); //dump
        for(j = 0; j < x; j++){
            scanf("%c", &map[i][j]);
            if (map[i][j] == '*')
                flag = 1;
        }
    }
    /*
    //imprime
    for (i = 0; i < y; i++){
        
        for(j = 0; j < x; j++)
            printf("%c", map[i][j]);
            
        printf("\n");
    }
    */
    
    if (flag == 0){
        printf("!\n");
    }
    
    else {
        if(caminha(map, noLoop, 'a', x, y, 0, 0) == 0){
            printf("!\n");
        }
    }
    
    //desalocar
    for (i = 0; i < y; ++i){
        free(map[i]);
    }
    free(map);
}
