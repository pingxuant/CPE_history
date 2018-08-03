
//uva1650
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1024
#define MOD 1000000007

using namespace std;

char s[MAXN];
int dp[MAXN][MAXN], sum[MAXN][MAXN];

int main() {
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        dp[0][1] = sum[0][1] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= i + 2; j++) {
                if (s[i] == 'I' || s[i] == '?')
                    dp[i+1][j] = (dp[i+1][j] + sum[i][j-1]) % MOD;
                if (s[i] == 'D' || s[i] == '?')
                    dp[i+1][j] = (dp[i+1][j] + (sum[i][i+1] - sum[i][j-1]) % MOD + MOD) % MOD;
                sum[i+1][j] = (sum[i+1][j-1] + dp[i+1][j]) % MOD;
            }
        }

        printf("%d\n",sum[n][n+1]);
    }
    return 0;
}


