//
//  Twitter
//
//
//  Tatiana Santos Camelo de Araujo
//  2015086298
//

#ifndef user_h
#define user_h

#include <stdio.h>
#include "messages.h"

typedef struct type_list_followers followers;
typedef struct type_stack_timeline timeline_seen;
typedef struct type_stack_timeline timeline_user;

//TAD User
typedef struct type_user{
    char id[20];
    char name[20];
    struct type_list_followers followers;
    struct type_stack_timeline timeline_user;
    struct type_stack_timeline timeline_seen;
}type_user;


//TAD list of followers
typedef struct cell *type_pointer;
typedef int type_key;

typedef struct{
    type_key key;
    struct type_user user;
}type_item_f;

typedef struct cell{
    type_item_f item;
    type_pointer next;
}type_cell;

struct type_list_followers{
    type_pointer first, last;
};




//TAD list timeline
/*
 typedef struct cell *type_pointer;
typedef int type_key;
 */

typedef struct {
    type_key key;
    type_message message;
}type_item_t;

type_cell cell;

struct type_stack_timeline{
    type_pointer top, bot; //bot de bottom, o fundo da pilha
    int size;
};

void iniciarAmizade(type_user *user1, type_user *user2, struct type_list_followers *followers);
void cancelarAmizade(type_user *user1, type_user *user2, struct type_list_followers *followers);
void exibirTimeline(type_user *user, struct type_stack_timeline timeline_seen);
int verAmigos(struct type_list_followers *followers, type_user *user, type_pointer p);

int make_list_followers(struct type_list_followers *followers);
int make_stack_timeline_seen(struct type_stack_timeline *timeline_seen);
int make_stack_timeline_user(struct type_stack_timeline *timeline_user);
void stacking_timeline_user(type_user *user, struct type_stack_timeline *timeline_user, type_item_t *item, int time_occurred);
void stacking_timeline_seen(type_user *user, struct type_stack_timeline *timeline_seen, type_item_t *item, int time_occurred);


#endif /* user_h */
