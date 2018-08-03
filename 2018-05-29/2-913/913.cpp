
//uva913
#include <stdio.h>
#include <assert.h>

int main() {
	unsigned long long N;

	while (scanf("%llu", &N) == 1) {
		N = (N + 1) * (N + 1) * 3 / 2 - 9;
		printf("%llu\n", N);
	}

	return 0;
}
