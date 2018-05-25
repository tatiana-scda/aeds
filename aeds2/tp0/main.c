#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include <time.h>

int main(int argc, char *argv){
    FILE *arquivo_entrada;
    FILE *arquivo_saida;
    clock_t, start_t, horario;;
    
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
    
}

    start_t = clock(); //Funcao de time.h que cria os horários desde a execusao do programa

//Primeira linha:
    void cadastro_impressora(impressora);
    