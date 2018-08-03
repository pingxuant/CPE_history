
//uva1210
#include <iostream>

#define Max 10001

using namespace std;

void MakePrime(int Prime[], int &Cnt) {
	int table[Max] = {};
	for(int i = 2; i < Max; ++i) {
		if(!table[i]) {
			Prime[Cnt++] = i;
			for(int j = 2; i * j < Max; ++j)
				table[i*j] = 1;
		}
	}
}

int main() {
	int Prime[Max] = {};
	int Cnt = 1;
	MakePrime(Prime, Cnt);

	int PreSum[Max] = {};

	PreSum[0] = Prime[0];
	for(int i = 1; i < Cnt; ++i)
		PreSum[i] = Prime[i] + PreSum[i-1];

	int dif[Max] = {};
	for(int i = 0; i < Cnt; ++i)
		for(int j = i + 1; j < Cnt; ++j)
			if(PreSum[j] - PreSum[i] < Max)
				++dif[ PreSum[j] - PreSum[i] ];

	int n;
	while(cin >> n && n)
		cout << dif[n] << endl;

	return 0;
}
