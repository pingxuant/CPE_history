
//uva722
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <deque>
#define SIZE (2 + 99)

using namespace std;

// ç´æ¨è»
struct Point {
    int x;
    int y;

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

// æª¢æ¥æ¯å¦å¨æ Deque ä¸
bool findInDeque(deque<Point> myDeque, Point myPoint) {
    for(int f = 0; f < myDeque.size(); f++) {
        if(myDeque[f].x == myPoint.x && myDeque[f].y == myPoint.y)
            return true;
    }

    return false;
}

int main()
{
    int caseNum, sX, sY, row, column, path;
    char area[SIZE][SIZE], buf[SIZE];
    deque<Point> myQue;

    cin >> caseNum; // get case number
    for(int c = 0; c < caseNum; c++) {
        // æ¯ case ä¹è¦ç©ºäè¡
        if(c != 0)
            cout << endl;

        // initialize
        myQue.clear();
        column = 0;
        path = 0;
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                area[i][j] = '1';

        // get start point
        cin >> sX >> sY;
        getchar();  // æ¸¬å¼éç©ºç½è

        cin.getline(buf, SIZE); // read data
        row = strlen(buf);      // calculate how many rows
        while(strlen(buf) != 0) {
            column++;   // calculate how many columns
            strncpy(area[column] + 1, buf, strlen(buf));    // puts into my array

            cin.getline(buf, SIZE); // read data
        }

        // use BFS to find the answer
        myQue.push_back(Point(sX, sY)); // push start point to deque
        while(!myQue.empty()) {  // end for empty
            int nX, nY;

            // è¨ nX, nY ¿åå¯«å¤ª
            nX = myQue.front().x;
            nY = myQue.front().y;

            // if å§ä½ç½®æ land ä¸è¦ä½
            if(area[nX][nY] == '1') {
                path = 0;
                break;
            }

            // ç´èµ°éä½ç½
            area[nX][nY] = '2';
            path++;

            // æª¢æ¥å¶ä½èµ°ä½ç½
            if(area[nX - 1][nY] == '0' && !findInDeque(myQue, Point(nX - 1, nY)))
                myQue.push_back(Point(nX - 1, nY));

            if(area[nX + 1][nY] == '0' && !findInDeque(myQue, Point(nX + 1, nY)))
                myQue.push_back(Point(nX + 1, nY));

            if(area[nX][nY - 1] == '0' && !findInDeque(myQue, Point(nX, nY - 1)))
                myQue.push_back(Point(nX, nY - 1));

            if(area[nX][nY + 1] == '0' && !findInDeque(myQue, Point(nX, nY + 1)))
                myQue.push_back(Point(nX, nY + 1));

            // å®å¾å¾ deque pop 
            myQue.pop_front();
        }

        // output final answer
        cout << path << endl;
    }

    return 0;
}
