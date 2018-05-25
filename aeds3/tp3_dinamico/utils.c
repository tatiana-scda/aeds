//
//  utils.c
//
//
//  Created by tatiana on 07/07/17.
//
//

#include "utils.h"

//retorna o numero de colisoes de certa bandeira
int colisaoNumero (tipoPares *vetor, int bar, int residencia, int tamanho){
    int i, colisoes = 0;
    
    for (i = 0; i < tamanho; i++){
        if (vetor[i].bar < bar && vetor[i].casa > residencia)
            colisoes++;
        else if (vetor[i].bar > bar && vetor[i].casa < residencia)
            colisoes++;
    }
    return colisoes;
}

//retorna se houve colisão das bandeiras
int colisaoTrue(tipoPares *vetor, int bar, int residencia, int tamanho, int *pilha){
    int i;
    
    for (i = 0; i < tamanho; i++){
        if(pilha[i]){
            if (vetor[i].bar < bar && vetor[i].casa > residencia)
                return 1;
            else if (vetor[i].bar > bar && vetor[i].casa < residencia)
                return 1;
        }
    }
    return 0;
}

//Função compare para ordenação em função de colisão
int compareC (const void * a, const void * b){
    tipoPares *aa, *bb;
    
    aa = (tipoPares *)a;
    bb = (tipoPares *)b;
    
    if (aa->colisao <  bb->colisao) return -1;
    else if (aa->colisao == bb->colisao) return 0;
    else return 1;
}

//Função compare para ordenação em função do numero dos bares
int compareB (const void * a, const void * b){
    tipoPares *aa, *bb;
    
    aa = (tipoPares *)a;
    bb = (tipoPares *)b;
    
    if (aa->bar <  bb->bar) return -1;
    else if (aa->bar == bb->bar) return 0;
    else return 1;
}

//retorna a posição com maior valor
int maxPosVetor(int *vetor, int tamanho){
    int i, valorMax = 0, pos;
    for (i = 0; i < tamanho; i++){
        if (vetor[i] > valorMax){
            valorMax = vetor[i];
            pos = i;
        }
    }
    return pos;
}

//inicia a árvore
void iniciaArvore(tipoArvore *arvore){
    (*arvore) = (tipoNodo*) malloc(sizeof(tipoNodo));
    (*arvore)->coloca = NULL;
    (*arvore)->naoColoca = NULL;
    (*arvore)->flags = 0;
}

//libera arvore
void liberaArvore(tipoArvore arvore){
    if (arvore->coloca)
        liberaArvore(arvore->coloca);
    if (arvore->naoColoca)
        liberaArvore(arvore->naoColoca);
    free(arvore);
    arvore = NULL;
}
