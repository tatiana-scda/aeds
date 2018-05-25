//
//  utils.h
//
//
//  Created by tatiana on 07/07/17.
//
//

#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <stdlib.h>
#include "guloso.h"
#include "forcaBruta.h"
#include "dinamico.h"

int colisaoNumero (tipoPares *vetor, int bar, int residencia, int tamanho);
int maxPosVetor(int *vetor, int tamanho);
int colisaoTrue(tipoPares *vetor, int bar, int residencia, int tamanho, int *Pilha);
void iniciaArvore(tipoArvore *arvore);
void liberaArvore(tipoArvore arvore);
int compareC (const void * a, const void * b);
int compareB (const void * a, const void * b);

#endif /* utils_h */
