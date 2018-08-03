
//uva1585
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int T, score, cnt, i;
	char str[100];

	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		score = cnt = 0;
		for(i = 0; i < strlen(str); ++i) {
			if(str[i] == 'O')
				++cnt;
			else
				cnt = 0;

			score += cnt;
		}
		printf("%d\n", score);
	}
	return 0;
}
