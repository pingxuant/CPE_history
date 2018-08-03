
//uva719
#include <iostream>
#include <string>

using namespace std;

int MinExpress(string str, int len) {
	int i = 0, j = 1, k = 0;

	while(k < len && i < len && j < len + 1) {
		int t = str[i+k] - str[j+k];
		if(t == 0)
			++k;
		else {
			if(t > 0)
				i = i + k + 1;
			else
				j = j + k + 1;

			if(i == j)
				++j;

			k = 0;
		}
	}
	return min(i, j);
}

int main() {
	int n;

	cin >> n;
	while(n--) {
		string str;
		cin >> str;

		cout << MinExpress(str+str, str.length())+1 << endl;
	}

	return 0;
}
