//
//  main.c
//  
//
//  Created by tatiana
//
//

#include <stdio.h>
#include <stdlib.h>

#include "ordenadores.h"
#include "gerador.h"

//COMPILAR: gcc *.c -Wall -o main

int main(int argc, char *argv[]){

    int i;
    
    int algoritmo;
    int tamanho;
    int tipo;
    int print;
    
    int *vetorInicial;
    int *vetorOrdenado;
    double *tempoGasto;

    printf("Favor escrever as escolhas\n\n");
 
    printf("Digite o número do tipo de algoritmo que deseja usar: 1 - bolha, 2 - selecao, 3 - insercao, 4 - shell, 5 - quick, 6 - heap, 7 - merge, 8 - radix\n");
    scanf("%d", &algoritmo);
    
    printf("Opções de tamanho do vetor: 100, 1 000, 10 000, 100 000\n");
    scanf("%d", &tamanho);
    
    printf("Digite o número do tipo do vetor que deseja: 1 - ordenado, 2 - aleatorio, 3 - quase ordenado, 4 - inverso \n");
    scanf("%d", &tipo);
    
    printf("Deseja imprimir os vetores de entrada e saída? 1 - imprimir, 2 - não imprimir \n");
    scanf("%d", &print);

    vetorInicial = (int *)malloc(tamanho*sizeof(int));
    vetorOrdenado = (int *)malloc(tamanho*sizeof(int));
    
    
    switch (tipo) {
        case '1':
            ordenado (tamanho);
            break;
        case '2':
            aleatorio (tamanho);
            break;
        case '3':
            quaseOrdenado (tamanho);
            break;
        case '4':
            inverso (tamanho);
            break;
        default:
            printf("Escolha de tipo de vetor inválida, escreve alguma das opções dadas");
            break;
    }
    
    switch (algoritmo){
        case '1':
            bolha (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '2':
            selecao (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '3':
            insercao (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '4':
            shell (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '5':
            quick (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '6':
            heap (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '7':
            merge (vetorInicial, tamanho, vetorOrdenado);
            break;
        case '8':
            radix (vetorInicial, tamanho, vetorOrdenado);
            break;
        default:
            printf("Escolha de algoritmo inválida, escreve alguma das opções dadas");
            break;
    }
    
    switch (print){
        case '1':
            printf("Você escolheu imprimir. Suas escolhas foram: \n Algoritmo: %d \n Tamanho do vetor: %d \n Tipo de vetor: %d \n\n", algoritmo, tamanho, tipo);
            printf("Vetor inicial:\n");
            for(int i = 0; i < tamanho; i++) {
                    printf("%d ", vetorInicial[i]);
                }
            printf("\n \n");
            
            printf("\Vetor ordenado:n");
            for(int i = 0; i < tamanho; i++) {
                printf("%d ", vetorOrdenado[i]);
            }
            printf("\n \n");
            
            break;
        case '2':
            printf("Você escolheu imprimir. Suas escolhas foram: \n Algoritmo: %d \n Tamanho do vetor: %d \n Tipo de vetor: %d \n", algoritmo, tamanho, tipo);
            break;
        default:
            printf("Escolha impressão inválida, escreve alguma das opções dadas");
            break;
    }

    
    free(vetorInicial);
    free(vetorOrdenado);
    
    return 0;
}
