#include <stdio.h>
#include <string.h>

int main(){
    
    char laugh[51];
    char funny[51];
    int i = 0;
    int j = 0;
    int flag = 1;
    int tam;
    int aux;
    
    scanf("%s", laugh);
    
    while (laugh[i] != '\0') {
        if (laugh[i] == 'a' || laugh[i] == 'e' || laugh[i] == 'i' || laugh[i] == 'o' || laugh[i] == 'u') {
            funny[j] = laugh[i];
            i++;
            j++;
        }
        else i++;
    }
    
    funny[j] = '\0';
    tam = j-1;
    aux = tam/2;
    
    for (i = 0; i < aux; i++, tam--) {
        
        if (funny[i] != funny[tam]) {
            flag = 0;
        }
    }
    
    if (flag == 0){
        printf("N\n");
    }
    else if (flag == 1){
        printf("S\n");
    }
    
    return 0;
}
