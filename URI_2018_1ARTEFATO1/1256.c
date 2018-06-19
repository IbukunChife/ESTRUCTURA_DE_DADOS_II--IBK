#include<stdio.h>
#include<stdlib.h>

typedef struct vector
{
    int *valores;
    int indice;
}vector;



int main(){
     int testCases, m, c, n;
     int i,j,h;

     scanf("%d",&testCases);
     for(i = 0; i < testCases; i++){
        scanf("%d %d",&m,&c);
        int *hash;
        vector hashv[m];
        for( j =0; j <  m; j++){
            hashv[j].indice = 0;
            hashv[j].valores = (int*)calloc(50, sizeof(int));
        }
        for(j = 0; j < c; j++){
            scanf("%d",&n);

            hashv[n % m].valores[hashv[n % m].indice] = n;
            hashv[n%m].indice++;
        }
         for (h = 0; h < m; h++) {
                printf("%d",h);
                for(j = 0; j < hashv[h].indice; j++){
                    if( hashv[h].valores[j] != 0)
                        printf(" -> %d",hashv[h].valores[j]);
                }
            printf(" -> \\\n");
        }
        if(i+1 != testCases)
            printf("\n");
     }
     return 0;
}
