//
//  operacoes.c
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

void imprimeArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++){ //O valor 1 corresponde a multiplicação (*) e o 0 corresponde a soma (+)
        if(array[i]){
            printf("*");
        }
        else{
            printf("+");
        }
    }
    printf("\n");
}


void copiaString(int origem[], int *destino, int tamanhoString){
    int i;
    for (i = 0; i < tamanhoString; i++){
        destino[i] = origem[i];
    }
}


void resolve(int nivel, int valores[], int indiceValores, int operadores[], int indiceOperadores, int indice, int tamanhoString,char *stringOriginal,int resultado, int ultimoNivel){
    
    if(nivel > ultimoNivel){
        
        if(valores[0] == resultado){
            imprimeArray(operadores, ultimoNivel);
        }
        return;
    }
    
    
    char *novaStringOriginal = malloc(201*sizeof(char));
    strcpy(novaStringOriginal, stringOriginal);
    
    
    int novoIndice = 0, valorA, valorB;
    
    
    char *numeroConversao = strtok(novaStringOriginal, " ");
    while(numeroConversao != NULL){
        if(novoIndice >= indice){
            
            if(numeroConversao[0] == '?'){
                break;
            }
            valores[indiceValores] = atoi(numeroConversao);
            indiceValores++;
        }
        numeroConversao = strtok(NULL," ");
        novoIndice++;
    }
    
    
    valorA = valores[indiceValores-2], valorB = valores[indiceValores - 1];
    

    int valoresSoma[tamanhoString], valoresMultiplicacao[tamanhoString], operadoresSoma[tamanhoString], operadoresMultiplicacao[tamanhoString];
    

    copiaString(valores, valoresSoma,tamanhoString);
    copiaString(valores, valoresMultiplicacao,tamanhoString);
    
    
    copiaString(operadores, operadoresSoma,tamanhoString);
    copiaString(operadores, operadoresMultiplicacao,tamanhoString);
    
    
    valoresSoma[indiceValores - 2] = valorA+valorB;
    //Adiciona o operador '+' no array de operadores
    operadoresSoma[indiceOperadores] = 0;
    resolve(nivel+1, valoresSoma, indiceValores-1, operadoresSoma, indiceOperadores+1, novoIndice+1, tamanhoString, stringOriginal, resultado, ultimoNivel);
    
    
    valoresMultiplicacao[indiceValores - 2] = valorA*valorB;
    //Adiciona o operador '*' no array de operadores
    operadoresMultiplicacao[indiceOperadores] = 1;
    resolve(nivel+1, valoresMultiplicacao, indiceValores-1, operadoresMultiplicacao, indiceOperadores+1, novoIndice+1, tamanhoString, stringOriginal, resultado, ultimoNivel);
}
