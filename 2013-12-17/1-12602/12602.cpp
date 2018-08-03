
//uva12602
#include <iostream>
#include <cstdlib>
using namespace std;

inline int deA(char c) {return c - 'A';}

int main(){
	int case_n;
	cin >> case_n;
	while(case_n--) {
		char input[9];
		cin >> input;
		int scoreA = deA(input[0]) * 26 * 26 + deA(input[1]) * 26 + deA(input[2]);
		int scoreB = atoi(input + 4);
		if(abs(scoreA - scoreB) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
	return 0;
}

