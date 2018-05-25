//
//  operacoes.h
//  
//
//  Created by tatiana
//
//

#ifndef operacoes_h
#define operacoes_h

#include <stdio.h>


//Declaração das funções
void imprimeArray(int array[], int size);
void copiaString(int origem[], int *destino, int tamanhoString);
void resolve(int nivel, int valores[], int indiceValores, int operadores[], int indiceOperadores, int indice, int tamanhoString,char *stringOriginal,int resultado, int ultimoNivel);

#endif /* operacoes_h */
