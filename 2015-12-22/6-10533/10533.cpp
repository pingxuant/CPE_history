
//uva10533
#include <stdio.h>
#define MAX 1000000

bool sieve[MAX];
int dp_acc[MAX] = {0};

int digit_sum(int n) {
	int sum = 0;
	for(; n > 0; n /= 10)
		sum += n % 10;
	return sum;
}

void init() {
	sieve[0] = sieve[1] = false;
	for(int i = 2; i < MAX; ++i)
		sieve[i] = true;
	for(int i = 2; i < MAX; i++)
		if(sieve[i])
			for(int j = i+i; j < MAX; j += i)
				sieve[j] = false;

	dp_acc[0] = dp_acc[1] = 0;
	for(int i = 2; i < MAX; ++i)
		dp_acc[i] = dp_acc[i - 1] + (sieve[i] && sieve[digit_sum(i)]);
}

int main() {
	int n, m1, m2;
	init();
	scanf("%d", &n);
	for(int loop = 0; loop < n; ++loop) {
		scanf("%d %d", &m1, &m2);
		printf("%d\n", dp_acc[m2] - dp_acc[m1 - 1]);
	}
	return 0;
}

