
//uva612
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DNA {
	public:
	string arr, Bak;
	int score, index;

	void Count(int n) {
		Bak = arr;
		score = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 1; j < n; ++j)
				if(arr[j] < arr[j-1]) {
					swap(arr[j], arr[j-1]);
					++score;
				}
		arr = Bak;
	}
};

bool cmp(DNA x, DNA y) {
	if(x.score != y.score)
		return x.score < y.score;
	else
		return x.index < y.index;
}

int main() {
	DNA S[100];
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < m; ++i) {
			cin >> S[i].arr;
			S[i].index = i;
			S[i].Count(n);
		}

		sort(S, S + m, cmp);
		for(int i = 0; i < m; ++i)
			cout << S[i].arr << endl;

		if(t)
			cout << endl;
	}
	return 0;
}
