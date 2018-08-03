
//uva12439
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int f(int n) {
	int sum = n / 4;
	sum -= (n / 100);
	sum += (n / 400);

	return sum;
}

int main() {
	int t, ti = 0;
	cin >> t;
	while(ti++ < t) {
		string mm1, mm2;
		int d1, d2, y1, y2, m1, m2;
		cin >> mm1;
		scanf("%d, %d", &d1, &y1);
		cin >> mm2;
		scanf("%d, %d", &d2, &y2);

		for(int i = 0; i < 12; ++i) {
			if(Month[i] == mm1)
				m1 = i;
			if(Month[i] == mm2)
				m2 = i;
		}
		if(m1 > 1)	// March 1~Dec 31
			++y1;
		if(m2 == 0 || (m2 == 1 && d2 != 29))	// Jan 1~Feb 28
			--y2;

		cout << "Case " << ti << ": " << f(y2) - f(y1-1) << endl;
	}
	return 0;
}
