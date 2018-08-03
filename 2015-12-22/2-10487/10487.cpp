
//uva10487
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[1005];

int int_abs(int n) { return n >= 0 ? n : -n; }

int solve(int num) {
	int i, j, ans = a[0]+a[1]; // at least two
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(int_abs(a[i] + a[j] - num) < int_abs(ans - num))
				ans = a[i] + a[j];
	return ans;
}

int main() {
	int i, req, tcnt = 0;
	while(scanf("%d", &n) == 1 && n != 0) {
		printf("Case %d:\n", ++tcnt);
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%d", &req);
			printf("Closest sum to %d is %d.\n", req, solve(req));
		}
	}
	return 0;
}
