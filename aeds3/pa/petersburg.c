#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M, K, i, p1;
    int *convidados;
    int *pessoa;
    int *flag;

    while (scanf("%d %d %d\n", &N, &M, &K) != EOF){
        convidados = (int*)calloc(M,sizeof(int));
        pessoa = (int*)calloc(M,sizeof(int));
        flag = (int*)calloc(M,sizeof(int));

        for (i = 0; i < M; i++){
            scanf("%d", &p1); scanf("%d", pessoa[p1]); //O indice será o numero da pessoa que é amiga da pessoa # valor que esta na casa
            flag[p1]++;
        }
        for(i = 0; i < M; i++){
              if (flag[i] >= K)
              convidados[i] = 1;
          }
          for(i = 0; i < M; i++){
              if (convidados[i] == 1)
                  printf("%d ", i);
          }
          printf("\n");
    }
free(convidados); free(pessoa); free(flag);
return 0;
}
