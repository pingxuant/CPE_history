
//uva264
#include <iostream>

using namespace std;

int main() {
	long input_n;
	int numerator, denominator;

	while(cin >> input_n) {
		// �����梯����(diag_n)
		int n;
		int sum = 0;
		for(n = 1; sum < input_n; n++)
			sum += n;
		
		// ��������
		// 以輸����累訰��梯��緸���
		// ����毳�
		numerator = input_n-(sum-(n-1));
		denominator = n-numerator;

		if(n%2 == 1)
			cout << "TERM " << input_n << " IS " << numerator << "/" << denominator << endl;
		else
			cout << "TERM " << input_n << " IS " << denominator << "/" << numerator << endl;
	}
	return 0;
}
