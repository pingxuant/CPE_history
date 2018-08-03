
//uva11040
#include <iostream>

int arr[9][9];

void getInput();
void doOutput();
void makeBaseRow();
void makeArrByBaseRow();

int main() {
	int case_n;
	std::cin >> case_n;
	while(case_n--) {
		getInput();
		makeBaseRow();
		makeArrByBaseRow();
		doOutput();
	}
	return 0;

}

void getInput() {
	using namespace std;
	cin >> arr[0][0];

	cin >> arr[2][0] >> arr[2][2];

	cin >> arr[4][0] >> arr[4][2] >> arr[4][4];

	cin >> arr[6][0] >> arr[6][2] >> arr[6][4] >> arr[6][6];

	cin >> arr[8][0] >> arr[8][2] >> arr[8][4] >> arr[8][6] >> arr[8][8];
}

void doOutput() {
	using namespace std;
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < i; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << arr[i][i] << endl;
	}
}

void makeBaseRow() {
	// D = a + 2b + c ==> b = (D - a - c) / 2
	arr[8][1] = (arr[6][0] - arr[8][0] - arr[8][2]) / 2;
	arr[8][3] = (arr[6][2] - arr[8][2] - arr[8][4]) / 2;
	arr[8][5] = (arr[6][4] - arr[8][4] - arr[8][6]) / 2;
	arr[8][7] = (arr[6][6] - arr[8][6] - arr[8][8]) / 2;
}

void makeArrByBaseRow() {
	for(int i = 7; i >= 0; --i)
		for(int j = 0; j<= i; ++j)
			arr[i][j] = arr[i + 1][j] + arr[i + 1][j + 1];
}

