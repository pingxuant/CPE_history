
//uva11286
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#define NUM 5
#define LEN 20

using namespace std;

// �P�_�j�p�禡 - �� max_element() �ϥ�
bool isBig(map<string, int>::value_type &a, map<string, int>::value_type &b) {
	return (a.second < b.second);
}

int main() {
	int dataNum, courseNum[NUM], ans;
	map<string, int> course;
	map<string, int>::iterator max;
	char numInChar[LEN];
	string numInString;

	while(cin >> dataNum) {	// ���o�ǥͤH��
		if(dataNum == 0)
			break;

		// initialize
		ans = 0;	// �����̲׵���
		course.clear();	// �O�s�Ҧ��X�{�L���ҵ{�զX + ��ܸӽҵ{�զX���H��

		for(int d = 0; d < dataNum; d++) {
			// ���o�ҵ{�s��
			for(int i = 0; i < NUM; i++)
				cin >> courseNum[i];

			// �ƧǹL�~��P�_�s���O�_�@�P
			sort(courseNum, courseNum + NUM);

			// �q int �}�C�ন char �}�C�A�ন string
			sprintf(numInChar, "%d%d%d%d%d", courseNum[0], courseNum[1], courseNum[2], courseNum[3], courseNum[4]);
			numInString = numInChar;

			// �P�_ map ���O�_�w�X�{�L
			if(course.find(numInChar) == course.end())
				course[numInString] = 1;	// ���X�{�h�� 1
			else
				course[numInString]++;		// �w�X�{�h�֥[
		}

		// ��X�̦h�H�諸�ҵ{�զX���X�ӤH��
		max = max_element(course.begin(), course.end(), isBig);

		// ��X�Ҧ��̦h�H�諸�ҵ{�զX�òέp��H��
		for(map<string, int>::iterator it = course.begin(); it != course.end(); it++) {
			if((*it).second == (*max).second)
				ans += (*max).second;
		}

		// ��X�̲׵���
		cout << ans << endl;
	}

	return 0;
}