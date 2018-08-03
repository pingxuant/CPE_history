
//uva630
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    int i, t, n, num;
    char word[1005][25], temp1[1005][25], test[25], temp2[25];

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        for(i = 0; i < n; ++i) {
            scanf("%s", word[i]);
            strcpy(temp1[i], word[i]);
            sort(&temp1[i][0], &temp1[i][0] + strlen(temp1[i]));
        }

        while(scanf("%s", test) && test[0] != 'E') {
            printf("Anagrams for: %s\n", test);
            strcpy(temp2, test);
            sort(&temp2[0], &temp2[0] + strlen(temp2));
            for(i = 0, num = 0; i < n; ++i)
                if(strcmp(temp2, temp1[i]) == 0)
					printf("%3d) %s\n", ++num, word[i]);
            if(num == 0) printf("No anagrams for: %s\n", test);
        }
		
        if(t) printf("\n");
    }
    return 0;
}
