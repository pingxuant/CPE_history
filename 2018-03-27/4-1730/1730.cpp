
//uva1730
#include <stdio.h>
using namespace std;

int main() {
	long long n;
	while (scanf("%lld", &n) == 1 && n) {
	    long long l = 1, r, val;
        long long ret = 0;
        while (l <= n) {
            val = n / l;
            r = n / val;
            ret += val * ((l + r) * (r - l + 1) / 2);
            l = r + 1;
        }
		printf("%lld\n", ret - 1);
	}
	return 0;
}
