
//uva1513
/// fake segment tree
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXNODE 524287
#define BASE 262144
/// 2^18 = 262144
/// 2^19 = 524288

using namespace std;

int N, M, q, base, nxtp, curp, newp, cnt;
int n[530000];
int p[100005];

void solve() {
    nxtp = BASE + N; /// index of the empty leftmost leaf node

    memset(n, 0, sizeof(n));
    /// initial leaf node
    for (int i = 0; i < N; i++)
        n[BASE + i] = 1;
    /// initial internal node
    for (int i = BASE - 1; i >= 1; i--)
        n[i] = n[i * 2] + n[i * 2 + 1];
    /// initial place
    for (int i = N; i >= 1; i--)
        p[i] = BASE + (N - i);

    for (int i = 0; i < M; i++, nxtp++) {
        scanf("%d", &q);
        /// query(q,infinite)
        cnt = 0;
        int l = p[q], r = MAXNODE;
        for (; l^r^1; l >>= 1, r >>= 1) {
            if(!(l & 1))
                cnt += n[l + 1];
            if (r & 1)
                cnt += n[r - 1];
        }

        if (i != 0) printf(" ");
        printf("%d", cnt);

        /// remove(q)
        curp = p[q];
        while(curp != 0) {
            --n[curp];
            curp /= 2;
        }
        /// update(q)
        p[q] = newp = nxtp;
        while(newp != 0) {
            ++n[newp];
            newp /= 2;
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &N, &M);
        solve();
    }
    return 0;
}

