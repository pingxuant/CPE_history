
//uva10905
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string str;

bool my(string a, string b) {
	return (a + b) < (b + a);
}

int main() {
	while(true) {
	    cin >> n;
        if(n == 0 || n>50)
            break;
		vector<string> t;

		while(n--){
			cin >> str;
			t.push_back(str);
		}
		sort(t.begin(),t.end(),my);
		for(n = t.size() - 1; n >= 0; n--)
			printf("%s",t[n].c_str());
		putchar('\n');
	}
	return 0;
}
