//
//  gerador.c
//  
//
//  Created by tatiana
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gerador.h"

//Gerador de vetor

int* aleatorio (int *tamanho){
    int *vetorInicial[tamanho];
    int i;
    int max = 1000; //numero aleatórios escolhidos até 1000
    
    for (i = 0; i < tamanho-1; i++){
        vetorInicial[i] = rand() % max + 1;
    }
    
    return vetorInicial;
}

int* ordenado (int *tamanho){
    int *vetorInicial[tamanho];
    int i, inicial;
    int max = 1000;
    
    inicial = rand() % max + 1;
    vetorInicial[0] = inicial;
    
    for (i = 1; i < tamanho-1; i++){
        vetorInicial[i] = vetorInicial[i] + 1;
    }
    
    return vetorInicial;
}

/*
int* quaseOrdenado (int *tamanho){
    
 return vetorInicial;
}
*/

int* inverso (int *tamanho){
    int *vetorInicial[tamanho];
    int i, inicial;
    int max = 1000;
    
    inicial = rand() % max + 1;
    vetorInicial[0] = inicial;
    
    if (inicial > tamanho){
        for (i = 1; i < tamanho-1; i++){
            vetorInicial[i] = vetorInicial[i] - 1;
        }
    }
    else inverso(*tamanho);
    
    return vetorInicial;
}

