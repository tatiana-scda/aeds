//
//  main.c
//  
//
//  Created by tatiana
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "operacoes.h"

int main() {
    
    char stringOriginal[201];
    int resultado = 0, tamanhoString = 0, ultimoNivel = 0, i = 0;
    int valores[201], operadores[201];
    
    fgets(stringOriginal, 201, stdin);
    scanf("%d", &resultado);
    
    while(stringOriginal[i] != '\0'){
        if(stringOriginal[i] == ' '){
            tamanhoString++;
        }
        if(stringOriginal[i] == '?'){
            ultimoNivel++;
        }
        i++;
    }
    
    resolve(1, valores, 0,operadores, 0, 0,tamanhoString+1,stringOriginal,resultado, ultimoNivel);
    
    return 0;
}
