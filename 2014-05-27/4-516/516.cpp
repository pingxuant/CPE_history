
//uva516
#include <iostream>

using namespace std;

void factor(int n) {
	int p[32] = {}, e[32] = {}, cnt = 0;
	for(int i = 2; i * i <= n; ++i) {
		if(!(n % i)) {
			p[cnt] = i;
			for(;!(n % i); n /= i)
				++e[cnt];
			++cnt;
		}
	}
	if(n != 1) {
		p[cnt] = n;
		e[cnt] = 1;
		++cnt;
	}

	cout << p[cnt - 1] << " " << e[cnt - 1];
	for(int i = cnt - 2; i >= 0; --i)
		cout << " " << p[i] << " " << e[i];
	cout << endl;
}

int main()
{
	int p, e;
	while(cin >> p && p) {
		char ch;
		cin.get(ch);
		cin >> e;

		int x;
		for(x = 1; e; --e)
			x *= p;

		while(cin.get(ch) && ch != '\n') {
			cin >> p >> e;
			for(; e; --e)
				x *= p;
		}
		factor(x - 1);
	}
	return 0;
}
