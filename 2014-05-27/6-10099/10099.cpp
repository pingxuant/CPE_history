
//uva10099
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, ti = 0, m;
	while(cin >> n >> m && n) {
		int x, y, d;
		int map[101][101] = {};
		for(int i = 0; i < m; i++) {
			cin >> x >> y >> d;
			map[x][y] = d-1;
			map[y][x] = d-1;
		}

		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					if(map[i][k] && map[k][j] && map[i][k] > map[i][j] && map[k][j] > map[i][j])
						map[i][j] = min(map[i][k], map[k][j]);
		
		cin >> x >> y >> d;
		int ans;
		if(d % map[x][y])
			ans = d / map[x][y] + 1;
		else
			ans = d / map[x][y];

		printf("Scenario #%d\n", ++ti);
		printf("Minimum Number of Trips = %d\n\n", ans);

	}
	return 0;
}
