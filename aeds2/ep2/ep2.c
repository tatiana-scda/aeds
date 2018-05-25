#include "ep2.h"

void empty_list(type_list *list){
    list->first = malloc(sozeof(type_node));
    list->last = malloc(sozeof(type_node));
    list->last->next = NULL;
}

