//
//  seuMadruga.c
//  
//
//  Created by tatiana on 21/06/17.
//
//

#include <stdio.h>

int corte (long int tiras, int papeis[tiras], int area, long int maxTira){
    long int tamanhoCorte, areaCorte, i, restoCorte = 0;
    int cortado[tiras];
    
    tamanhoCorte = maxTira/2.00;
    
    for (i = 0; i < tiras; i ++){
        if (papeis[i] > tamanhoCorte)
            areaCorte += papeis[i] - tamanhoCorte;
    }
    
    while (areaCorte > 0.0001){
        if (areaCorte == area)
            return tamanhoCorte;
        else
       corte (tiras, &papeis[tiras], area, maxTira);
    }
}

int main (){
    long int tiras, area, h, i, comprimento, compCorte, maxTira = 0;
    
        while (scanf("%ld %ld", &tiras, &area) && tiras != 0 && area != 0){
            
            int papeis[tiras];
            
            
            for (i = 0; i < tiras; i++){
                scanf("%ld", &comprimento);
                if (comprimento == 0)
                    break;
                else
                    papeis[i] = comprimento;
            }
            for (i = 0; i < tiras; i ++)
                if(papeis[i] > maxTira)
                    maxTira = papeis[i];
            
            compCorte = corte (tiras, &papeis[tiras], area, maxTira);
            
            if (compCorte)
                printf("%.4ld\n", compCorte);
            else if (compCorte == 0)
                printf(":D\n");
            else
                printf("-.-\n");
    }
    
    return 0;
}
