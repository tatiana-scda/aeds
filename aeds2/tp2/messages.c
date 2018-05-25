//
//  Twitter
//
//
//  Tatiana Santos Camelo de Araujo
//  2015086298
//

#include <stdio.h>
#include <stdlib.h>

#include "messages.h"

//funcoes de mensagem

//código 1
void postarMensagem(type_user *user, struct type_list_followers *followers, type_message *message, FILE *entrada, type_pointer p){ // inclui a mensagem em cada uma das timelines dos amigos do usu´ario
    p = user->followers->first->next;
    
    //anda toda lista de seguidores
    while (p != NULL){
        if (user->timeline_seen == NULL){ //se o amigo nao tiver a pilha para timeline, cria-se e adticiona esta mensagem como primeira
            make_stack_timeline_seen (*timeline_seen);
            
            stacking_timeline_seen(*user, *timeline_seen, *item, time_occurred);
            
            user->timeline_seen->bot = user->timeline_seen->top->next->next;
            user->timeline_seen->bot->next = NULL;
        }

        else {// como a mensagem estará sendo postada na hora que o programa a lê, ela sempre será a mensagem mais atual
            stacking_timeline_seen(*user, *timeline_seen, *item, time_occurred);
        }
    p = p->next;
    }
    stacking_timeline_user(*user, *timeline_user, *item, time_occurred); //salva na TL do usuário que postou
    stacking_timeline_seen(*user, *timeline_seen, *item, time_occurred); //salva na timeline que ele vê
}


//código 4
void curtirMensagem(type_message *message, int time_occurred){  //atualizar o tempo ao curtir a mensagem
    message->likes++;
    message->time = time_ocurred;
    
    stacking_timeline_seen(*user, *timeline_seen, *message, time_occurred);
}
