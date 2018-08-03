
//uva10050
#include <iostream>

using namespace std;

int main() {
	int dataNum, day, political, *noWork, ans;
	bool *eachDays;

	cin >> dataNum;	// ���o��Ƽ�
	for(int d = 0; d < dataNum; d++) {
		cin >> day >> political;	// ���o�ѼơB�F�Ҽ�

		// initialize
		ans = 0;
		noWork = new int [political];
		eachDays = new bool [day];
		for(int i = 0; i < day; i++)
			eachDays[i] = false;

		// �O���U�F�Ҥ��O�}�u�X��
		for(int i = 0; i < political; i++)
			cin >> noWork[i];

		// �O���Ҧ��F�Ҫ��}�u��l
		for(int i = 0; i < political; i++)
			for(int j = noWork[i] - 1; j < day; j += noWork[i])
				eachDays[j] = true;

		// �έp�@���X�ѽ}�u����l (�P�����B�����~)
		for(int i = 0; i < day; i++)
			if(eachDays[i] && i % 7 != 5 && i % 7 != 6)
				ans++;

		delete [] noWork;
		delete [] eachDays;
		cout << ans << endl;	// ��X�̫ᵪ��
	}

	return 0;
}