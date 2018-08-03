
//uva722
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <deque>
#define SIZE (2 + 99)

using namespace std;

// ���
struct Point {
    int x;
    int y;

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

// 檢����� Deque �
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
        // � case ��空��
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
        getchar();  // 測��空��

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

            // � nX, nY ��寫太
            nX = myQue.front().x;
            nY = myQue.front().y;

            // if ��置� land ���
            if(area[nX][nY] == '1') {
                path = 0;
                break;
            }

            // �走���
            area[nX][nY] = '2';
            path++;

            // 檢���走��
            if(area[nX - 1][nY] == '0' && !findInDeque(myQue, Point(nX - 1, nY)))
                myQue.push_back(Point(nX - 1, nY));

            if(area[nX + 1][nY] == '0' && !findInDeque(myQue, Point(nX + 1, nY)))
                myQue.push_back(Point(nX + 1, nY));

            if(area[nX][nY - 1] == '0' && !findInDeque(myQue, Point(nX, nY - 1)))
                myQue.push_back(Point(nX, nY - 1));

            if(area[nX][nY + 1] == '0' && !findInDeque(myQue, Point(nX, nY + 1)))
                myQue.push_back(Point(nX, nY + 1));

            // ��� deque pop 
            myQue.pop_front();
        }

        // output final answer
        cout << path << endl;
    }

    return 0;
}
