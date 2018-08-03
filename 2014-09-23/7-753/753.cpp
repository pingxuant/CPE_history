
//uva753
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#define MAXN 500

using namespace std;

typedef map<string,int> MSI;
typedef map<string,string> MSS;

int t, n, m, k, nCnt;
bool edge[MAXN][MAXN];
MSI socket;
MSS item;

bool vis[MAXN];
int pre[MAXN];

const bool path(int u) {
	int i;
	for(i = 1; i <= n; ++i) {
		if(edge[u][i] && !vis[i]) {
			vis[i] = true;
			if(!pre[i] || path(pre[i])) {
				pre[i] = u;
				return true;
			}
		}
	}
	return false;
}

const int maxMatch(void) {
	int ret = 0;
	memset(pre, 0, sizeof(pre));
	for(MSS::iterator it = item.begin(); it != item.end(); ++it) {
		memset(vis, false, sizeof(vis));
		if(path(socket[(*it).second])) ++ret;
	}
	return ret;
}

int main(void) {
	int i, j, x, y;
	string tmps1, tmps2;
	
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		item.clear(); socket.clear();
		memset(edge, false, sizeof(edge));
		for(i = 1; i <= n; ++i)
			cin >> tmps1; socket[tmps1] = i;
		
		scanf("%d", &m);
		nCnt = n;
		for(i = 1; i <= m; ++i) {
			cin >> tmps1 >> tmps2;
			item[tmps1] = tmps2;
			if(!socket[tmps2]) socket[tmps2] = ++nCnt;
		}
		scanf("%d", &k);
		for(i = 1; i <= k; ++i) {
			cin >> tmps1 >> tmps2;
			if(!socket[tmps1]) socket[tmps1] = ++nCnt;
			if(!socket[tmps2]) socket[tmps2] = ++nCnt;
			x = socket[tmps1]; y = socket[tmps2];
			edge[x][y] = true;
		}

		for(i = 1; i <= nCnt; ++i)
			edge[i][i] = true;

		for(i = 1; i <= nCnt; ++i)
			for(x = 1; x <= nCnt; ++x)
				for(y = 1; y <= nCnt; ++y)
					edge[x][y] |= (edge[x][i]&edge[i][y]);

		printf("%d\n", m-maxMatch());

		if(t) putchar('\n');
	}

	return 0;
}
