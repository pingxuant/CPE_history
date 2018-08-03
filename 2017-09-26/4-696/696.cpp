
//uva696
#include <iostream>

using namespace std;

int solve(int m, int n){

	if (m > n)
	    swap(m, n);

	if (m == 1) //special case
		return n;
	else if (m == 2) //special case
	    return 4 * (n / 4) + ( (n % 4 <= 2) ? 2 * (n % 4): 4);
	else  //normal case
	    return (m * n + 1) / 2;

}

int main(){

	int m, n;

	while (true){

		cin >> m >> n;
		if (m == 0 || n == 0)
		    break;
		int res = solve(m, n);
		cout << res << " knights may be placed on a " << m << " row "
		<< n << " column board." << endl;
	}

	return 0;
}
