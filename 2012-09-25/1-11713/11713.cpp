
//uva11713
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int dataNum;
	string name1, name2;
	bool isSame;
	
	cin >> dataNum;
	for(int d = 0; d < dataNum; d++) {
		cin >> name1 >> name2;
		isSame = true;
		
		// �P�_���׬O�_�@�P
		if(name1.length() != name2.length()) {
			cout << "No" << endl;
			continue;
		}

		for(int i = 0; i < name1.length(); i++) {
			// �P�_�O�_������
			if((name1[i] == 'a' || name1[i] == 'e' || name1[i] == 'i' || name1[i] == 'o' || name1[i] == 'u') && (name2[i] == 'a' || name2[i] == 'e' || name2[i] == 'i' || name2[i] == 'o' || name2[i] == 'u'))
				continue;

			// �P�_�D�������r���O�_�@�P
			if(name1[i] != name2[i]) {
				cout << "No" << endl;
				isSame = false;
				break;
			}
		}

		if(isSame)
			cout << "Yes" << endl;
	}

	return 0;
}