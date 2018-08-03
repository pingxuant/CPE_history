
//uva10018
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int data;

	cin >> data;	// �覤���

	for(int d = 0; d < data; d++) {
		char sNum[11], srNum[11] = "";
		bool isReverse = false;
		int count = 0;
		long long int num, rNum;

		// 许�並��
		cin >> sNum;
		for(int i = strlen(sNum) - 1, j = 0; i >= 0; i--, j++)
			srNum[j] = sNum[i];

		while(!isReverse) {
			count++;	// 統���幾次
			
			// ��轸�好���
			num = atol(sNum);
			rNum = atol(srNum);

			// 徸���並��好��
			sprintf(sNum, "%lld", num + rNum);
			for(int i = strlen(sNum) - 1, j = 0; i >= 0; i--, j++)
				srNum[j] = sNum[i];

			// �����
			if(strcmp(sNum, srNum) == 0)
				isReverse = true;
		}

		// 輸�����
		cout << count << ' ' << sNum << endl;
	}

	return 0;
}