
//uva10922
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	char str[1005];
	int i, sum, deg;
	while (gets(str) && strcmp(str,"0")) {
		printf("%s",str);
		for (sum = i = 0; str[i]; i++)
			sum += str[i]-'0';
		
		if (sum % 9 != 0)
			printf(" is not a multiple of 9.\n");
		else {
			deg = 1;
			while (sum >= 10) {
				sprintf(str, "%d", sum);
				sum = 0;
				for (i = 0; i < str[i]; i++)
					sum += str[i]-'0';
				deg++;
			}
			printf(" is a multiple of 9 and has 9-degree %d.\n", deg);
		}
	}
	return 0;
}
