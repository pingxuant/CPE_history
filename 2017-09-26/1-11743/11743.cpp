
//uva11743
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void) {
    int N, i;
    scanf("%d", &N);
    int cred[16];
    while(N--) {
        int a, b;
        for(i = 0; i < 4; i++) {
            scanf("%d", &a);
            cred[i * 4 + 3] = a % 10;
            a = a / 10;
            cred[i * 4 + 2] = a % 10;
            a = a / 10;
            cred[i * 4 + 1 ] = a % 10;
            a = a / 10;
            cred[i * 4] = a % 10;
        }
        b = 0;
        for(i = 0; i < 16; i = i + 2) {
            a = cred[i] * 2;
            b = b + a % 10;
            a = a / 10;
            b = b + a % 10;
        }
        for(i = 1; i < 16; i = i + 2)
            b = b + cred[i];
        if(b % 10)
            printf("Invalid\n");
        else
            printf("Valid\n");
    }
    return 0;
}
