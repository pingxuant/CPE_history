
//uva1644
#include <stdio.h>
#define SIZE 1300000

int t[SIZE] = {0};

int main(void) {
    int i, j, n, gap;

    t[0] = t[1] = 1;
    for (i = 2; i < SIZE; i++) {
        if(t[i] == 0) {
            for(j = i+i; j < SIZE; j += i) 
                t[j] = 1;
        }
    }

	while (scanf("%d", &n) && n != 0) {
        gap = 0;
        for (i = n; t[i] != 0; i--) 
            gap++;
        for (i = n; t[i] != 0; i++) 
            gap++;

        printf("%d\n", gap);
    }


    return 0;
}
