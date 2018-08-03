
//uva686
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int prime[32769] = {0}; // 2^15 + 1
	int input, ans_count;

	for (int i = 2; i <= 32768; ++i) {
		if (prime[i] == 0) {
			for (int j = i; i * j <= 32768; ++j) {
				prime[i * j] = 1;	// 1 represents the index is not a prime number
			}
		}
	}

	while (scanf("%d", &input) != EOF && input != 0) {
		ans_count = 0;
		for (int i = 2; i <= input / 2; ++i) {
			if (prime[i] == 0 && prime[input - i] == 0) {
				++ans_count;
			}
		}
		printf("%d\n", ans_count);
	}

    return 0;
}

