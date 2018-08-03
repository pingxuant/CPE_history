
//uva10038
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	bool isJolly;
	int dataNum, *data;
	vector<int> minus;

	while(cin >> dataNum) {	// �康度
		// �
		data = new int [dataNum];
		minus.clear();
		isJolly = true;

		// 紴��
		for(int d = 0; d < dataNum; d++)
			cin >> data[d];

		// �箸���差�
		for(int i = 1; i < dataNum; i++)
			minus.push_back(abs(data[i] - data[i - 1]));

		// �
		sort(minus.begin(), minus.end());

		// ����� Jolly jumper
		for(int i = 0; i < minus.size() && isJolly; i++)
			if(minus[i] != i + 1)
				isJolly = false;

		// 輸����
		if(isJolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

		// ���
		delete [] data;
	}

	return 0;
}