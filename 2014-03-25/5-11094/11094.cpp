
//uva11094
#include <iostream>
#include <cstring>
#define MAX 21

using namespace std;

int row, col, kingX, kingY, landNum, ans;
int path[MAX][MAX];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char map[MAX][MAX], landMark;

// DFS mark the path
void findLand(int i, int j) {
	// column must be linked the start and end
	if(j < 0)
		j = col - 1;
	if(j >= col)
		j = 0;
	
	// find the end of row
	if(i < 0 || i >= row)
		return ;
	
	// has found or not land
	if(path[i][j] != 0 || map[i][j] != landMark)
		return ;
	
	// mark as found
	path[i][j] = 1;
	landNum++;
	
	// find the next point (DFS)
	for(int k = 0; k < 4; k++)
		findLand(i + dir[k][0], j + dir[k][1]);	
}

int main() {
	// get the row and column (next input data)
	while(cin >> row >> col) {
		// get map
		for(int i = 0; i < row; i++)
			cin >> map[i];
		
		// get king point and what mark is land
		cin >> kingX >> kingY;
		landMark = map[kingX][kingY];
		
		// initialize
		ans = 0;
		landNum = 0;
		memset(path, 0, sizeof(path));
		
		// set the king city as marked (don't calculate the king city)
		findLand(kingX, kingY);
		
		// start finding
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				// check each point for DFS
				landNum = 0;
				findLand(i, j);
				
				// find the biggest city without king city
				if(ans < landNum)
					ans = landNum;
			}
		}
		
		// output
		cout << ans << endl;
	}
	
	return 0;
}
