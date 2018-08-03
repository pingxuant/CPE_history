
//uva488
#include <stdio.h>

int main(void){
    int N, tc = 0, a, f, i, j, k;
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &a, &f);
        for(i = 1; i <= f; i++){
            if(tc++)
                printf("\n");
            for(j = 1; j <= a; j++){
                for(k = 1; k <= j; k++)
                    printf("%d", j);
                printf("\n");
            }
            for(j = a - 1; j >= 1; j--){
                for(k = 1; k <= j; k++)
                    printf("%d", j);
                printf("\n");
            }

        }
    }
    return 0;
}
