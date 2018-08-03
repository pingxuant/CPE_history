
//uva242
#include <cstdlib>
#include <algorithm>  
#include <cstring> 
#include <vector>
#include <cstdio>    
#include <iostream> 

using namespace std;

const int maxn = 1010;
struct node{
	vector<int> a;
	bool operator < (const node& rhs) const {
		if (a.size() < rhs.a.size()) return true;
		else if (a.size() == rhs.a.size()) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] < rhs.a[i])
					return 1;
				if (a[i] > rhs.a[i])
					return 0;
			}
			return false;
		}
		return false;
	}
}plan[100];

bool d[maxn][11], vis[maxn][11];
int s, n, MAX[maxn];

int dp(int i, int j, int k) {
	if (vis[i][j])
		return d[i][j];
	vis[i][j] = true;
	if (i == 0)
		return d[i][j] = 1;
	d[i][j] = false;
	for (int g = 0; g < plan[k].a.size(); g++) {
		int fee = plan[k].a[g];
		if (i >= fee && j > 0 && dp(i - fee, j - 1, k))
			d[i][j] = true;
	}
	return d[i][j];
}

int CMP(const int a, const int b){
	return  a > b;
}

int main(void) {
	while (scanf("%d", &s) && s) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			plan[i].a.clear();
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				plan[i].a.push_back(x);
			}
			sort(plan[i].a.begin(), plan[i].a.end(), CMP);
		}
		sort(plan, plan + n);
		int max_ = 0, posi = 0;
		for (int i = 0; i < n; i++) {
			MAX[i] = 0;
			memset(vis, false, sizeof(vis));
			for (int j = 1;; j++) {
				if (!dp(j, s, i)) {
					MAX[i] = j - 1;
					break;
				}
			}
			if (max_ < MAX[i])
				max_ = MAX[i]; posi = i;
		}
		printf("max coverage =%4d :", max_);
		for (int i = plan[posi].a.size() - 1; i >= 0; i--)
			printf("%3d", plan[posi].a[i]);
		printf("\n");
	}
	return 0;
}
