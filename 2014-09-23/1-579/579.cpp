
//uva579
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int h, m;
    double ah, am, ans; // angle of hour and min
    while (scanf("%d:%d", &h, &m) && (h | m)) {
        if (h == 12) h = 0;
        ah = h * 30 + 30 * m * 1.0 / 60;
        am = m * 6;
        ans = ah - am;
        while (ans < 0) ans += 360;
        if (ans > 180) ans = 360 - ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}
