
//uva147
#include <iostream>
#include <iomanip>
#include <cstdio>

#define Max 30001

long long way[Max][11]={};

using namespace std;

int f(int c, int index) {
	int i;
	for(i = 0; i < c; i += 5)
		way[i][index] = way[i][index-1];
	for(i = c; i < Max; i += 5)
		way[i][index] = way[i-c][index] + way[i][index-1];
}

int main() {
	long long i, j;

	for(i = 0; i < Max; i+=5)
		way[i][0] = 1;
	
	f(10, 1);
	f(20, 2);
	f(50, 3);
	f(100, 4);
	f(200, 5);
	f(500, 6);
	f(1000, 7);
	f(2000, 8);
	f(5000, 9);
	f(10000, 10);

	int a, b;
	while(scanf("%d.%d\n", &a, &b) == 2 ) {
		if(a == 0 && b == 0)
			break;
		else {
			printf("%3d.", a);
			if(b < 10)
				cout << "0" << b;
			else
				cout << b;
			cout << setw(17) << way[a*100+b][10] << endl;
		}
	}
	return 0;
}
