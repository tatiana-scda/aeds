//
//  badSet.c
//  
//
//  Created by tatiana on 20/04/17.
//https://www.urionlinejudge.com.br/judge/en/problems/view/2087
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, tam_string = 0, tam_string2 = 0;
    int i = 0, j = 0, k = 0, n = 0, count = 0;
    char string[101];
    char **sentences;
    
    while(1){
        scanf("%d", &N);
        if(N==0) break;
    
        
        sentences = (char**)calloc(N,sizeof(char*));
        
        for(i = 0; i < N;i++)
            sentences[i] = (char*)calloc(101,sizeof(char));
        
        if(sentences == NULL)
            printf("error\n");
        
        
        for(k = 0; k < N; k++){
            scanf("%s", string);
            tam_string = strlen(string);
            for (j = 0; j < tam_string; j++){
                sentences[k][j] = string[j];
            }
        }
        
        /*
         //Imprimir matriz
        for(i = 0; i < N;i++){
            for(j = 0; j < 101;j++)
                printf("%c", sentences[i][j]);
            printf("\n");
        }
        */
        
        //Até aqui alocou a matriz com todas as palavras
        //Agora comparar
    

    
        for (n = 0; n < N; n++){
            tam_string = strlen(sentences[n]);
            tam_string2 = strlen(sentences[n+1]);
            
            for (i = 0; (i < tam_string) && (sentences[n][i] != '\0'); i++){
                if (sentences[n][i] == sentences[n+1][i])
                    count++;
                
                if((sentences[n][count+1]) == '\0' || (sentences[n+1][count+1]) == '\0'){
                    printf("Conjunto Ruim\n");
                    break;
                }
        
            
            }
        }
        printf("Conjunto Bom\n");
        
        
        
        //Desalocar
        for(i = 0; i < N; i++)
            free(sentences[i]);
        
            free(sentences);
    }
    
    return 0;
}

/*
 tam_string = strlen(sentences[n]);
 tam_string2 = strlen(sentences[n+1]);
 
 for (i = 0; (i < tam_string) && (sentences[n][i] != '\0'); i++){
 if (sentences[n][i] == sentences[n+1][i])
 count++;
 
 }
 
 if((sentences[n][count+1]) == '\0' || (sentences[n+1][count+1]) == '\0'){
 printf("Conjunto Ruim\n");
 break;
 }
 }
 
 printf("Conjunto Bom\n");
 */




