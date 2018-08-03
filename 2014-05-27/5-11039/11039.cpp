
//uva11039
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

bool cmp(int a,  int b) {
	return abs(a) < abs(b);
}

int main() {
	int floor[500000];
	int T, num, i;
	while(scanf("%d",  &T) == 1) {
		while(T--)
		{
			int judge = 0, ans = 0, last = 0;
			memset(floor, 0, sizeof(floor));
			scanf("%d", &num);
			for(i = 0; i <num; i++)
				scanf("%d", &floor[i]);
			sort(floor, floor+num, cmp);
			for(i = 0; i < num; i++) {
				if(judge == 0) {
					last = abs(floor[i]);
					ans++;
					judge = floor[i] > 0 ? 2 : 1;
				}
				else if(judge == 1 && abs(floor[i]) > last && floor[i] > 0) {
					last = abs(floor[i]);
					ans++;
					judge = 2;
				}
				else if(judge == 2 && abs(floor[i]) > last && floor[i] < 0) {
					last = abs(floor[i]);
					ans++;
					judge = 1;
				}
			}
			printf("%d\n", ans);
		}
		return 0;
	}
}
