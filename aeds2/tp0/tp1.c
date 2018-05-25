#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *arquivo_entrada;
FILE *arquivo_saida;


void fila_vazia(tipo_fila *fila){
    fila->frente = malloc(sizeof(tipo_celula));
    fila->final = fila->frente;
    fila->frente->prox = NULL;
}

void cadastro_impressora(tipo_impressora *impressora){
    fscanf(arquivo_entrada, "%s ", &impressora->nome);
    fscanf(arquivo_entrada, "%d ", &impressora->capacidade);
}

void cadastro_usuario(tipo_usuario *usuario){
    fscanf(arquivo_entrada, "%s ", &usuario->nome);
    fscanf(arquivo_entrada, "%d ", &usuario->prioridade);
}

void remover_usuario(tipo_usuario *usuario){
    fscanf(arquivo_entrada, "%s ", &usuario->nome);
    if(){ /*usuario n estiver imprimindo*/
        free(usuario);
    }
    else //esperar impressao
        remover_usuario(usuario);
}

void nova_impressao(tipo_impressao *impressao){
    fscanf(arquivo_entrada, "%d ", &horario);
    fscanf(arquivo_entrada, "%s ", &usuario.nome);
    fscanf(arquivo_entrada, "%d ", &usuario.prioridade);
    fscanf(arquivo_entrada, "%d ", &paginas);
    fscanf(arquivo_entrada, "%d ", &tempo_espera);
}

void relatorio(){
    
}
