#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função para impressão do array de operadores
void imprimeArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++){
        //Os valores 1 no array correspondem à '*' e os valores 0 correspondem à '+'
        if(array[i]){
            printf("*");
        }
        else{
            printf("+");
        }
    }
    printf("\n");
}

//Função para copiar uma string para outra
void copiaString(int origem[], int *destino, int tamanhoString){
    int i;
    for (i = 0; i < tamanhoString; i++){
        destino[i] = origem[i];
    }
}

//Função recursiva que encontra todas as possibilidades válidas
void resolve(int nivel, int valores[], int indiceValores, int operadores[], int indiceOperadores, int indice, int tamanhoString,char *stringOriginal,int resultado, int ultimoNivel){
    //Condição de parada da função recursiva: Ter chegado no último nível da árvore
    if(nivel > ultimoNivel){
        //Caso o resultado seja igual ao valor no final das operações, imprime os operadores correspondentes
        if(valores[0] == resultado){
            imprimeArray(operadores, ultimoNivel);
        }
        return;
    }

    //Copia a string de entrada para uma nova variável, para não alterar o valor original
    char *novaStringOriginal = malloc(201*sizeof(char));
    strcpy(novaStringOriginal, stringOriginal);

    //Variáveis auxiliares
    int novoIndice = 0, valorA, valorB;

    //Loop para percorrer cada substring separada por um espaço dentro da string
    char *numeroConversao = strtok(novaStringOriginal, " ");
    while(numeroConversao != NULL){
        //Continua sem fazer nada até encontrar onde parou na ultima chamada
        if(novoIndice >= indice){
            //Caso o caractere seja interrogação, interrompe a inserção no array
            if(numeroConversao[0] == '?'){
                break;
            }
            //Caso contrário, é um numero valido, e deve ser inserido no array de valores
            valores[indiceValores] = atoi(numeroConversao);
            indiceValores++;
        }
        //Pega a próxima substring
        numeroConversao = strtok(NULL," ");
        novoIndice++;
    }

    //Pega os dois ultimos valores do array, para serem empilhados e multiplicados
    valorA = valores[indiceValores-2], valorB = valores[indiceValores - 1];
    
    //Cria dois arrays para guardar os valores caso somados e multplicados, e mais dois arrays para guardar os operadores dessas operações
    int valoresSoma[tamanhoString], valoresMultiplicacao[tamanhoString], operadoresSoma[tamanhoString], operadoresMultiplicacao[tamanhoString];

    //Copia os valores para as novas pilhas de soma e multiplicação
    copiaString(valores, valoresSoma,tamanhoString);
    copiaString(valores, valoresMultiplicacao,tamanhoString);

    //Copia os operadores para os novos vetores de operadores
    copiaString(operadores, operadoresSoma,tamanhoString);
    copiaString(operadores, operadoresMultiplicacao,tamanhoString);

    //Adiciona o valor da soma dos dois elementos retirados no array
    valoresSoma[indiceValores - 2] = valorA+valorB;
    //Adiciona o operador '+' no array de operadores
    operadoresSoma[indiceOperadores] = 0;
    //Realiza a chamada recursiva para o novo vetor gerado com a soma dos dois elementos
    resolve(nivel+1, valoresSoma, indiceValores-1, operadoresSoma, indiceOperadores+1, novoIndice+1, tamanhoString, stringOriginal, resultado, ultimoNivel);

    //Adiciona o valor da multiplicacao dos dois elementos retirados no array
    valoresMultiplicacao[indiceValores - 2] = valorA*valorB;
    //Adiciona o operador '*' no array de operadores
    operadoresMultiplicacao[indiceOperadores] = 1;
    //Realiza a chamada recursiva para o novo vetor gerado com a multiplicação dos dois elementos
    resolve(nivel+1, valoresMultiplicacao, indiceValores-1, operadoresMultiplicacao, indiceOperadores+1, novoIndice+1, tamanhoString, stringOriginal, resultado, ultimoNivel);
}

int main(int argc, char *argv[]) {
    //Variáveis auxiliares
    char stringOriginal[201];
    int resultado = 0, tamanhoString = 0, ultimoNivel = 0, i = 0;
    int valores[201], operadores[201];

    //Pega a string de entrada
    fgets(stringOriginal, 201, stdin);
    //Pega o resultado esperado
    scanf("%d", &resultado);

    //Percorre toda a string
    while(stringOriginal[i] != '\0'){
        //Conta quantas palavras separadas por espaço a entrada possui
        if(stringOriginal[i] == ' '){
            tamanhoString++;
        }
        //Conta quantos níveis a árvore terá
        if(stringOriginal[i] == '?'){
            ultimoNivel++;
        }
        i++;
    }
    
    //Realiza a chamada da função recursiva para encontrar os valores possíveis
    resolve(1, valores, 0,operadores, 0, 0,tamanhoString+1,stringOriginal,resultado, ultimoNivel); 

    return 0;
}
