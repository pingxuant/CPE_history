
//uva10035
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	int da[15], db[15];
	int i, j, cat, cnt;
	while(cin >> a >> b && (a+b)!=0) {
		for(i = 0; i < 15; i++)
			da[i] = db[i] = 0;
		i = a;
		j = b;

		for(cnt = 0; i != 0; cnt++, i /= 10)
			da[cnt] = i % 10;

		for(cnt = 0; j != 0; cnt++, j /= 10)
			db[cnt] = j % 10;

		for(i = 0, cat = 0; i < 14; i++) {
			da[i] += db[i];
			if(da[i] > 9) {
				da[i+1] ++;
				da[i] %= 10;
				cat++;
			}
		}

		if(cat == 0)
			printf("No carry operation.\n");
		else if(cat == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", cat);
	}
	return 0;
}
