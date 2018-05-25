//
//  adhoc2.c
//
//
//  Created by tatiana on 29/05/17.
//
//

#include <stdio.h>
#include <stdlib.h>

int somaVetor(int *vetor, int inicio, int fim){
    int i, soma = 0;
    for (i = inicio; i < fim; i++)
        soma += vetor[i];
    return soma;
}

int main (){
    
    int n, i, inicio, sum = 0, tam, valor;
    long long int vitorias = 0;
    
    scanf("%d", &n);
    int fileira[n];
    int resto[10];
    
    for(i = 0; i < 10; i++)
        resto[i] = 0;
    
    for (i = 0; i < n; i++)
        scanf("%d", &fileira[i]);
    
    resto[0] = 1;
    for(i = 0; i < n; i++){
        sum += fileira[i];
        sum %= 8;
        vitorias += resto[sum];
        resto[sum]++;
    }
    
    printf("%lld\n", vitorias);
    return 0;
}
