
//uva10666
#include <stdio.h>

int main() {
	int n, x, t, i, k, j;
	int win, lose;

	// two[i] = 2^i
	int two[33] = {0, 1};
	for(i = 2; i < 33; ++i)
		two[i] = two[i-1] * 2;

	scanf("%d", &t);
	while(t--) {
		win = lose = 0;
		scanf("%d %d", &n, &x);
		++n;
		k = x;
		for(i = 1; i < n && k % 2 == 0; ++i)
			k /= 2;
		for(j = i; j < n; ++j) {
			if(k % 2 == 1)
				lose++;
			k /= 2;
		}

		win = two[i] - 1;

		printf("%d %d\n", lose + 1, two[n] - win);
	}
	return 0;
}
