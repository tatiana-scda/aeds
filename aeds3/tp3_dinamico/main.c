//
//  main.c
//
//
//  Created by tatiana on 21/06/17.
//
//

#include "utils.h"


int main() {
    char algoritmo;
    int bares, i, num1, num2;
    
    scanf("%c", &algoritmo); //guloso dinamico bruto
    scanf("%d", &bares);
    
    tipoPares *relacao = (tipoPares*) calloc(bares,sizeof(tipoPares));
    
    for (i = 0; i < bares; i++){
        scanf("%d %d", &num1, &num2);//um dos dois tem que ser par
        if (num1%2 == 0){ //separa todos pares na primeira coluna e impares na segunda
            relacao[i].bar = num1;
            relacao[i].casa = num2;
        }
        else {
            relacao[i].bar = num2;
            relacao[i].casa = num1;
        }
    }
    
    if (algoritmo == 'g')
        mainGuloso(relacao, bares);
    
    else if (algoritmo == 'd')
        dinamico(relacao, bares);

    else if (algoritmo == 'b')
        mainForcaBruta(relacao, bares);
    
    free(relacao);
    return 0;
    
}
