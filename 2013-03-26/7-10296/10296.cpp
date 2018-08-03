
//uva10296
#include <iostream>
#include <algorithm>
#define MAXPOINT 1 + 15
#define INF 1000000000

using namespace std;

int matrix[MAXPOINT][MAXPOINT], odd[MAXPOINT], dp[1 << MAXPOINT];

// ref: http://mypaper.pchome.com.tw/zerojudge/post/1322922929
int build(int pN, int oddNum) {
    if(pN == 0)
        return 0;

    if(dp[pN] != -1)
        return dp[pN];

    int i, j, tmp;

    dp[pN] = 0xfffffff;
    for(int i = 0; i < oddNum; i++) {
        if(pN & (1 << i)) {
            for(j = i + 1; j < oddNum; j++) {
                if(pN & (1 << j)) {
                    tmp = build(pN - (1 << i) - (1 << j), oddNum);
                    dp[pN] = min(dp[pN], tmp + matrix[odd[i]][odd[j]]);
                }
            }
            break;
        }
    }
    return dp[pN];
}

int main()
{
    int pointNum, roadNum, pointInfo[MAXPOINT], total, x, y, len, oddNum;

    while(cin >> pointNum)  // get point number
    {
        if(pointNum == 0)
            break;

        // get road number
        cin >> roadNum;

        // initialize
        total = 0;
        for(int p = 0; p <= pointNum; p++)
            pointInfo[p] = 0;

        for(int i = 0; i <= pointNum; i++)
            for(int j = 0; j <= pointNum; j++)
                matrix[i][j] = INF;

        for(int d = 0; d < (1 << MAXPOINT); d++)
            dp[d] = -1;

        for(int r = 1; r <= roadNum; r++) {
            // get road information
            cin >> x >> y >> len;

            // each road must walk at least one time
            total += len;

            // calculate each point connect how many road
            pointInfo[x]++;
            pointInfo[y]++;

            // save the minimize one int the matrix
            matrix[x][y] = min(matrix[x][y], len);
            matrix[y][x] = min(matrix[y][x], len);
        }

        // compute the minimize length of each one point to other points
        for(int k = 1; k <= pointNum; k++)
            for(int i = 1; i <= pointNum; i++)
                for(int j = 1; j <= pointNum; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

        // get the odd roads of point's information
        oddNum = 0;
        for(int p = 1; p <= pointNum; p++) {
            if(pointInfo[p] % 2 != 0) {
                odd[oddNum] = p;
                oddNum++;
            }
        }

        // output the final answer
        cout << total + build((1 << oddNum) - 1, oddNum) << endl;
    }

    return 0;
}
