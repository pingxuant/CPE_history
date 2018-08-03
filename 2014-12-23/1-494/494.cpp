
//uva494
#include <stdio.h>

int main () {
	char In, M, N, Cou;

	while (scanf("%c", &In) == 1) {
		M = 0; Cou = 0;
		while (In != '\n') {
			if ((65 <= In && In <= 90) || (97 <= In && In <= 122)) N = 1;
			else N = 0;
			
			if (M == 0 && N == 1) Cou++;
			M = N;

			scanf("%c", &In);
		}
		printf("%d\n", Cou);
	}
	return 0;
}

