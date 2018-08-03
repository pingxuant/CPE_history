
//uva1225
#include <stdio.h>
#include <string.h>
int digi[10];
int main(void){
    int N, input, i, a, b;
    scanf("%d", &N);
    while (N--){
        memset(digi, 0, sizeof(digi));
        scanf("%d", &input);
        for(i = 1; i <= input; i++){
            a=i;
            while(a)
            {
                digi[a%10]++;
                a=a/10;
            }
        }
        printf("%d", digi[0]);
        for(i = 1; i < 10; i++)
            printf(" %d", digi[i]);
        printf("\n");
    }
    return 0;
}
