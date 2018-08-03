
//uva10721
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, k, m;
    long long tab[51][51][51] = {0};
    for(int i = 0; i < 51; i++) tab[0][0][i] = 1;
    for(int i = 1; i < 51; i++) {
        for(int j = 1; j < 51; j++) {
            for(int k = 1;k < 51; k++) {
                for(int p = 1; p <= k && p <= i; p++) {
                    tab[i][j][k] += tab[i - p][j - 1][k];
                }
            }
        }
    }
    while(scanf("%d %d %d", &n, &k, &m) == 3) {
        cout << tab[n][k][m] << endl;
    }
    return 0;
}
