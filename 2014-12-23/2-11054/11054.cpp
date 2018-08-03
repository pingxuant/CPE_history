
//uva11054
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n, i;
	int a[100005];
	long long int ans;
	while (scanf("%d", &n) && n) {
		for (i = 0 ; i < n ; i++)
			scanf("%d",&a[i]);
		ans = 0;
		for (i = 0 ; i < n ; i++) {
			ans += (a[i] >= 0 ? a[i] : -a[i]);
			a[i + 1] = a[i] + a[i + 1];
		}

		printf("%lld\n", ans);
	}

	return 0;
}
