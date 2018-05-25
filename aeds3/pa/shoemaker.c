//
//  shoemaker.c
//  
//
//  Created by tatiana on 16/05/17.
//
// visitar todas arestas uma vez

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idCid;
    //se a cidade 0 percente a conf AB, é um vertice 0 que liga AB. Se for só A, é um loop
}TipoAresta;

typedef struct{
    int idConf;
    
}tipoVertice;

int main(){
    int N, C, K, i;
    
    scanf("%d %d", &N, $C); //cidades e confederações
    
    for (i = 0, i < C){
        scanf("%d", &K);
        alocar info
    }
    
    if (confederacao sem cidade){
        retirar vertice
    }
    
    if (mais de dois vertices impares){
        printf("-1");
    }
    
    return 0;
}

/*
 
 Para quem já leu e entendeu o problema:
 
 O problema consiste em fazer com que Poly percorra todas as cidades sem repetições.
 Cada cidade pertence a uma ou duas confederações.
 Uma cidade da confederação A e B só pode ser visitada se Poly possuir um tíquete da confederação A ou da confederação B.
 Ao entrar em tal cidade com um tíquete da confederação A, Poly devolve o tíquete de A e recebe o tíquete de B para viajar para a próxima cidade.
 Poly só pode carregar um único tíquete.
 Se uma cidade só pertence a uma confederação, Poly pode entrar e sair desta cidade com o mesmo tíquete.
 
 
 Observações que tornam o problema simples:
 
 Pensem nas confederações como vértices e nas cidades como arestas.
 Se a cidade 0 pertence a confederação A e B, crie uma aresta identificada como 0 entre os vértices A e B.
 Se a cidade 1 só pertence a uma confederação A, crie aresta de A para A identificada como 1.
 Se todas as arestas forem percorridas sem repetição então o problema é resolvido.
 Observe que entre dois vértices de confederações A e B podemos ter múltiplas arestas indicando que várias cidades pertencem às confederações A e B.
 O grafo precisa ser conexo. (Elimine os vértices que não possuem arestas, pois podemos ter confederações sem cidades)
 Não tem problema repetir vértices (Que agora são confederações).
 Pensem na paridade dos vértices, quais são as condições para que seja possível percorrer todas as arestas no grafo?
 Vocês conseguem ver que se tivermos apenas vértices de grau par em um grafo conexo então não importa aonde eu começar o percurso eu sempre conseguirei percorrer todas as arestas?
 Conseguem ver também que eu sempre terei um número par de vértices de grau ímpar? E que se eu tiver mais do que dois vértices de grau ímpar eu nunca conseguirei percorrer todas as arestas?

 
*/
