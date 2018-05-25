//
//  Twitter
//
//
//  Tatiana Santos Camelo de Araujo
//  2015086298
//

#ifndef messages_h
#define messages_h

#include <stdio.h>
#include "user.h"

typedef struct {
    char text[141];
    int id[20];
    int likes;
    int time;
}type_message;


void postarMensagem(type_user *user, struct type_list_followers *followers, type_message *message, FILE *entrada, type_pointer p);
void curtirMensagem(type_message *message, int time_occurred);

#endif /* messages_h */
