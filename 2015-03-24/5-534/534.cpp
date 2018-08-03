
//uva534
#include <cstdio>
#include <cmath>
#include <iostream>
#define MAXN 205

using namespace std;

double d[MAXN][MAXN];
int x[MAXN], y[MAXN];

double dis(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

int main() {
	int i, j, k, n, testcase = 0;

	while (scanf("%d",&n) && n) {
		for (i = 0; i < n; i++)
			scanf("%d %d",&x[i],&y[i]);

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = dis(i,j);

		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					d[i][j] = min(max(d[i][k], d[k][j]), d[i][j]);
				
		printf("Scenario #%d\n", ++testcase);
		printf("Frog Distance = %.3lf\n\n", d[0][1]);
	}
	return 0;
}
