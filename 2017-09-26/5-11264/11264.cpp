
//uva11264
#include <cstdio>
#include <iostream>

using namespace std;

int T, n, c[1005];

int solve() {
    int cur = c[0], ans = 2; /// c[0] and c[n-1] must choose
    for (int i = 1; i < n-1; ++i) {
        if (cur < c[i] && cur + c[i] < c[i+1]) {
            cur += c[i];
            ++ans;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &c[i]);
        printf("%d\n", solve());
    }

    return 0;
}
