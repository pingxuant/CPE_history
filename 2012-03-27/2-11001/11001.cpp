
//uva11001
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

/*
	double D = 0.3*sqrt(vt/i - v0)
	double len = D * i

=>
	len = i*0.3*sqrt(vt/i-v0);
	len^2 = i^2*0.09*(vt/i-v0);
	len^2 ~= i*i*(vt/i-v0);
	len^2 ~= i*(vt-v0*i);
	len^2 ~= vt*i-v0*i*i;
*/

int main() {
	double vt, v0;

	while(cin >> vt >> v0 && vt) {
		int i = 1;
		double MaxLen = 0;
		int MaxDiv = 0;
		int cnt = 1;
		while(vt / i > v0) {
			double len = (vt * i - v0 * i * i);

			if(len > MaxLen) {
				MaxLen = len;
				MaxDiv = i;			// the part will make max length.
				cnt = 1;			// new max length, part counter reset.
			}
			else if(len == MaxLen)	// record how many part will make max length.
				++cnt;

			++i;
		}

		if(cnt == 1)				// only one partition could make max length.
			cout << MaxDiv << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}
