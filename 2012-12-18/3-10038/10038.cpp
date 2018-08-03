
//uva10038
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	bool isJolly;
	int dataNum, *data;
	vector<int> minus;

	while(cin >> dataNum) {	// ç´åº·åº¦
		// å§
		data = new int [dataNum];
		minus.clear();
		isJolly = true;

		// ç´´æ¸å
		for(int d = 0; d < dataNum; d++)
			cin >> data[d];

		// è¨ç®¸é°ä¸äå·®å
		for(int i = 1; i < dataNum; i++)
			minus.push_back(abs(data[i] - data[i - 1]));

		// åº
		sort(minus.begin(), minus.end());

		// ¤æ·æ¯å¦ç Jolly jumper
		for(int i = 0; i < minus.size() && isJolly; i++)
			if(minus[i] != i + 1)
				isJolly = false;

		// è¼¸åºå¤æ·ç
		if(isJolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

		// ¾è¶é
		delete [] data;
	}

	return 0;
}