#ifndef tp1_h
#define tp1_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 typedef struct tipo_impressora{
     char nome[12];
     int capacidade; //impressao em folhas/segundo
 } tipo_impressora;

typedef struct tipo_usuario{
    char nome[22];
    int prioridade; //0 a 5, sendo 1 a mais importante
} tipo_usuario;

typedef struct tipo_impressao{
    int horario;
    struct usuario.nome;
    struct usuario.prioridade;
    int tempo_espera;
    int paginas;
}tipo_impressao;

//Será uma fila, para adequar a FIFO
//TAD Fila

typedef struct tipo_celula* pointer;

typedef int tipo_chave;

typedef struct tipo_item{
    tipo_impressora impressora;
    tipo_usuario usuario;
    tipo_chave chave;
}tipo_item;

typedef struct tipo_celula{
    tipo_item item;
    pointer prox;
    pointer antes;
} tipo_celula;

typedef struct tipo_fila{
    pointer frente;
    pointer final;
} tipo_fila;

#endif /* tp1_h */
