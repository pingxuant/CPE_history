
//uva272
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int flag = 1;
	char ch;

	while(scanf("%c", &ch) != EOF) {
		if(ch == '"') {
			if(flag)
				cout << "``";
			else
				cout << "''";
			flag = 1 - flag;
		}
		else
			cout << ch;
	}
	return 0;
}
