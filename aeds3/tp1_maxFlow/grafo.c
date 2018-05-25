//
//  grafo.c
//
//
//  Created by tatiana on 27/04/17.

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include "grafo.h"

/*

Essa conferencia se tornou desncessaria

 //Soma todos valores possíveis de ciclistas que podem chegar ao cliente pelo grafo. O valor considerando o caminho deve ser igual ou menor o valor que esta função retorna.
 int maxCiclistasCliente(tipoGrafo *grafo, int vertices){
     int maxC = 0;
     int i, j;

     for (i = 0; i < vertices-1; i++){//Não ler o valor de superCliente
         for (j = 0; j < vertices-1; j++){
             if (grafo->vertice[i][j].tipo == 1) //id de cliente
                 maxC += grafo->vertice[i][j].trafego;
        }
     }
     return maxC;
 }

 //Soma todos possíveis ciclistas que saem de  todas franquias. O valor máximo de possíveis ciclistas que andam pelo grafo também deve ser menor ou igual que o valor que esta função retorna
 int maxCiclistasFranquia(tipoGrafo *grafo, int vertices){
     int i, j, maxF = 0;

     for (i = 1; i < vertices; i++){//Não ler o valor de superFranquia
         for (j = 1; j < vertices; j++){
             if (grafo->vertice[i][j].tipo == 0) //id franquia
             maxF += grafo->vertice[i][j].trafego;
         }
     }
     return maxF;
 }*/


//Aloca dinamicamente os grafos em matriz
tipoGrafo* aloca(int vertices){
    int i;
    tipoGrafo *grafo = (tipoGrafo*) malloc (vertices*sizeof(tipoGrafo));

    grafo->vertice = (tipoVertice**) malloc (vertices*sizeof(tipoVertice*));
    for(i = 0; i < vertices; i++)
        grafo->vertice[i] = (tipoVertice*) malloc (vertices*sizeof(tipoVertice));

   return grafo;
}

//Sabendo qual vértice é franquia, salva a superFranquia ligada até franquia, com ciclistas/h infinito
void verticeSuperFranquia(tipoGrafo *grafo, int vFranquia){
    grafo->vertice[0][vFranquia].tipo = 0;
    grafo->vertice[0][vFranquia].trafego = INT_MAX;
}

//Sabendo qual vértice é cliente, salva o superCliente ligada até cliente, com ciclistas/h infinito
void verticeSuperCliente(tipoGrafo *grafo, int cVertice, int vertices){
        grafo->vertice[cVertice][vertices-1].tipo = 1;
        grafo->vertice[cVertice][vertices-1].trafego = INT_MAX;
 }

//Copia o grafo original para o grafio residual
void copiaGrafo(tipoGrafo *grafo, tipoGrafo *Rgrafo, int vertices){
	int i, j;

	for(i = 0; i < vertices; i++){
		for(j = 0; j < vertices; j++){
			Rgrafo->vertice[i][j].tipo = grafo->vertice[i][j].tipo;
			Rgrafo->vertice[i][j].trafego = grafo->vertice[i][j].trafego;
		}
	}
}

//Funcao simples para informacoes e debug
void imprimeT(tipoGrafo *grafo, int vertices){
	int i, j;
	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++){
			printf("%d ", grafo->vertice[i][j].trafego);
		}
	printf("\n");
	}
    printf("\n");
}

//Funcao simples para informacoes e debug
void imprimeQ(tipoGrafo *grafo, int vertices){
    int i, j;

    for (i=0; i < vertices; i++) {
        for (j = 0; j < vertices; j++){
            printf("%d ", grafo->vertice[i][j].tipo);
        }
        printf("\n");
    }
}

//Funcao simples para informacoes e debug
void imprimeVetor(int *vetor, int total){
    int i;
    for(i = 0; i < total; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

//Percorre um vetor todo e zera todas casas
void zeraVetor(int *vetor, int total){
    int i;
    for(i = 0; i < total; i++)
        vetor[i] = 0;
}

//Função que faz busca BFS no grafo e acha caminho de superFranquia e superCliente
int bfs(tipoGrafo *Rgrafo, int vertices, int *parent, int *fila){
    int j, i = 0;
    int visitado[vertices];
    //Zera os vetores para nao haver lixo na memoria
    zeraVetor(visitado, vertices);
    zeraVetor(parent, vertices);
    //Inicia fila
    int *frente = fila;
    int *final = fila;
    final++;
    visitado[0] = 1;

    while (frente != final) {
        //Tira o primeiro da fila, enquanto fila nao vazia
        i = *frente;
        frente++;
        for(j = 0; j < vertices; j++){
            if (visitado[j] == 0 && Rgrafo->vertice[i][j].trafego > 0){
                visitado[j] = 1;
                parent[j] = i;
                *final = j;
                final++;
                if(j == vertices-1){
                    return 1; //Retorna 1 se chegou no último vertice
                }
            }
        }
    }
    return 0; //Retorna 0 se não há caminho
}

//Recebe o parent de BFS e faz a soma do fluxo
int caminho(tipoGrafo *Rgrafo, int vertices, int *parent){
    int i=vertices-1, fluxoMaximo = 0, fluxoCaminho = INT_MAX;
    int *fila = calloc(vertices, sizeof(int));

    //Enquanti houver caminho valido, BFS eh chamada recursivamente
    while (bfs(Rgrafo, vertices, parent, fila)){
        fluxoCaminho = INT_MAX; //Fluxo maximo inicia como infinito
        int j = vertices-1;
        while(j != 0){
            i = parent[j];
            //Procura o menor peso do caminho, mas maior que zero
            if(fluxoCaminho > Rgrafo->vertice[i][j].trafego && (Rgrafo->vertice[i][j].trafego > 0)){
              //Se o peso for menor, vai ser o novo fluxo do caminho. Se for maior, fluxo continua o mesmo
                fluxoCaminho = Rgrafo->vertice[i][j].trafego;
            }
            j = parent[j];
        }
        j = vertices - 1;
        while (j != 0){
            i = parent[j];
            //Retira o peso do grafo residual, dai ha balanceamento de quantos ciclistas ainda podem passar nesta aresta
            Rgrafo->vertice[i][j].trafego = Rgrafo->vertice[i][j].trafego - fluxoCaminho;
            //Adiciona no verice oposto ([j][i]) caso tenha que voltar no caminho
            Rgrafo->vertice[j][i].trafego = Rgrafo->vertice[j][i].trafego + fluxoCaminho;
            j = parent[j];
        }
        //Fluxo maximo e incrementado com fluxo de cada caminho valido
        fluxoMaximo += fluxoCaminho;
    }
    free(fila);
    return fluxoMaximo;
}

//Função para desalocar a memória usada para o grafo e vetor parent
void desaloca(tipoGrafo *grafo, tipoGrafo *Rgrafo, int vertices, int *parent){
    int i;

    for (i = 0; i < vertices; i++)
        free(grafo->vertice[i]);
    free (grafo);

    for (i = 0; i < vertices; i++)
        free(Rgrafo->vertice[i]);
    free (Rgrafo);
    free(parent);
}
