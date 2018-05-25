//
//  adhoc1.c
//
//
//  Created by tatiana on 29/05/17.
//
//
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nivel =  0;
    int valor, maxNivel = 0, casa = 0;
    int x = 0, y = 0;
    int lado = 0;

    while (scanf("%d", &valor) == 1) {
        maxNivel = 1;
        nivel = 0;
        if (valor != 1){
            while(valor > maxNivel){
                nivel++;
                maxNivel = 6*nivel + maxNivel;
            }

            x = nivel;
            y = 0;

            while (valor != maxNivel){
                for (lado = 0; lado < 6; lado++){
                    casa = 0;
                    while (valor != maxNivel && casa != nivel){
                        casa++;
                        maxNivel--;
                        if (lado == 0 && casa <= nivel)
                            y--;
                        if (lado == 1 && casa <= nivel)
                            x--;
                        if (lado == 2 && casa <= nivel){
                            x--;
                            y++;
                        }
                        if (lado == 3 && casa <= nivel)
                            y++;
                        if (lado == 4 && casa <= nivel)
                            x++;
                        if (lado == 5 && casa <= nivel){
                            x++;
                            y--;
                        }
                    }
                }

            }
        }
        else
            printf("0 0\n");
    }
    return 0;
}
