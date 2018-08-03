
//uva748
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 150

char *reverse(char *s1) {
	int i, count = 0;
	char *result = strdup(s1);
	for (i = (int)strlen(s1) - 1; i >= 0; i--) {
		result[count] = s1[i];
		count++;
	}
	result[count] = '\0';
	return result;
}

char *multiplication(char *m1, char *m2) {
	char *s1 = reverse(m1);
	char *s2 = reverse(m2);
	int length1 = (int) strlen(m1);
	int length2 = (int) strlen(m2);
	int result_length = 0;
	int i, j;
	int d1, d2, mul, overflow = 0, sum = 0;
	char *result = (char *) malloc (sizeof(char) * (length1 + length2 + 2));
	char *returned;
	
	for (i = 0; i < length1 + length2; i++)
		result[i] = '0';
	result[length1 + length2] = '\0';
	result_length = (int) strlen(result);
	
	for (i = 0; s1[i] != '\0'; i++) {
		overflow = 0;
		for (j = 0; s2[j] != '\0'; j++) {
			d1 = s1[i] - '0';
			d2 = s2[j] - '0';
			mul = d1 * d2;
			
			sum = overflow + mul + (result[i + j] - '0');
			result[i + j] = (sum % 10) + '0';
			overflow = sum / 10;
		}
		if (overflow > 0) {
			result[i + j] = (overflow % 10) + '0';
			if (i + j >= result_length) {
				result_length++;
				result[result_length] = '\0';
			}
		}
		if (overflow > 10) {
			result[i + j + 1] = (overflow / 10) + '0';
			if (i + j + 1 >= result_length) {
				result_length++;
				result[result_length] = '\0';
			}
		}
	}
	free(s1);
	free(s2);
	
	returned = reverse(result);
	free(result);
	
	return returned;
}
char *trimchar(char *str, char c) {
	char *end;
	
	while(*str == c)
		str++;
	
	if(*str == 0)
		return str;
	
	end = str + strlen(str) - 1;
	while(end > str && *end == c)
		end--;
	
	*(end + 1) = 0;
	
	return str;
}

/*Given R and n, compute the result of R^n in string type*/
char *Exponentiation(double R, int n) {
	char RString[SIZE], *decimalString;
	char uintString[SIZE];
	char *temp, *result, multiplicand[SIZE];
	char returned[SIZE] = {0};
	int digitCount = 0;
	int i, count = 0;
	int flag = 0;
	
	sprintf(RString, "%lf", R);		/*print R to a string*/
	decimalString = trimchar(RString, '0');  /*trim the zero character*/
	
	/*Compute the count of decimal digits for the fraction part.*/
	for (i = 0; decimalString[i] != '\0'; i++) {
		if (decimalString[i] == '.')
			flag = 1;   /*When the decimal point is encuontered*/
		else {
			if (flag == 1)
				digitCount++;
			uintString[count++] = decimalString[i];
		}
	}
	uintString[count] = '\0';
	
	strcpy(multiplicand, uintString);
	for (i = 1; i < n; i++) {
		temp = multiplication(multiplicand, uintString);
		strcpy(multiplicand, temp);
		free(temp);
	}
	result = multiplicand;
	
	strncpy(returned, result, strlen(result) - digitCount * n);
	if (digitCount > 0) {
		strcat(returned, ".");
		strcat(returned, result + (strlen(result) - digitCount * n));
	}
	return strdup(trimchar(returned, '0'));
}

int main(void) {
	double R;
	int n;
	char *result;
	
	while (fscanf(stdin, "%lf%d", &R, &n) != EOF) {
		result = Exponentiation(R, n);
		printf("%s\n", result);
		free(result);
	}
	return 0;
}
