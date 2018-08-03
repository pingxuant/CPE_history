
//uva374
#include <cstdio>
#include <iostream>

using namespace std;

long long bpm(long long b, long long p, long long m) {
	long long i, n = b, k, r, a = 1;

	if(b == 0)
		return 0;
	else if(p == 0 || b == 1)
		return 1;
	else if(p == 1)
		return b % m;

	for(i = 1; b < m; i++)
		b *= n;

	k = p % i;

	for(r = 0; r < k; r++)
		a *= n;

	return (a * bpm(b%m, p/i, m)) % m;
}

int main() {
	long long b, p, m, i, k;

	while(cin >> b >> p >> m) {
		if(b >= m)
			b %= m;

		cout << bpm(b, p, m) << endl;
	}
	return 0;
}
