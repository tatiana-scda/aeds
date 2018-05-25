#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/*
void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST
     int i;
     // Initialize all keys as INFINITE
     for (i = 0; i < V; i++)
        key[i] = INT_MAX;
        mstSet[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph);
}*/

int main(){
  int R, C;
  int V, W, P;
  int aux = 0, i = 0, j = 0;
  int **grafo;
  int *caminho; //tamanho max vertices
  scanf("%d %d", &R, &C);

  grafo = (int**)calloc(R,sizeof(int*);
  for(aux = 0; aux < R; aux++)
    grafo[aux] = (int*)calloc(R,sizeof(int);

  caminho = (int*)calloc(R,sizeof(int);

  for(aux = 0; aux < C; aux++){
    scanf("%d %d %d", &i, &j, &grafo[i][j]);
    grafo[j][i] = grafo[i][j];
  }



return 0;
}
