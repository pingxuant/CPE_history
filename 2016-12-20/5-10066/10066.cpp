
//uva10066
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
int a[105], b[105];
int dp[105][105];


int main() {
    int tcnt = 0;
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        for (int i = 1 ; i <= n ; i++)
            scanf("%d", &a[i]);
        for (int i = 1 ; i <= m ; i++)
            scanf("%d", &b[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        printf("Twin Towers #%d\n", ++tcnt);
        printf("Number of Tiles : %d\n\n", dp[n][m]);
    }

    return 0;
}


