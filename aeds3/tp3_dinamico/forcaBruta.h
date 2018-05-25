//
//  forcaBruta.h
//
//
//  Created by tatiana on 21/06/17.
//
//

#ifndef forcaBruta_h
#define forcaBruta_h

#include "utils.h"

typedef struct tipoPares{
    int bar;
    int casa;
    int colisao;
    int *quemColide;
}tipoPares;

typedef struct tipoNodo *apontador;

typedef struct tipoNodo *tipoArvore;

typedef struct tipoNodo{
    apontador coloca, naoColoca; //gerencia a arvora como um lado colocando a bandeira e o outro não colocando
    int flags;
}tipoNodo;

void mainForcaBruta(tipoPares *vetor, int tamanho);
int maior(tipoArvore arvore);
void forcaBruta(tipoPares *vetor, tipoArvore arvore, int profundidade, int *pilha, int direcao, int tamanho);

#endif /* forcaBruta_h */
