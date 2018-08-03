
//uva12149
#include <iostream>
using namespace std;

int ans1(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int ans2(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i * i;
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		cout << ans2(n) << endl;
	}
	return 0;
}

