
//uva536
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char preord[30], inord[30];
int len;

void solve(int d, int k , int left, int right) {
	if (left > right || right < left || k >= len) return;

	if (left == right)
		printf("%c", inord[left]);
	else {
		int i;
		for (i = left; i < len; i++) {
			if (inord[i] == preord[k]) {
				solve(d + 1, k + 1, left, i - 1);
				solve(d + 1, k + (i - left) + 1, i + 1, right);
				printf("%c", inord[i]);
				break;
			}
		}
	}
}

int main() {
	while (scanf("%s %s", preord, inord) == 2) {
		len = strlen(preord);
		solve(0, 0, 0, len - 1);
		printf("\n");
	}

	return 0;
}
