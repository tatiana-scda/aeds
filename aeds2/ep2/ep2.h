#ifndef ep2_h
#define ep2_h

#include <stdio.h>

//TAD Lista Duplamente Encadeada

typedef node *pointer;

typedef struct node {
    pointer next;
    pointer before;
    int algarism;
}type_node;

typedef struct {
    pointer first;
    pointer last;
}type_list;

//TAD BigNum
//(criar destruir somar subtrair imprimir)
#endif /* ep2_h */
