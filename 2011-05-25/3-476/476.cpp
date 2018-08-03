
//uva476
#include <cstdio>
#include <iostream>

#define Max 20

using namespace std;

int main()
{
	int flag = 1;
	double lx[Max], ly[Max], rx[Max], ry[Max];
	char ch;
	double x, y;

	int i = 0, cnt = 0;
	while(scanf("%c", &ch) != EOF) {
		if(ch == 'r') {
			scanf("%lf %lf %lf %lf\n", &lx[cnt], &ly[cnt], &rx[cnt], &ry[cnt]);
			cnt++;
		}
		else
			break;
	}


	int num = 1;
	while(scanf("%lf %lf\n", &x, &y) == 2) {
		if(x == 9999.9 && y == 9999.9)
			break;
		flag = 0;
		for(i = 0; i < cnt; i++) {
			if(x > lx[i] && x < rx[i] && y < ly[i] && y > ry[i]) {
				flag = 1;
				printf("Point %d is contained in figure %d\n", num, i + 1);
			}
		}
		if(!flag)
			printf("Point %d is not contained in any figure\n", num);

		num++;
	}
	return 0;
}
