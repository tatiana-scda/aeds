#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ep1.h"


int conversao_hora_min(int hora, int min){
    return (hora * 60) + min;
}

void imprime_hora(int tempo){
    int hora, min;
    hora = tempo/60;
    min = tempo%60;
    printf("%d:%d\n", hora, min);
}

int tempo_medio_desistencia(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int total = 0;
    int numero = 0;
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].desistencia == 1){
            total += (cliente[i].hora_saida - cliente[i].hora_entrada);
            numero++;
        }
    }
    
    return total/numero;
}

int tempo_medio_geral(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int total = 0;
    int numero = 0;
    for (i = 0; i < clientes_atuais; i++){
        total += (cliente[i].hora_saida - cliente[i].hora_entrada);
        numero++;
    }
    return total/numero;
}

int tempo_medio_atendimento(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int total = 0;
    int numero = 0;
    for (i = 0; i < clientes_atuais; i++){
        total += (cliente[i].hora_atendimento - cliente[i].hora_saida);
        numero++;
    }
    return total/numero;

}

float valor_perdido(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int perdido = 0;
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].desistencia == 1){
            perdido += (cliente[i].gasto_estimado);
        }
    }
    return perdido;
    
}

float valor_ganho(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int ganho = 0;
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].desistencia == 0){
            ganho += (cliente[i].gasto_estimado);
        }
    }
    return ganho;
}

int clientes_desistentes(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int desistentes = 0;
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].desistencia == 1){
            desistentes++;
        }
    }
    return desistentes;
}

int clientes_atentidos(tipo_cliente *cliente, int clientes_atuais){
    int i;
    int atendidos = 0;
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].desistencia == 0){
            atendidos++;
        }
    }
    return atendidos;
}

//Case 1
void chegada(FILE *arquivo_entrada, tipo_cliente* cliente, int *total_clientes, int *clientes_atuais){
    int hora, min;
    fscanf(arquivo_entrada, "%d:%d ", &hora, &min);
    //Acesso a hora de entrada do cliente de acordo com sua entrada
    fscanf(arquivo_entrada, "%d ", &cliente[*clientes_atuais].numero_cliente);
    fscanf(arquivo_entrada, "%f\n", &cliente[*clientes_atuais].gasto_estimado);
    cliente[*clientes_atuais].hora_entrada = conversao_hora_min(hora, min);

    *total_clientes+=1;
    *clientes_atuais+=1;
}


//Case 2
void atendimento(FILE *arquivo_entrada, tipo_cliente* cliente, int clientes_atuais){
    int hora, min, numero_aux, i;
    fscanf(arquivo_entrada, "%d:%d ", &hora, &min);
    fscanf(arquivo_entrada,"%d ", &numero_aux);
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].numero_cliente == numero_aux){
            cliente[i].hora_atendimento = conversao_hora_min(hora, min);
            break;
        }
    }
    
}

//Case 3
void saida(FILE *arquivo_entrada, tipo_cliente* cliente, int clientes_atuais){
    int hora, min, numero_aux, i;
    fscanf(arquivo_entrada, "%d:%d ", &hora, &min);
    fscanf(arquivo_entrada,"%d ", &numero_aux);
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].numero_cliente == numero_aux){
            cliente[i].hora_saida = conversao_hora_min(hora, min);
            break;
        }
    }
}

//Case 4

void desistencia(FILE *arquivo_entrada, tipo_cliente* cliente, int clientes_atuais){
    int hora, min, numero_aux, i;
    fscanf(arquivo_entrada, "%d:%d ", &hora, &min);
    fscanf(arquivo_entrada,"%d ", &numero_aux);
    for (i = 0; i < clientes_atuais; i++){
        if (cliente[i].numero_cliente == numero_aux){
            cliente[i].desistencia = 1;
            cliente[i].hora_saida = conversao_hora_min(hora, min);
            break;
        }
    }
    
}

//Case 5
void imprimir(FILE *arquivo_saida, int clientes_atuais, *consulta){
    arquivo_saida = fopen("arquivo_saida.rtf", "a");
        printf("Consulta numero: %d", *consulta++);
        printf("Quantidade de clientes que entraram: %d ", clientes_atuais);
        printf("Quantidade de clientes atendidos: %d ", clientes_atentidos(cliente, clientes_atuais));
        printf("Quantidade de clientes desistentes: %d ", clientes_desistentes(cliente, clientes_atuais));
        printf("Tempo medio em fila geral: ");
        imprime_hora(tempo_medio_geral);
        printf("Tempo medio em fila antes de desistir: ");
        imprime_hora(tempo_medio_desistencia);
        printf("Tempo medio de atendimento: ");
        imprime_hora(tempo_medio_atendimento);
        printf("Valor vendido estimado: %d ", valor_ganho(cliente, clientes_atuais));
        printf("Valor perdido estimado: %d ", valor_perdido(cliente, clientes_atuais));
}