
//uva10783
#include <iostream>

using namespace std;

int main() {
	int t, ti = 0;
	cin >> t;
	int arr[101] = {};
	for(int i = 1; i < 101; ++i) {
		if(i % 2 == 1)
			arr[i] = i;
		arr[i] += arr[i-1];
	}
	while(ti++ < t) {
		int a, b;
		cin >> a >> b;

		if(a == 0)
			a = 1;

		cout << "Case " << ti << ": " << arr[b] - arr[a-1] << endl;
	}
	return 0;
}
