
//uva10369
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#define MAXV (500+1)
#define MAXE (500*500+1)

using namespace std;

double x[MAXV], y[MAXV];
int S, P, E, totS;
int fa[MAXV];

struct edge{
	int n1, n2;
	double dis;
	void init (int n1, int n2) {
		this->n1 = n1;
		this->n2 = n2;
		dis = sqrt((x[n1] - x[n2]) * (x[n1] - x[n2]) + (y[n1] - y[n2]) * (y[n1] - y[n2]));
	}
}e[MAXE];

bool ecmp (edge e1, edge e2) {
	return e1.dis < e2.dis;
}

int find_set(int n) {
	if (fa[n] == n)
		return n;
	else
		return fa[n] = find_set(fa[n]);
}

void union_set(int x, int y) {
	int rx = find_set(x);
	int ry = find_set(y);
	if (rx != ry) {
		fa[ry] = rx;
		totS --;
	}
}


double kruskal() {
	int i, n1, n2;
	double ans = 0;
	for (i = 0; i < E && totS > S; i++) {
		n1 = e[i].n1;
		n2 = e[i].n2;
		union_set(n1, n2);
		ans = max(ans, e[i].dis);
	}
	return ans;
}

int main() {
	int i, j, t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &S, &P);
		for (i = 0; i < P; i++)
			scanf("%lf %lf",&x[i],&y[i]);
		for (E = 0, i = 0; i < P; i++)
			for (j = i + 1; j < P; j++)
				e[E++].init(i, j);

		totS = P;
		sort(e,e + E,ecmp);
		for (i = 0; i < P; i++)
				fa[i] = i;
		printf("%.2lf\n",kruskal());
	}
	return 0;
}
