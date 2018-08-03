
//uva12223
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define MAX 50005
#define INF (1LL<<60)

using namespace std;

typedef long long ll;

class Edge{
public:
    int s;
    ll d;
    Edge(int _s, ll _d): s(_s), d(_d) {}
};

typedef vector<Edge> VE;

int c, n, m, a, b;
ll t, f;
VE e[MAX]; /// edge info for each subway
ll cnt[MAX]; /// times to travel for each subway
ll totcnt[MAX], sumcnt;
bool vis[MAX];
ll dp[MAX], ans;

ll dfs1(int cur) {
    for (int i = 0; i < e[cur].size(); ++i) {
        Edge next = e[cur][i];
        if (vis[next.s] == false) {
            vis[next.s] = true;
            ll subtotcnt = dfs1(next.s);
            dp[0] += 2 * subtotcnt * next.d;
            totcnt[cur] += subtotcnt;
        }
    }
    return totcnt[cur];
}

void dfs2(int cur) {
    for (int i = 0; i < e[cur].size(); ++i) {
        Edge next = e[cur][i];
        if (vis[next.s] == false) {
            vis[next.s] = true;
            dp[next.s] = dp[cur] + (sumcnt - 2 * totcnt[next.s]) * 2 * next.d;
            ans = min(ans, dp[next.s]);
            dfs2(next.s);
        }
    }
}

int main() {
    scanf("%d", &c);
    for (int ccnt = 0; ccnt < c; ++ccnt) {
        scanf("%d", &n); /// 0 ~ n-1
        for (int i = 0; i < MAX; ++i)
            e[i].clear();
        for (int i = 1; i <= n - 1; ++i) {
            scanf("%d%d%lld", &a, &b, &t);
            e[a - 1].push_back(Edge(b - 1, t));
            e[b - 1].push_back(Edge(a - 1, t));
        }

        scanf("%d", &m);
        sumcnt = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(totcnt, 0, sizeof(totcnt));
        for (int i = 1; i <= m; ++i) {
            scanf("%d%lld", &a, &f);
            totcnt[a - 1] = cnt[a - 1] = f;
            sumcnt += f;
        }
        memset(vis, false, sizeof(vis));
        dp[0] = 0;
        vis[0] = true;
        dfs1(0); /// start from subway 0

        memset(vis, false, sizeof(vis));
        vis[0] = true;
        ans = dp[0];
        dfs2(0);

        /// output
        int pflag = false;
        printf("%lld\n",ans);
        for (int i = 0; i < n; ++i) {
            if(dp[i] == ans) {
                if(pflag == true)
                    printf(" ");
                pflag = true;
                printf("%d", i + 1);
            }
        }
        printf("\n");
    }

    return 0;
}
