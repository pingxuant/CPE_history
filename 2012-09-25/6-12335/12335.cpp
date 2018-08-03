
//uva12335
#include <iostream>
#include <string>
#include <cstring>
#define LEN 21

using namespace std;

int main() {
	int dataNum;	// dataNum = �D�ؤ��� T
	long long int k, factorial[LEN];
	string s;
	char *ans;

	// �p�� i ���h - factorial[i] = i!
	factorial[0] = 1;
	for(int i = 1; i < LEN; i++)
		factorial[i] = factorial[i - 1] * i;

	cin >> dataNum;	// ���o data �� (�Y T ��)
	for(int d = 0; d < dataNum; d++) {
		cin >> s >> k;	// ���o���� (�Y s, k)

		// initialize
		ans = new char [s.length() + 1];
		memset(ans, '-', sizeof(char) * s.length());
		ans[s.length()] = '\0';

		for(int i = 0; i < s.length(); i++) {
			long long int stage;	// �h���w���Ÿ��᪺�ĴX�Ӧ�m
			int place = 0;	// �ĴX�Ӧ�m

			// �Q�Τ��ϭp�� s[i] ����m (���t�w���Ÿ�����m)
			stage = k / factorial[s.length() - i - 1];
			if(k % factorial[s.length() - i - 1] == 0)
				stage--;

			// �Q�� stage ��X s[i] �b ans ������m
			for(int count = 0; count <= stage; place++) {
				if(ans[place] != '-')
					continue;
				count++;
			}
			ans[place - 1] = s[i];

			// �ץ� k �ȥH�i��U�Ӵ`��
			k = k % factorial[s.length() - i - 1];
			if(k == 0)
				k = factorial[s.length() - i - 1];
		}

		cout << "Case " << d + 1 << ": " << ans << endl;
		delete [] ans;
	}

	return 0;
}