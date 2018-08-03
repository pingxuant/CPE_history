
//uva315
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;
vector<int> a[N];
bool flag[N], ap[N];
int d[N], low[N];
int n, c, subtree;

void DFS(int u) {
	flag[u] = true;
	low[u] = d[u] = ++c;
	for (vector<int>::iterator it = a[u].begin(); it != a[u].end(); ++it) {
		if (!flag[*it]) {
			DFS(*it);
			low[u] = min(low[u], low[*it]);
			if (low[*it] >= d[u]) {
				if (u != 0)
					ap[u] = true;
				else subtree++;
			}
		}
		else low[u] = min(low[u], d[*it]);
	}
}

bool g[N][N];
char buf[1000], t[100];

int main() {
	int i, j, x, y;
	while (scanf("%d", &n), n) {
		memset(g, 0, sizeof(g));
		while (scanf("%d", &x), x) {
			gets(buf);
			for (i = 0; buf[i] == ' '; i++);
			for (; buf[i]; i += j + 1) {
				for (j = 0; buf[i + j] && buf[i + j] != ' '; j++);
				strncpy(t, buf + i, j);
				t[j] = '\0';
				y = atoi(t);
				g[x - 1][y - 1] = g[y - 1][x - 1] = true;
				if (buf[i + j] == '\0') break;
			}
		}
		
		for (i = 0; i < n; i++) {
			a[i].clear();
			for (j = 0; j < n; j++)
				if (g[i][j]) a[i].push_back(j);
		}
		
		memset(flag, 0, sizeof(flag));
		memset(ap, 0, sizeof(ap));
		subtree = 0;
		c = 0;
		DFS(0);
		if (subtree > 1) ap[0] = true;
		int sum = 0;
		for (i = 0; i < n; i++)
			if (ap[i]) sum++;
		printf("%d\n", sum);
	}
	return 0;
}
