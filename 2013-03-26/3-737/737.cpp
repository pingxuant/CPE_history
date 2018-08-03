
//uva737
#include <iostream>

using namespace std;

int main() {
    int caseNum, x, y, z, distance, xMin, xMax, yMin, yMax, zMin, zMax;
    bool noAnswer;

    while(cin >> caseNum) {  // read case number
        if(caseNum == 0)
            break;

        noAnswer = false;
        for(int c = 0; c < caseNum; c++) {
            cin >> x >> y >> z >> distance; // read input

            if(c == 0) { // initialize
                xMin = x;
                xMax = x + distance;
                yMin = y;
                yMax = y + distance;
                zMin = z;
                zMax = z + distance;
            }

            // æª¢æ¥æ¯å¦æäº¤é
            if(xMin > x + distance && yMin > y + distance && zMin > z + distance)
                noAnswer = true;

            if(xMax < x && yMax < y && zMax < z)
                noAnswer = true;

            // äº¤é¾åºäº¤ç¯
            if(!noAnswer) {
                if(x > xMin)
                    xMin = x;

                if(x + distance < xMax)
                    xMax = x + distance;

                if(y > yMin)
                    yMin = y;

                if(y + distance < yMax)
                    yMax = y + distance;

                if(z > zMin)
                    zMin = z;

                if(z + distance < zMax)
                    zMax = z + distance;
            }
        }

        // ¹æäº¤é¡è¼¸ºçæ¡
        if(noAnswer)
            cout << 0 << endl;
        else
            cout << (xMax - xMin) * (yMax - yMin) * (zMax - zMin) << endl;
    }

    return 0;
}
