
//uva12654
#include <iostream>
#include <cstdio>
#include <algorithm>

#define CostMax 2000000000

using namespace std;

int Arr[1005]; 
int Cost[1005]; 

void cover(int i, int t)  {
    int j;
    int cover = Arr[i] + t; // Next Cover if use this patch
    for(j = i + 1; Arr[j] <= cover; ++j);
    if(Cost[j] > Cost[i] + t)
        Cost[j] = Cost[i] + t;
}
 
void Output(int n) {
	for(int i = 0; i < n; ++i)
		printf("%4d", Arr[i]);
	cout << endl;
}

int main()  {
    int n, c, t1, t2;
    while(cin >> n >> c >> t1 >> t2) {
        for(int i = 0; i < n; ++i)
            cin >> Arr[i];

		int Ans = 2000000;
		for(int k = 0; k < n; ++k) {
			// init
			for(int i = 0; i <= n; ++i)
				Cost[i] = CostMax;
			Cost[0] = 0;
 
			// make a wall
			Arr[n] = 2000000;

			for(int i = 0; i < n; ++i) {
				// each one try to use two patch.
				if(Cost[i] != CostMax) {
					cover(i, t1);
					cover(i, t2);
				}
			}

			if(Cost[n] < Ans)
				Ans = Cost[n];
			Arr[0] += c;
			sort(Arr, Arr + n);
		}
		
		cout << Ans << endl;
    }
    return 0; 
} 