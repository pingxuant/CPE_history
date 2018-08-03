
//uva10474
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 10005

using namespace std;

int main(void) {
	int N, Q, cnt[MAX], x, i, cas = 1;
	bool v[MAX];

	while(scanf("%d %d", &N, &Q) && (N || Q)) {
		printf("CASE# %d:\n", cas++);

		memset(cnt, 0, sizeof(cnt));
		memset(v, false, sizeof(v));
		for(i = 0; i < N; ++i) {
			scanf("%d", &x);
			++cnt[x];
			v[x] = true;
		}
		for(i = 1, cnt[0] = 1; i < MAX; ++i)
			cnt[i] += cnt[i - 1];

		for(i = 0; i < Q; ++i) {
			scanf("%d", &x);
			if(!v[x]) printf("%d not found\n", x);
			else printf("%d found at %d\n", x, cnt[x - 1]);
		}
	}
	return 0;
}
