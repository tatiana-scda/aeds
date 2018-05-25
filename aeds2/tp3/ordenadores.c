//
//  ordenadores.c
//  
//
//  Created by tatiana
//
//

#include "ordenadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Algoritimos de ordenação

int* bolha (int *vetorInicial, int *tamanho, int *vetorOrdenado){
    int i, j, aux;
    int n = tamanho;
    int mov = 0;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    for (i = 1; i <= n; i++){
        for (j = 1; j <= (n-i); j++){
            if (vetorInicial[j] > vetorInicial[j+1]){
                aux = vetorInicial[j];
                vetorInicial[j] = vetorInicial[j+1];
                vetorInicial[j+1] = aux;
                mov++;
            }
        }
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

int* selecao (int *vetorInicial, int *tamanho, int *vetorOrdenado){
    int i, j, aux, min;
    int n = tamanho;
    int mov = 0;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    for (i = 1; i <= n - 1; i++){
        min = i;
        for (j = i + 1; j <= n; j++)
            if (vetorInicial[j] < vetorInicial[min]){
                min = j;
                mov++;
            }
        aux = vetorInicial[min];
        vetorInicial[min] = vetorInicial[i];
        vetorInicial[i] = aux;
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

int* insercao (int *vetorInicial, int *tamanho, int *vetorOrdenado){
    int i, j, aux;
    int n = tamanho;
    int mov = 0;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    for (i = 2; i <= n; i++){
        aux = vetorInicial[i];
        j = i - 1;
        vetorInicial[0] = aux;
        while (aux < vetorInicial[j]){
            vetorInicial[j+1] = vetorInicial[j];
            j--;
            mov++;
        }
        vetorInicial[j+1] = aux;
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

int* shell (int *vetorInicial, int *tamanho, int *vetorOrdenado){
    int i, j, aux;
    int h = 1;
    int n = tamanho;
    int mov = 0;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    do h = h * 3 + 1;
    while (h < n);
    do{
        h /= 3;
        for (i = h + 1; i <= n; i++){
            aux = vetorInicial[i]; j = i;
            while (vetorInicial[j - h] > aux){
                vetorInicial[j] = vetorInicial[j - h]; j -= h;
                mov++;
                if (j <= h)
                    break;
            }
            vetorInicial[j] = aux;
        }
    }
    while (h != 1);
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

void particao(int *vetorInicial){
    int x, w;
    int *i, *j;
    int esq, dir;
    
    *i = esq; *j = dir;
    x = vetorInicial[(*i + *j) / 2];
    do {
        while (x > vetorInicial[*i]) (*i)++;
        while (x < vetorInicial[*j] (*j)--;
        if (*i <= *j){
            w = vetorInicial[*i];
            vetorInicial[*i] = vetorInicial[*j];
            vetorInicial[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

int* quick (int *vetorInicial, int *tamanho, int *vetorOrdenado){
    int i;
    int n = tamanho;
    int mov = 0;
    int p, e, d;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    if (e < d) {
        p = particao(vetorInicial, e, d); /* Particiona o vetor */
        Quicksort(vetorInicial, e, p-1); /* Ordena lado esquerdo */
        Quicksort(vetorInicial, p+1, d); /* Ordena lado direito */
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

void constroi(int *vetorInicial) {
    int esq, n;
    esq = n / 2 + 1;
    while (esq > 1) {
        esq--;
        refaz(vetorInicial); }
}
               
void refaz(int *vetorInicial) {
    int esq, dir;
    int i, j, x;
    
    int i = esq;
    j = i * 2;
    x = vetorInicial[i];
    while (j <= dir) {
        if (j < dir) {
            if (vetorInicial[j] < vetorInicial[j+1]) j++;
        }
        if (x >= vetorInicial[j]) break;
        vetorInicial[i] = vetorInicial[j];
        i = j;
        j = i * 2;
        }
    vetorInicial[i] = x;
}
               
int* heap (int *vetorInicial, int *tamanho,int *vetorOrdenado){
    
    int i, x;
    int mov = 0;
    int esq, dir;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    constroi(vetorInicial);
    esq = 1;
    dir = n;
    while (dir > 1) {
        x = vetorInicial[1];
        vetorInicial[1] = vetorInicial[dir]; vetorInicial[dir] = x;
        dir--;
        refaz(vetorInicial);
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

void mergeIntercala(TipoItem *v, TipoIndice esq, TipoIndice meio, TipoIndice dir){
    int i, j, k;
    int a_tam = meio-esq+1;
    int b_tam = dir-meio;
    TipoItem *a = (TipoItem*) malloc(sizeof(TipoItem) * a_tam); TipoItem *b = (TipoItem*) malloc(sizeof(TipoItem) * b_tam); for (i = 0; i < a_tam; i++) a[i] = v[i+esq];
    for (i = 0; i < b_tam; i++) b[i] = v[i+meio+1];
    for (i = 0, j = 0, k = esq; k <= dir; k++) {
        if (i == a_tam) v[k] = b[j++];
        else if (j == b_tam) v[k] = a[i++];
        else if (a[i].Chave < b[j].Chave) v[k] = a[i++]; else v[k] = b[j++];
    }
    free(a); free(b);
}
               
int* merge (int *vetorInicial, int *tamanho,int *vetorOrdenado){
    
    int i;
    int n = tamanho;
    int mov = 0;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    if (esq == dir) return;
    TipoIndice meio = (esq + dir) / 2;
    mergesort_ordena(v, esq, meio); mergesort_ordena(v, meio+1, dir); mergesort_intercala(v, esq, meio, dir);
}
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}

int* radix(int *vetorInicial, int *tamanho, int *v, int base, int num_digitos, int *vetorOrdenado){
    
    int i;
    int mov = 0;
    int n = tamanho;
    
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    
    int j, w, count[base+1], d, idx;
    int *aux = (int *) malloc(n * sizeof(int));
    for(w = 0; w < num_digitos; w++) {
        for(j = 0; j < base; j++)
            count[j] = 0; // zera contador
        for(i = 0; i < n; i++) { // conta dígitos
            d = digito(v[i], w, base);
            count[d+1]++;
        } // seta índices para os dígitos
        for(j = 1; j < base; j++)
            count[j] += count[j-1];
        for(i = 0; i < n; i++) { // adiciona nas posições
            d = digito(v[i], w, base);
            idx = count[d];
            count[d] += 1;
            aux[idx] = v[i];
            mov++;
        }
        for(i = 0; i < n; i++)
            v[i] = aux[i]; // retorna p/ v
    }
    
    for(i = 0; i < n; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
    
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    
    return vetorOrdenado;
}
