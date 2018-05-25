#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ep1.h"
//Compilar com gcc -Wall *.c -o main

int main(int argc, char *argv[]){
    
    FILE *arquivo_entrada;
    FILE *arquivo_saida;
    int i;
    int evento;
    int total_clientes = 0;
    int clientes_atuais = 0; //Numero de clientes que estão na loja
    tipo_cliente *clientes;
    int consultas = 0;
    
    //Inicialmente, o programa vai conferir se ambos arquivos (entrada e saida) podem ser lidos.
    arquivo_entrada = fopen("arquivo_entrada.rtf", "r");
    if (arquivo_entrada == NULL){
        printf("Erro ao ler arquivo de entrada\n");
    }
    
    arquivo_saida = fopen("arquivo_saida.rtf", "r");
    if (arquivo_saida == NULL){
        printf("Erro ao ler arquivo de saida\n");
    }
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    
    //Le a primeira linha e salva o numero de clientes
    fscanf(arquivo_entrada, "%d\n", &total_clientes);
    //Cria um vetor de tamanho (total_clientes)
    clientes = (tipo_cliente *)malloc(total_clientes*(sizeof(tipo_cliente)));
    for (i = 0; i < total_cliente; i++){
        clientes[i].desistencia = 0;
    }
    
    scanf("%d ", &evento);
    switch(evento){
            //Chegada de cliente
        case 1:
            chegada(arquivo_entrada, clientes, &total_clientes, &clientes_atuais);
            break;
            
            //atendimento de cliente
        case 2:
            atendimento(arquivo_entrada, cliente, clientes_atuais);
            break;
            
            //Saida apos ser atendido
        case 3:
            saida(arquivo_entrada, cliente, clientes_atuais);
            break;
            
            //Desistencia
        case 4:
            desistencia(arquivo_entrada, cliente, clientes_atuais);
            break;
            
            //Imprimir relatorio
        case 5:
            imprimir(arquivo_entrada);
            break;
            
            //Sair do sistema
        case 6:
            free(clientes);
            break;
            
        default:
            printf("Operacao invalida\n");
    }
}