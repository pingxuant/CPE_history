
//uva105
#include <iostream>
#include <sstream>
#include <string>
#define MAX 10000

using namespace std;

int main() {
	int l, h, r, build[MAX + 1];
	stringstream intToString;
	string ans;
	
	// initialize
	for(int i = 0; i <= MAX; i++)
		build[i] = 0;
	
	// get input
	while(cin >> l >> h >> r) {
		// mark the high value in each x-axis
		for(int i = l; i < r; i++) {
			if(build[i] < h)
				build[i] = h;
		}
	}
	
	// save the answer
	if(build[0] != 0)
		intToString << 0 << ' ' << build[0] << ' ';
	for(int i = 1; i <= MAX; i++) {
		if(build[i] != build[i - 1])
			intToString << i << ' ' << build[i] << ' ';
	}
	
	// output the answer
	getline(intToString, ans);
	ans.erase(ans.length() - 1);
	cout << ans << endl;
	
	return 0;
}
