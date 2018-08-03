
//uva514
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

int main(void){
    int n, i, j, a[1001], prt = 0;
    while(scanf("%d", &n) && n){
        while(scanf("%d", &a[0]) && a[0]){
            if(a[0] == 0)
                continue;
            for(i = 1; i < n; i++)
                scanf("%d", &a[i]);
            j = 0;
            stack<int> S;
            for(i = 1; i <= n; i++){
                if(a[j] == i)
                    j++;
                else if( !S.empty() && S.top() == a[j]) {
                        j++;
                        S.pop();
                }
                else
                    S.push(i);

                while(!S.empty() && S.top() == a[j]){
                    j++;
                    S.pop();
                }
            }

            if(S.empty() && j == n)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
