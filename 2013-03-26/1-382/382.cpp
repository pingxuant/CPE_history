
//uva382
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
   int num, ans;

    cout << "PERFECTION OUTPUT" << endl;

    while(cin >> num) {  // read input
        if(num == 0)    // 0 for end program
            break;

        ans = 1;
		for(int i = 2; i <= sqrt(num); i++) { // start checking
            if(num % i == 0) {   // æª¢æ¥æ¯å¦çºå
                ans = ans + i + (num / i);  // add to answer
				
                if(i == sqrt(num))  // »æè¤ ex:9=3+3
                    ans -= i;
            }
        }

        printf("%5d  ", num);   // output number

        // output answer
        if(ans < num || num == 1)   // 1 for special case
            cout << "DEFICIENT" << endl;
        else if(ans == num)
            cout << "PERFECT" << endl;
        else
            cout << "ABUNDANT" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
