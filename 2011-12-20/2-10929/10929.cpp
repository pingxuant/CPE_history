
//uva10929
#include <stdio.h>
#include <string.h>

int main() {
	char str[1005];
	int one, two, len, i, d;

	while(scanf("%s", str) != EOF) {
		len = strlen(str);
		if(len == 1 && str[0] == '0')
			break;

		one = two = 0;
		for(i = 0; i < len; i+=2)
			one += (int)(str[i] - '0');
		for(i = 1; i < len; i+=2)
			two += (int)(str[i] - '0');

		if(one > two)
			d = one - two;
		else
			d = two - one;

		if(d % 11 == 0)
			printf("%s is a multiple of 11.\n", str);
		else
			printf("%s is not a multiple of 11.\n", str);
	}
	return 0;
}
