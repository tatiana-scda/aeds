//Criando TAD para clientes
typedef struct{
    int hora_entrada;
    int hora_saida;
    int hora_atendimento;
    int tempo;
    float gasto_estimado;
    int numero_cliente;
    int desistencia; //1 para p cliente que desistiu, 0 para cliente atendidos.
} tipo_cliente;


/*
typedef struct tipo_celula* pointer;

typedef struct tipo_celula{
    tipo_cliente cliente;
    pointer prox;
} tipo_celula;

typedef struct tipo_lista{
    pointer head;
    pointer last;
} tipo_lista;
*/