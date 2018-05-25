//
//  demogorgon.c
//
//
//
//

#include <stdio.h>

#define max 999999

int min(int a, int b){
    if (a <= b)
        return a;
    else
        return b;
}

int main (){
    int spells, hp, damage, mana, i, j, danoTotal = 0;
    int dano;
    while(scanf("%d %d", &spells, &hp) != EOF){
        danoTotal = 0;
        int sDamage[spells+1], sMana[spells+1];
        int info[spells+1][hp+1];
        
        for (i = 0; i < spells; i++){
            scanf("%d %d", &dano, &mana);
            sDamage[i] = dano;
            sMana[i] = mana;
            danoTotal += dano;
            //   printf("dano tt%d\n", danoTotal);
        }
        
        if (danoTotal < hp)
            printf("-1\n");
        else {
            for (i = 0; i <= spells; i++){
                for (j = 0; j <= hp; j++){
                    if (i == 0 || j == 0)
                        info[i][j] = max;
                    else if (j <= sDamage[i-1]){
                        //             printf("%d %d\n", sDamage[i-1], sMana[i-1]);
                        info[i][j] = min(info[i-1][j], sMana[i-1]);
                    }
                    else if(j > sDamage[i-1])
                        info[i][j] = min(info[i-1][j], (info[i-1][ j-sDamage[i-1] ] + sMana[i-1]));
                }
            }
            //for(i = 0; i <= spells; i++){
            //for (j =0; j <=hp; j++) {
            //   printf("%d ", info[i][j]);
            // }
            //   printf("\n");
            // }
            printf("%d\n", info[spells][hp]);
        }
    }
    return 0;
}
