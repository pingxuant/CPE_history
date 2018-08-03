
//uva264
#include <iostream>

using namespace std;

int main() {
	long input_n;
	int numerator, denominator;

	while(cin >> input_n) {
		// ¨çºå¨åªäæ¢¯åè§ç·ä¸(diag_n)
		int n;
		int sum = 0;
		for(n = 1; sum < input_n; n++)
			sum += n;
		
		// ¾å°å¯åè§ç·å¾ï¼
		// ä»¥è¼¸¥æ¸å¼æ¤ç´¯è¨°åä¸æ¢¯åè§ç·¸å¸çé¤
		// »æ¨çå­æ¯³å
		numerator = input_n-(sum-(n-1));
		denominator = n-numerator;

		if(n%2 == 1)
			cout << "TERM " << input_n << " IS " << numerator << "/" << denominator << endl;
		else
			cout << "TERM " << input_n << " IS " << denominator << "/" << numerator << endl;
	}
	return 0;
}
