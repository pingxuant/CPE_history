
//uva11538
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	LL n, m, ans; // n >= m
	while (scanf("%lld%lld", &m, &n)) {
		if (m == 0 && n == 0)
			break;
		if (m > n) swap(m, n);
		ans = 2 * n * (m * (m - 1) / 2) + 2 * m * (n * (n - 1) / 2); // ï¿½ï¿½ï¿½ï¿½ï¿
		ans = ans + 2 * 2 * ((n - m + 1) * (m * (m - 1) / 2) + 2 * ((m) * (m - 1) * (m - 2) / 6)); // ï¿½ï¿½
		printf("%lld\n", ans);
	}
	return 0;
}
