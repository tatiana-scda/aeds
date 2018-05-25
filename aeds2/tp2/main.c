//
//  Twitter
//
//
//  Tatiana Santos Camelo de Araujo
//  2015086298
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "messages.h"
#include "user.h"

//COMPILAR: gcc *.c -Wall -o main
//"TL" é usado como sigla para "timeline" nos comentários ao longo do código

int main(int argc, char *argv[]){
    
    int users_total;
    type_user user;
    char infos[500];
    char *token;
    int i = 0;
    int line = 0;
    int code;
    int time_occurred;
    
    FILE *entrada;
    FILE *saida;
    
    
    //Inicialmente, o programa vai conferir se ambos arquivos (entrada e saida) podem ser lidos.
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL){
        printf("Erro ao ler arquivo de entrada\n");
    }
    
    saida = fopen("saida.txt", "w");
    if (saida == NULL){
        printf("Erro ao criar arquivo de saida\n");
    }
    
    //Ler e salvar o numero de usuarios
    fscanf(entrada, "%d ", &users_total);
    line++;

    //Ler e salvar informaçoes dos usuários
    fscanf(entrada, "%s ", infos);
    token = strtok(infos, ";");
    if (line <= users_total){
        while (token != NULL){
            if(i == 0){
                strcpy(user.id, token);
            }
            else if(i == 1){
                strcpy(user.name, token);
            }
            else if(i >= 2){
                strcpy(user.followers, token);
                user.followers = user.followers.next;
            }
            token = strtok (NULL, ";");
            i++;
        }
        line++;
    }
    
    
    else if(line > users_total){
        //Apos ler e salvar todas informações de usuários, as linhas seguintes serão de acontecimentos na rede
        
        fscanf(entrada, "%s ", infos);
        token = strtok(infos, ";");
        while (token != NULL){
            if(i == 0){
                strcpy(time_occurred, token);
            }
            else if(i == 1){
                strcpy(code, token);
                i++;
                
                if(code == 1){
                    strcpy(user.id, token);
                    strcpy(message.id, token);
                    strcpy(message.text[141], token);
                }
                else if(code == 2){
                    strcpy(user1.id, token);
                    strcpy(user2.id, token);
                }
                else if(code == 3){
                    strcpy(user1.id, token);
                    strcpy(user2.id, token);
                }
                else if(code == 4){
                    strcpy(user.id, token);
                    strcpy(message.id, token);
                }
                else if(code == 5){
                    strcpy(user.id, token);
                }
                
            }
            token = strtok (NULL, ";");
            i++;
        }
    }
        switch(code){
            case '1':
                postarMensagem(*user, *followers, *message, *entrada, p);
            break;

            case '2':
                iniciarAmizade(*user1, *user2, *followers);
            break;
                
            case '3':
                cancelarAmizade(*user1, *user2, *followers);
            break;
                
            case '4':
                curtirMensagem(*message, time_occurred);
            break;
                
            case '5':
                exibirTimeline(*user, timeline_seen);
                while(timeline_seen.next != NULL){
                    fprintf(saida,"%d , %s" ,*user->id, *user->name);
                    fprintf(saida,"%d , %s" ,timeline_seen.message.id, timeline_seen.message.text[141]);
                    timeline_seen.next = timeline_seen.next.next;
                }
            break;
        }
    
        
    fclose(entrada);
    fclose(saida);

    return 0;
    
}



























