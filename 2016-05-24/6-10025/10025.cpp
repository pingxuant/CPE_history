
//uva10025
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int Case, k;
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &k);
		k = abs(k);

		int n = 0, sum = 0;
		while (sum < k) sum += (++n);

		if (k % 2)
			while (sum % 2 != 1) sum += (++n);
		else
			while (sum % 2 != 0) sum += (++n);

		if (k == 0) printf("3\n");
		else printf("%d\n", n);

		if (Case) printf("\n");
	}
	return 0;
}
