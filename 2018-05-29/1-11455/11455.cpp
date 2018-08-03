
//uva11455
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
    int TC, edge[4], i, quad;
    scanf("%d", &TC);
    while(TC--) {
        for(i = 0; i < 4; i++)
            scanf("%d", edge + i);
        sort(edge, edge + 4);

        if(edge[0] == edge[1] && edge[1] == edge[2] && edge[2] == edge[3])
            printf("square\n");
        else if(edge[0] == edge[1] && edge[2]==edge[3])
            printf("rectangle\n");
        else if(edge[0] + edge[1] + edge[2] > edge[3])
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
    return 0;
}
