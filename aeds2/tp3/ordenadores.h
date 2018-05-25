//
//  ordenadores.h
//  
//
//  Created by tatiana
//
//

#ifndef ordenadores_h
#define ordenadores_h

#include <stdio.h>

int* bolha (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* selecao (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* insercao (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* shell (int *vetorInicial, int *tamanho, int *vetorOrdenado);
void particao(int *vetorInicial);
int* quick (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* heap (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* merge (int *vetorInicial, int *tamanho, int *vetorOrdenado);
int* radix(int *vetorInicial, int *tamanho, int *v, int base, int num_digitos , int *vetorOrdenado);

#endif /* ordenadores_h */
