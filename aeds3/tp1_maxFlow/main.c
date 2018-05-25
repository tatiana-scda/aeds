//
//  main.c
//
//
//  Created by tatiana on 27/04/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include "grafo.h"

int main (void){
    int vertices, arestas, franquias, clientes;
    int vertice1, vertice2, ciclistas;
    int max = 0;
    int i = 0, j = 0, count;

    scanf("%d %d %d %d", &vertices, &arestas, &franquias, &clientes);

    //Para dar espaço para superFranquia e superCliente
    vertices = vertices + 2;

    int *parent = calloc(vertices,sizeof(int));
    tipoGrafo *grafo = aloca(vertices);
	  tipoGrafo *Rgrafo = aloca(vertices);

    for (i = 0; i < vertices; i++){
        for (j = 0; j < vertices; j++){
            grafo->vertice[i][j].trafego = 0; //numero de ciclistas/h
            grafo->vertice[i][j].tipo = 2; //id de nem cliente nem franquia
        }
    }

    for (i = 0; i < arestas; i++){
        scanf("%d %d %d", &vertice1, &vertice2, &ciclistas);
        //Soma 1 devido a implementacao de superFranquia
        vertice1++; vertice2++;
        grafo->vertice[vertice1][vertice2].trafego = ciclistas;
    }

    for (count = 0; count < franquias; count++){
        scanf("%d", &vertice1);
        vertice1++;
        for (i = 0; i < vertices; i++){
                grafo->vertice[vertice1][i].tipo = 0; //id de franquia
        }
        //Liga franquia a superFranquia com peso infinito
        verticeSuperFranquia(grafo, vertice1);
    }

    for (count = 0; count < clientes; count++){
        scanf("%d", &vertice1);
        vertice1++;
        for (i = 1; i < vertices; i++){ //Não salva novamente em 0, pois não nodo que é cliente E franquia
                grafo->vertice[i][vertice1].tipo = 1; //id de cliente
        }
        //Liga cliente a superCliente com peso infinito
        verticeSuperCliente(grafo, vertice1, vertices);
    }
    //Copia o grafo original para o grafo residual(Rgrafo)
    copiaGrafo(grafo, Rgrafo, vertices);
    //Função que recebe caminho de bfs e faz as operações no Rgrafo para achar o máximo
    max += caminho(Rgrafo, vertices, parent);

    printf("%d\n", max);

    desaloca(grafo, Rgrafo, vertices, parent);
    return 0;
}
