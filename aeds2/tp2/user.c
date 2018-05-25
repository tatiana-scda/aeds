//
//  Twitter
//  
//
//  Tatiana Santos Camelo de Araujo
//  2015086298
//

#include <stdio.h>
#include <stdlib.h>

#include "user.h"

int

//funçoes de usuário

//código 2
void iniciarAmizade(type_user *user1, type_user *user2, type_list_followers *followers){
    //Inclusir na lista do usuario 1
    user1->followers->last->next = malloc(sizeof(type_cell));
    
    user1->followers->last = user1->followers->last->next;
    user1->followers->last->user = *user2;
    user1->followers->last->next = NULL;
    
    //Incluir na lista do usuario 2
    user2->followers->last->next = malloc(sizeof(type_cell));
    
    user2->followers->last = user2->followers->last->next;
    user2->followers->last->user = *user1;
    user2->followers->last->next = NULL;
    
}

//código 3
void cancelarAmizade(type_user *user1, type_user *user2, type_list_followers *followers){
    //cancelar a amizade deve ser feita para ambos usuários
    type_pointer p1, p2;
    p1 = user1->followers->first->next;
    p2 = user2->followers->first->next;
    
    type_pointer aux1, aux2;
    aux1 = malloc(sizeof(type_cell));
    aux2 = malloc(sizeof(type_cell));
    
    while(p1 != NULL){
        
        if(p1->user->id != user2->id){
            
            aux1 = p1->next;
            *user2 = aux1->user;
            p1->next = aux1->next;
            
            if(p1->next == NULL){
                followers->next = NULL;
            }

            free(aux1);
        }
        p1 = p1->next;
    }
    
    while(p2 != NULL){
        if(p2->user->id != user1->id){
            
            aux2 = p2->next;
            *user1 = aux2->user;
            p2->next = aux2->next;
            
            if(p2->next == NULL){
                followers->next = NULL;
            }
            
            free(aux2);
        }
        p2 = p2->next;
    }
}

//código 5
void exibirTimeline(type_user *user, type_stack_timeline timeline_seen){
    //A função de postar mensagem já salva as mensagens do próprio usuário na TL que ele vê
    type_pointer p;
    p = user->timeline_seen->top->next;
    int i;
    
    while(p != NULL){
        for(i = 0; i < 140; i++){
            printf("%c ", user->timeline_seen->message->text[i]);
        }
        printf("%d ", user->timeline_seen->message->likes);
        
        p = p->next;
    }
}

int verAmigos(type_list_followers *followers, type_user *user, type_pointer p){
    p = user->followers->first->next;
    
    while (p != NULL){
        return p; //A função retorna o ponteiro para o primeiro item da lista até o ultimo
        p = p->prox;
    }
}



//inicialização das listas e pilhas
int make_list_followers(struct type_list_followers *followers){
    followers->first = malloc(sizeof(type_cell));
    followers->last = followers->first;
    followers->first->next = NULL;
    
    return (followers->first == followers->last);
}

int make_stack_timeline_user(struct type_stack_timeline *timeline_user){
    timeline_user->top = malloc(sizeof(type_cell));
    timeline_user->bot = timeline_user->top;
    timeline_user->top->bot = NULL;
    timeline_user->size++;
    
    return (timeline_user->top == timeline_user->bot);
}

int make_stack_timeline_seen(struct type_stack_timeline *timeline_seen){
    timeline_seen->top = malloc(sizeof(type_cell));
    timeline_seen->bot = timeline_seen->top;
    timeline_seen->top->bot = NULL;
    timeline_seen->size++;
    
    return (timeline_seen->top == timeline_seen->bot);
    
}

//empilha
void stacking_timeline_user(type_user *user, struct type_stack_timeline *timeline_user, type_item_t *item, int time_occurred){
    type_pointer aux = malloc(sizeof(type_cell));
    
    timeline_user->top->message->id = type_item_t->id;
    timeline_user->top->message->text = type_item_t->text;
    timeline_user->top->message->time = time_occurred;
    
    aux->next = timeline_user->top;
    timeline_user->top = aux;
    timeline_user->size++;
    free(aux);
}

void stacking_timeline_seen(type_user *user, struct type_stack_timeline *timeline_seen, type_item_t *item, int time_occurred){
    type_pointer aux = malloc(sizeof(type_cell));
    
    timeline_seen->top->message->id = type_item_t->id;
    timeline_seen->top->message->text = type_item_t->text;
    timeline_seen->top->message->time = time_occurred;
    
    aux->next = timeline_seen->top;
    timeline_seen->top = aux;
    timeline_seen->size++;
    free(aux);
}
