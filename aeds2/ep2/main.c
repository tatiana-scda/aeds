#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ep2.h"
//Compilar com gcc -Wall *.c -o main

int main(int argc, char *argv[]){
    char *number;
    
    FILE *in;
    FILE *out;
    
    in = fopen ("ep2.in", "r");
    if (ep2.in == NULL)
        printf ("Error opening file");
    else {
        if(fgets(number, 1, in) != ' '&&'\n'){
            list->last->next = malloc(sizeof(type_node));
            list->last = list->last->next;
            list->last->algarism = number;
            list->last->next = NULL;
        }
        else{
            
        }
    return 0;
}