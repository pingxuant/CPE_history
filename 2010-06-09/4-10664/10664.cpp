
//uva10664
#include <stdio.h>
#include <string.h>
int dp[4002];
int main(void){
    int TC, l[21], sz, a, sum, i, j;
    char c;
    scanf("%d", &TC);
    while(TC--){
        sz = sum = 0;
        while(scanf("%d%c",&l[sz],&c)==2){
            sum = sum + l[sz];
            sz++;
            if(c=='\n')
                break;
        }
        if(sum%2){
            printf("NO\n");
            continue;
        }
        else{
            sum = sum / 2;
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for(i = 0; i < sz; i++){
                for(j = sum - l[i]; j >= 0; j--)
                    if(dp[j] && !dp[j + l[i]])
                        dp[j + l[i]]=1;
            }
            if(dp[sum])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
