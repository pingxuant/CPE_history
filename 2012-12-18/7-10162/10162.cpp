
//uva10162
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// N = 100  1 å¾ªç°ïæ­¤åæ± N = 0 ~ 99 ç­æ¡ï¼¹æ N % 100 ³å¯æºçæ¡

int main() {
    string N;
    int ans[100], a, b, len, n;

    // æ± N = 0 ~ 99 ç­æ¡
    ans[0] = 0;
    for(int i = 1; i < 100; i++) {
        a = i % 10; // a = N % 10
        b = i % 10; // b = (N ^ j) % 10

        // è® b = (N ^ N) % 10
        for(int j = 2; j <= i; j++)
            b = (b * a) % 10;

        // ans[i] = (ans[i - 1] + (N ^ N)) % 10
        ans[i] = (b + ans[i - 1]) % 10;
    }

    while(cin >> N) {
		if(N == "0")
            break;

        // å¾ N % 100 çµ
        len = N.length();
        if(len > 1)
            n = (N[len - 2] - '0') * 10 + (N[len - 1] - '0');
        else
            n = N[0] - '0';

        // è¼¸åºæå¾ç­æ¡
        cout << ans[n] << endl;
    }

    return 0;
}
