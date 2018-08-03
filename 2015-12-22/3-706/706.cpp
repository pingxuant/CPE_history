
//uva706
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int head[]  ={1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
int upperl[]={1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
int upperr[]={1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
int mid[]   ={0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
int lowerl[]={1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
int lowerr[]={1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
int btm[]   ={1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

int main() {
    int i, j, n, len;
    char s[10];
    int is[10];
    while(scanf("%d %s",&n,s) == 2 && n) {
        for(i = 0, len = strlen(s); i < len; i++)
            is[i] = s[i] - '0';

        for(i = 0; i < len; i++) {
            if(i) printf(" ");
            printf(" ");
            for(j = 0; j < n; j++)
                printf("%c", head[is[i]] == 1 ? '-' : ' ');
            printf(" ");
        }
        printf("\n");
		
        for(int k = 0; k < n; k++) {
            for(i = 0; i < len; i++) {
                if(i) printf(" ");
                printf("%c", upperl[is[i]] == 1 ? '|' : ' ');
                for(j = 0; j < n; j++)
                    printf(" ");
                printf("%c", upperr[is[i]] == 1 ? '|' : ' ');
            }
            printf("\n");
        }
		
        for(i = 0; i < len; i++) {
            if(i) printf(" ");
            printf(" ");
            for(j = 0; j < n; j++)
                printf("%c", mid[is[i]] == 1 ? '-' : ' ');
            printf(" ");
        }
        printf("\n");
		
        for(int k = 0; k < n; k++) {
            for(i = 0; i < len; i++) {
                if(i) printf(" ");
                printf("%c", lowerl[is[i]] == 1 ? '|' : ' ');
                for(j = 0; j < n; j++)
                    printf(" ");
                printf("%c", lowerr[is[i]] == 1 ? '|' : ' ');
            }
            printf("\n");
        }
		
        for(i = 0; i < len; i++) {
            if(i) printf(" ");
            printf(" ");
            for(j = 0; j < n; j++)
                printf("%c", btm[is[i]] == 1 ? '-' : ' ');
            printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
