
//uva10177
#include <iostream>

using namespace std;

int main() {
	int n;
	long long arr[101][6] = {};

	for(n = 1; n < 101; n++) {
		long long all = ((n+1) * n) / 2;
		arr[n][0] = arr[n-1][0] + n * n;
		arr[n][1] = all * all - arr[n][0];
		arr[n][2] = arr[n-1][2] + n * n * n;
		arr[n][3] = all * all * all - arr[n][2];
		arr[n][4] = arr[n-1][4] + n * n * n * n;
		arr[n][5] = all * all * all * all - arr[n][4];
	}

	while(cin >> n)
		cout << arr[n][0] << " " << arr[n][1] << " " << arr[n][2] << " " << arr[n][3] << " " << arr[n][4] << " " << arr[n][5] << endl;
	return 0;
}
