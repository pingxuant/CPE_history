
//uva657
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 50

using namespace std;

int row, col, ansNum, caseNum = 1;
int ans[MAX * MAX], pathStar[MAX][MAX], pathX[MAX][MAX];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char picture[MAX][MAX];

// use DFS to check the dice point
void findX(int i, int j) {
    // DFS at leaf point
    if(pathX[i][j] == 1)
        return;

    for(int k = 0; k < 4; k++)
    {
        // out of range
        if(i + dir[k][0] < 0 || i + dir[k][0] >= row)
            continue;
        if(j + dir[k][1] < 0 || j + dir[k][1] >= col)
            continue;

        // not 'X'
        if(picture[i + dir[k][0]][j + dir[k][1]] != 'X')
            continue;

        // has find before
        if(pathX[i + dir[k][0]][j + dir[k][1]] == 1)
            continue;

        // set this point has been check
        pathX[i][j] = 1;

        // find next point
        findX(i + dir[k][0], j + dir[k][1]);
    }

    // set this point has been check
    pathX[i][j] = 1;
}

// use DFS to check the dice
void findStar(int i, int j) {
    // DFS at leaf point
    if(pathStar[i][j] == 1)
        return;

    for(int k = 0; k < 4; k++) {
        // out of range
        if(i + dir[k][0] < 0 || i + dir[k][0] >= row)
            continue;
        if(j + dir[k][1] < 0 || j + dir[k][1] >= col)
            continue;

        // not '*'
        if(picture[i + dir[k][0]][j + dir[k][1]] == '.')
            continue;

        // has find before
        if(pathStar[i + dir[k][0]][j + dir[k][1]])
            continue;

        // we need to check
        if(picture[i + dir[k][0]][j + dir[k][1]] != '.') {
            // find the dice point and use DFS to check that point
            if(picture[i + dir[k][0]][j + dir[k][1]] == 'X' && pathX[i + dir[k][0]][j + dir[k][1]] == 0) {
                // find the dice point
                ans[ansNum]++;

                // use DFS to check that dice point
                findX(i + dir[k][0], j + dir[k][1]);
            }

            // set this point has been check
            pathStar[i][j] = 1;

            // find next point
            findStar(i + dir[k][0], j + dir[k][1]);
        }
    }

    // set this point has been check
    pathStar[i][j] = 1;
}

int main() {
    // get first input
    cin >> col >> row;

    while(row != 0 && col != 0) {
        // get picture
        for(int i = 0; i < row; i++)
            cin >> picture[i];

        // initialize
        ansNum = 0;
        memset(pathStar, 0, sizeof(pathStar));
        memset(pathX, 0, sizeof(pathX));
        memset(ans, 0, sizeof(ans));

        // find how many dices (the first star position)
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(picture[i][j] != '.' && pathStar[i][j] == 0) {
                    findStar(i, j);

                    // the first 'X' haven't count
                    if(picture[i][j] == 'X')
                        ans[ansNum]++;

                    ansNum++;
                }
            }
        }

        // sort the answer
        sort(ans, ans + ansNum);

        // output the answer
        cout << "Throw " << caseNum << endl;
        for(int i = 0; i < ansNum - 1; i++)
            cout << ans[i] << ' ';
        cout << ans[ansNum - 1] << endl << endl;

        // get next input
        cin >> col >> row;
        caseNum++;
    }

    return 0;
}
