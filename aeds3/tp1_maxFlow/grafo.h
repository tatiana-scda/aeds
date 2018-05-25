//
//  grafo.h
//
//
//  Created by tatiana on 27/04/17.
//
//

#ifndef grafo_h
#define grafo_h
#include <stdio.h>

typedef struct tipoVertice{
    int tipo; //0 franquia, 1 cliente, 2 nenhum
    int trafego;
}tipoVertice;

typedef struct tipoGrafo{
    tipoVertice **vertice;
}tipoGrafo;


//int maxCiclistasCliente(tipoGrafo *grafo, int vertices);
//int maxCiclistasFranquia(tipoGrafo *grafo, int vertices);

void zeraVetor(int *vetor, int total);
void verticeSuperCliente(tipoGrafo *grafo, int cVertice, int vertices);
void verticeSuperFranquia(tipoGrafo *grafo, int cFranquia);
tipoGrafo *aloca(int vertices);
void desaloca(tipoGrafo *grafo, tipoGrafo *rGrafo, int vertices, int *parent);
int bfs(tipoGrafo *Rgrafo, int vertices, int *parent, int *fila);
int caminho(tipoGrafo *Rgrafo, int vertices, int *parent);
void copiaGrafo(tipoGrafo *grafo, tipoGrafo *Rgrafo, int vertices);
void imprimeT(tipoGrafo *grafo, int vertices);
void imprimeQ(tipoGrafo *grafo, int vertices);
void imprimeVetor(int *vetor, int total);
#endif /* grafo_h */
