
//uva10763
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 500005

using namespace std;

typedef pair<int, int> PII;

int n;
PII a[N], b[N];

int main(void) {
	int i;

	while(scanf("%d", &n) == 1 && n) {
		for(i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			b[i].first = a[i].second;
			b[i].second = a[i].first;
		}

		sort(a, a + n);
		sort(b, b + n);

        for(i = 0; i < n && a[i].second == b[i].second; ++i);

        if(i == n) puts("YES");
        else puts("NO");
	}
	return 0;
}
