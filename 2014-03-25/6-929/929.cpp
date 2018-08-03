
//uva929
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int N = 1000;
int INF = 100000000;
int g[1000][1000], cost[1000][1000];
int r, c;

struct node {
	int x, y, w;
	bool operator < (const struct node a) const {
	   return w > a.w;
	}
} tl;

void dij() {
	int a, b;
	bool vis[1000][1000];
	priority_queue <struct node> pq;
	memset(vis, 0, sizeof(vis));
	g[1][1] = cost[1][1];
	tl.x = tl.y = 1, tl.w = g[1][1];
	pq.push(tl);
	while (!pq.empty()) {
		tl = pq.top();
		pq.pop();
		a = tl.x, b = tl.y;
		if (vis[a][b])
			continue;
		vis[a][b] = true;
		if (a > 1 && !vis[a - 1][b] && g[a - 1][b] > g[a][b] + cost[a - 1][b]) {
			g[a - 1][b] = g[a][b] + cost[a - 1][b];
			tl.x = a - 1;
			tl.y = b;
			tl.w = g[a - 1][b];
			pq.push(tl);
		}
		if (a < r && !vis[a + 1][b] && g[a + 1][b] > g[a][b] + cost[a + 1][b]) {
			g[a + 1][b] = g[a][b] + cost[a + 1][b];
			tl.x = a + 1;
			tl.y = b;
			tl.w = g[a + 1][b];
			pq.push(tl);
		}
		if (b > 1 && !vis[a][b - 1] && g[a][b - 1] > g[a][b] + cost[a][b - 1]) {
			g[a][b - 1] = g[a][b] + cost[a][b - 1];
			tl.x = a;
			tl.y = b - 1;
			tl.w = g[a][b - 1];
			pq.push(tl);
		}
		if (b < c && !vis[a][b + 1] && g[a][b + 1] > g[a][b] + cost[a][b + 1]) {
			g[a][b + 1] = g[a][b] + cost[a][b + 1];
			tl.x = a, tl.y = b + 1, tl.w = g[a][b + 1];
			pq.push(tl);
		}
	}
}

int main() {
	int T, i, j;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &r, &c);
		for (i = 1; i <= r; ++i) {
			for (j= 1; j <= c; ++j) {
				scanf("%d", &cost[i][j]);
				g[i][j] = INF;
			}
		}
		dij();
		printf("%d\n", g[r][c]);
	}
	return 0;
}

