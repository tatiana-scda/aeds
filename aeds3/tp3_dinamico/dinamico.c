//
//  dinamico.c
//  
//
//  Created by tatiana on 21/06/17.
//
// for i in $(seq 0 9); do echo "Teste $i"; cat toy_$i | /usr/bin/time ./exec; done

#include "utils.h"

//retorna máximo de dois inteiros
int maximo(int a, int b){
    return(b > a ? b : a);
}

//retorna máximo de um vetor de inteiros
int maxV(int *vetor, int tamanho){
    int max = 0, i;
    for (i = 0; i < tamanho; i++){
        if (vetor[i] > max)
            max = vetor[i];
    }
    return max;
}

//acha a maior subsequencia crescente de casas
void maiorSequencia(int tamanho, int *sequencia, tipoPares *vetor){
    int i = 1, j = 0;
    
    for (i = 1; i < tamanho; i++){
        for (j = 0; j < i; j++){
            if(vetor[j].casa < vetor[i].casa )
                sequencia[i] = maximo(sequencia[i], (sequencia[j])+1);
        }
    }
}

//ordena e acha maior subsequencia e a imprime
void dinamico(tipoPares *vetor, int tamanho){
    int i;
    int *sequencia = (int*) calloc(tamanho,sizeof(int));
    for (i = 0; i < tamanho; i++)
        sequencia[i] = 1;
    
    //ordena em ordem crescente os bares
    qsort (vetor, tamanho, sizeof(tipoPares), compareB);
    
    maiorSequencia(tamanho, sequencia, vetor);
    
    printf("%d\n", maxV(sequencia, tamanho));
    free(sequencia);
}

