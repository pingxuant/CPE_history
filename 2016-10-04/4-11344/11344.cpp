
//uva11344
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int t, N, n[15];
char str[1000 + 5];

bool check() {
    int res;
    for (int i = 0; i < N; i++) {
        res = 0;
        for (int j = 0; j < strlen(str); j++) {
            res = (res * 10) + (str[j] - '0');
            res = res % n[i];
        }
        if (res != 0) return false;
    }

    return true;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &str);
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &n[i]);
        if (check())
            printf("%s - Wonderful.\n", str);
        else
            printf("%s - Simple.\n", str);
    }
    return 0;
}
