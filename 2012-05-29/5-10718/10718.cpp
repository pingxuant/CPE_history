
//uva10718
#include<stdio.h>

int main() {
	unsigned int N, L, U;
	while(scanf("%d%d%d",&N, &L, &U) == 3) {
		int i;
		unsigned int power, M = 0;
		
		for(i = 31; i >= 0; i--) {
			power = 1 << i;
			if(power > U) continue;
			if(N & power && power > L) continue;
			if(L < power) L = 0;
			else L -= power;
			U -= power;
			M |= power;
		}
		printf("%u\n", M);
	}
	return 0;
}
