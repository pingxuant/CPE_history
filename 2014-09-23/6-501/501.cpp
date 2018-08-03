
//uva501
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define N 30010

using namespace std;

typedef priority_queue<int> PQI;

int k, m, n, I;
int a[N], u[N];

int main(void) {
	int i, l;
	scanf("%d", &k);
	
	while(k--) {
		PQI minQ, maxQ;
		scanf("%d%d", &m, &n);

		for(i = 1; i <= m; ++i) scanf("%d", &a[i]);
		for(i = 1; i <= n; ++i) scanf("%d", &u[i]);

		I = 1;
		for(l = 1; l <= m; ++l) {
			maxQ.push(a[l]);
			minQ.push(-maxQ.top());
			maxQ.pop();

			while(I <= n && u[I] == l) {
				maxQ.push(-minQ.top()); minQ.pop();
				printf("%d\n", maxQ.top());
				++I;
			}
		}

		if(k) putchar('\n');
	}
	return 0;
}
