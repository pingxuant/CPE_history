
//uva10684
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int arr[10001];
	int n, i, sum, Max;

	while(cin >> n && n) {
		for(i = 0; i < n; i++)
			cin >> arr[i];

		for(i = 0, sum = 0, Max = -1; i < n; i++) {
			sum += arr[i];
			if(sum < 0)
				sum = 0;
			else if(sum > Max)
				Max = sum;
		}

		if(Max > 0)
			printf("The maximum winning streak is %d.\n", Max);
		else
			printf("Losing streak.\n");
	}
	return 0;
}
