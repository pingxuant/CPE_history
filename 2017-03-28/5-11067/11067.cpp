
//uva11067
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    int w = 0, h = 0, n = 0, wx = 0, wy = 0;
    long long path[101][101];
    while (scanf("%d %d", &w, &h) == 2) {
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i <= h; i++)
            for (int j = 0; j <= w; j++)
                path[i][j] = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> wx >> wy;
            path[wy][wx] = -1;
        }
        for (int i = 0; i <= h; i++)
            for (int j = 0; j <= w; j++) {
                if (path[i][j] == -1)
                    path[i][j] = 0;
                else {
                    if (i == 0 && j == 0)
                        path[0][0] = 1;
                    else if (i == 0)
                        path[i][j] = path[i][j - 1];
                    else if (j == 0)
                        path[i][j] = path[i - 1][j];
                    else
                        path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        if (path[h][w] == 0)
            cout << "There is no path.\n";
        else if (path[h][w] == 1)
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
        else
            cout << "There are " << path[h][w] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
    }
    return 0;
}


