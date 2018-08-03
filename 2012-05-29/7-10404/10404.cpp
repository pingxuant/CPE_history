
//uva10404
#include <iostream>
#include <cstring>

using namespace std;

int dp[1000001];

int main() {
	int n;
	while(cin >> n) {
		int m, arr[20] = {};
		
		cin >> m;
		for(int i = 0; i < m; ++i)
			cin >> arr[i];

		dp[0] = 2;
		for(int i = 1; i <= n; ++i) {
			bool flag = 0;
			for(int k = 0; k < m; ++k) {
				if(i - arr[k] >= 0) {
					if(dp[i - arr[k]] == 2) {
						flag = 1;
						break;
					}
				}
			}
			dp[i] = (flag ? 1 : 2);
		}

		cout << (dp[n] == 1 ? "Stan wins\n" : "Ollie wins\n");
	}
	return 0;
}
