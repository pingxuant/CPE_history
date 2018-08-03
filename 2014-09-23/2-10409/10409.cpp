
//uva10409
#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int n, top, north, west, t;
    char comm[10];

    while(scanf("%d", &n) && n) {
        top = 1; north = 2; west = 3;
        while(n--) {
            scanf("%s", comm);
            t = top;
            if(comm[0] == 'n') {
                top = 7 - north; north = t;
            }
            else if(comm[0] == 'e') {
                top = west; west = 7 - t;
            }
            else if(comm[0] == 's') {
                top = north; north = 7 - t;
            }
            else if(comm[0] == 'w') {
                top = 7 - west; west = t;
            }
        }
        printf("%d\n", top);
    }
    return 0;
}
