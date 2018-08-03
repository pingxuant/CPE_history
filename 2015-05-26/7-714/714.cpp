
//uva714
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int N, m, k, i, p[505], cnt, s[505];
	long long r, l, t, sum;

	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &m, &k);

		r = l = 0;
		for(i = 0; i < m; ++i) {
			scanf("%d", &p[i]);
			if(l < p[i]) l = p[i];
			r += p[i];
		}

		while(l < r) {
			t = (r + l) / 2;
			cnt = sum = 0;
			for(i = 0; i < m; ++i) {
				sum += p[i];
				if(sum > t) {
					++cnt;
					sum = p[i];
				}
			}

			if(cnt < k) r = t;
			else l = t + 1;
		}

		cnt = sum = 0;
		memset(s, 0, sizeof(s));
		for(i = m - 1; i >= 0; --i) {
			sum += p[i];
			if(sum > r || i < k - cnt - 1) {
				s[i] = 1;
				++cnt;
				sum = p[i];
			}
		}
		
		for(i = 0; i < m; ++i) {
			if(i) printf(" ");
			printf("%d", p[i]);
			if(s[i])
				printf(" /");
		}
		printf("\n");
	}
	return 0;
}
