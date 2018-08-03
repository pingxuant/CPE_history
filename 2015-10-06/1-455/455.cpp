
//uva455
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str[85];

int solve() {
	int i, j, len = strlen(str);
	for(i = 1; i <= len; i++) { // length
		if(len % i != 0) continue;
		for(j = 0; j < len; j++)
			if(str[j] != str[j % i])
				break;
		if(j == len)
			return i;
	}
	return -1;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s", str);
		printf("%d\n", solve());
		if(t != 0)
			putchar('\n');
	}
	return 0;
}
