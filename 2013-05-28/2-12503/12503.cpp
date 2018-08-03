
//uva12503
#include <iostream>

using namespace std;

int instructionArray[102];

int getInstrInput() {
	char temp[20];
	int val;
	cin >> temp;

	switch(temp[0]) {
	case 'S':
		cin >> temp;
		cin >> val;
		return instructionArray[val];
	case 'L':
		return -1;
	case 'R':
		return 1;
	}
	//Shoun't touch there
	return 0;
}

int main(){

	int case_n;
	cin >> case_n;

	while(case_n--) {
		int line_n;
		cin >> line_n;
		int ans = 0;
		for(int i = 1; i <= line_n; ++i)
			ans += instructionArray[i] = getInstrInput();

		cout << ans << endl;
	}
	
	return 0;
}
