
//uva798
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 15
#define W 105

using namespace std;

int w[N], h[N], m[N], n, ans;
bool puz[W][W];

bool valid(int nx, int ny, int nw, int nh) {
	if(nx+nw > w[0] || ny+nh > h[0]) return false;

	static int dx, dy;

	for(dx = nx; dx < nx + nw; ++dx)
		for(dy = ny; dy < ny + nh; ++dy)
			if(puz[dx][dy])
				return false;

	return true;
}

void setTile(int nx, int ny, int nw, int nh, bool val) {
	static int dx, dy;
	nw += nx;
	nh += ny;

	for(dx = nx ; dx < nw; ++dx)
		for(dy = ny ; dy < nh; ++dy)
			puz[dx][dy] = val;
}

void pmap(void) {
	static int x, y;

	for(x = 0; x < w[0]; ++x) {
		for(y = 0; y < h[0]; ++y)
			putchar(puz[x][y] ? 'X':'_');
		putchar('\n');
	}
	putchar('\n');
}

void dfs(int nx, int ny) {

	if(ny == h[0]) {
		if(nx == w[0] - 1) {
			++ans;
			return;
		}
		else {
			++nx;
			ny = 0;
		}
	}

	int i;

	if(!puz[nx][ny]) {
		for(i = 1; i <= n; ++i) {
			if(m[i]) {
				if(valid(nx, ny, w[i], h[i])) {
					setTile(nx, ny, w[i], h[i], true); --m[i];
					dfs(nx, ny + 1);
					setTile(nx, ny, w[i], h[i], false); ++m[i];
				}

				if(w[i] != h[i] && valid(nx, ny, h[i], w[i])) {
					setTile(nx, ny, h[i], w[i], true); --m[i];
					dfs(nx, ny + 1);
					setTile(nx, ny, h[i], w[i], false); ++m[i];
				}
			}
		}
	}
	else
		dfs(nx, ny+1);
}

int main(void) {
	int i;

	while(scanf("%d%d%d", &w[0], &h[0], &n) == 3) {

		// input
		for(i = 1; i <= n; ++i)
			scanf("%d%d%d", &m[i], &w[i], &h[i]);

		// initialize
		ans = 0;
		memset(puz, false, sizeof(puz));
		
		// solve
		dfs(0, 0);

		// output
		printf("%d\n", ans);

	}

	return 0;
}
