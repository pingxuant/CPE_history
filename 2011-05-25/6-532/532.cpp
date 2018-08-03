
//uva532
#include <iostream>
#include <cstdio>

#define Max 31

using namespace std;

class node {
public:
	int x, y, z;

	node() {
		x = y = z = 0;
	}
	void set(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
}root, end;


char map[Max][Max][Max];
bool done[Max][Max][Max];
int path[Max][Max][Max];
class node que[30000];

void insert(int x, int y, int z, int &cnt, int dep) {
	que[cnt].set(x, y, z);
	path[x][y][z] = dep+1;
	done[x][y][z] = true;
	cnt++;
}

int main() {
	int L, R, C;
	int i, j, k;
	while(cin >> L >> R >> C && L) {
		for(i = 0; i < Max; i++)
			for(j = 0; j < Max; j++)
				for(k = 0; k < Max; k++)
					map[i][j][k] = done[i][j][k] = path[i][j][k] = 0;

		for(i = 0; i < L; i++)
			for(j = 0; j < R; j++) {
				scanf("%s", map[i][j]);
				for(k = 0; k < C; k++)
				{
					if(map[i][j][k] == 'S')
						root.set(i, j, k);
					else if(map[i][j][k] == 'E')
						end.set(i, j, k);
				}
			}

		que[0] = root;
		int head = 0, tail = 1, dep = 0;
		while(head < tail) {
			int tx = que[head].x, ty = que[head].y, tz = que[head].z, td = path[tx][ty][tz];

			if(tx > 0 	&& !done[tx-1][ty][tz] && map[tx-1][ty][tz] != '#')	insert(tx-1, ty  , tz  , tail, td);
			if(tx < L-1	&& !done[tx+1][ty][tz] && map[tx+1][ty][tz] != '#')	insert(tx+1, ty  , tz  , tail, td);
			if(ty > 0	&& !done[tx][ty-1][tz] && map[tx][ty-1][tz] != '#')	insert(tx  , ty-1, tz  , tail, td);
			if(ty < R-1	&& !done[tx][ty+1][tz] && map[tx][ty+1][tz] != '#')	insert(tx  , ty+1, tz  , tail, td);
			if(tz > 0	&& !done[tx][ty][tz-1] && map[tx][ty][tz-1] != '#')	insert(tx  , ty  , tz-1, tail, td);
			if(tz < C-1	&& !done[tx][ty][tz+1] && map[tx][ty][tz+1] != '#')	insert(tx  , ty  , tz+1, tail, td);

			head++;
		}

		if(path[end.x][end.y][end.z] > 0)
			printf("Escaped in %d minute(s).\n", path[end.x][end.y][end.z]);
		else
			printf("Trapped!\n");
	}
	return 0;
}
