
//uva10018
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int data;

	cin >> data;	// å¾è¦¤æ·çè³

	for(int d = 0; d < data; d++) {
		char sNum[11], srNum[11] = "";
		bool isReverse = false;
		int count = 0;
		long long int num, rNum;

		// è®¸åä¸¦åè½
		cin >> sNum;
		for(int i = strlen(sNum) - 1, j = 0; i >= 0; i--, j++)
			srNum[j] = sNum[i];

		while(!isReverse) {
			count++;	// çµ±è·èäºå¹¾æ¬¡
			
			// å¾å­è½¸åå¥½åè¨ç®
			num = atol(sNum);
			rNum = atol(srNum);

			// å¾¸åè½å­ä¸¦åè½å¥½æè¼
			sprintf(sNum, "%lld", num + rNum);
			for(int i = strlen(sNum) - 1, j = 0; i >= 0; i--, j++)
				srNum[j] = sNum[i];

			// ¤æ·æ¯å¦å
			if(strcmp(sNum, srNum) == 0)
				isReverse = true;
		}

		// è¼¸åºæå¾ç­æ¡
		cout << count << ' ' << sNum << endl;
	}

	return 0;
}