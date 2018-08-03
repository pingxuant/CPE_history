
//uva10954
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

template <typename T,typename U,typename V>
T pop(priority_queue<T, U, V> &q) {
	T ret = q.top();
	q.pop();
	return ret;
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		
		priority_queue<ll, vector<ll>,greater<ll>> q;
		while (n--) {
			int x;
			cin >> x;
			q.push(x);
		}
		
		ll sum = 0;
		while (q.size() > 1) {
			ll cost = pop(q) + pop(q);
			sum += cost;
			q.push(cost);
		}
		cout << sum << endl;
	}
	return 0;
}

