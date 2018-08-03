
//uva11401
#include<iostream> 

using namespace std;

const int N = 1000000 + 10;
long long a[N];

int main() {
	
    a[3] = 0;
    for(long long i = 4; i < N; i++) {
    	a[i] = a[i - 1] + ((i - 1) * (i - 2) / 2 - (i - 1 - i / 2)) / 2;
    }
    int n;
    while(cin >> n) {
	if(n < 3) break;
    	cout << a[n] << endl;
    }
		
	return 0;
}
