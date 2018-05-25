//
//  guga_1781.c
//  
//
//  Created by tatiana on 05/04/17.
//
//gcc guga_1781.c -Wall -o guga_1781

#include <stdio.h>


int main() {
    
    int T; //# strings
    long int Q; //# operations
    int operator;
    int walk;
    char aux;
    char S[10001];
    char S2[10001];
    char cons[10001]; //string de consoantes na palavra
    char vog[10001]; //string de vogais
    int i = 0; int j = 0; int k = 0; int m; int n;
    int tamV = 0;
    int tamC = 0;
    
    scanf("%d", &T);
    scanf("%s", S);
    scanf("%ld", &Q);


    for (m = 1; m <= T; m++){
        
        while (S[i] != '\0') {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
                vog[tamV] = S[i];
                i++;
                tamV++;
            }
            else  {
                cons[tamC] = S[i];
                i++;
                tamC++;
            }
        }

        vog[tamV] = '\0';
        cons[tamC] = '\0';

        //printf("%s\n%s \n", cons, vog);
        
        i = 0;
        for (n = 1; n <= Q; n++) { //fazer todos casos
            
            scanf("%d %d", &operator, &walk);
            
            printf("Caso #%d:\n", n);
            
            if (operator == 0) {
                aux = vog[(i+walk) % tamV];
                vog[(i+walk) % tamV] = vog[i];
            }

            else if (operator == 1) {
                aux = cons[(i+walk) % tamC];
                cons[(i+walk) % tamC] = cons[i];
            }

            else if (operator == 2) {
                i = 0; j = 0; k = 0;
                while (S[i] != '\0') {
                    if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
                        S2[i] = vog[j];
                        j++; i++;
                    }
                    else  {
                        S2[i] = cons[k];
                        i++; k++;
                    }
                }
                printf("%s", S2);
            }
        }
    }

    return 0;
}
