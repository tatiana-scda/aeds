//
//  radars.c
//  
//
//  Created by tatiana on 02/07/17.
//
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int testes, i, a, radar, dist, valor;
    int max = 1000000 + 10; //espec
    int *temp, *posicaoRadar, *aux, *lucro;
    
    scanf("%d", &testes);
    
    for (a = 0; a < testes; a++){
        scanf("%d %d", &radar, &dist);
    
        temp = (int*) calloc (radar,sizeof(int)); //variavel axiliar
        posicaoRadar = (int*) calloc (max,sizeof(int));
        aux = (int*) calloc (max,sizeof(int)); //variavel axiliar
        lucro = (int*) calloc (max,sizeof(int)); //vai controlar valores de cada um
        
        for (i = 0; i < radar; i++){
            scanf("%d", &temp[i]);
            posicaoRadar[temp[i]] = 1;
        }
        for (i = 0; i < radar; i++){
            scanf("%d", &valor);
            if (lucro[temp[i]] < valor) //lucro = maior
                lucro[temp[i]] = valor;
        }
        for (i = max - 2; i >= 0; i--) {
            aux[i] = aux[i + 1];
            if (posicaoRadar[i] && i + dist < max){
                if (aux[i] < lucro[i] + aux[i + dist]) //aux = maior
                    aux[i] = lucro[i] + aux[i + dist];
            }
        }
        printf("%d\n", aux[0]);
        free(temp); free(posicaoRadar); free(aux); free(lucro);
        
    }
    return 0;
}
