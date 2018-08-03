
//uva1632
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>

int a[10010],  b[10010],  d[10010][10010][2];

int main(void) {
	int i, j, k, n, cur, minv;
	while(scanf("%d", &n) == 1) {
		for(i = 1; i <= n; i++)
			scanf("%d%d", &a[i], &b[i]);
		
		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				d[i][j][0] = d[i][j][1] = (1 << 30);				
		for(i = 1; i <= n; i++)
			d[i][i][0] = d[i][i][1] = 0;			
		for(i = n; i > 0; i--) {
			for(j = i + 1; j <= n; j++) {
				d[i][j][0] = std::min(d[i + 1][j][0] + a[i + 1] - a[i], d[i + 1][j][1] + a[j] - a[i]);
				if(d[i][j][0] >= b[i])
					d[i][j][0] = (1 << 30);
				d[i][j][1] = std::min(d[i][j - 1][0] + a[j] - a[i], d[i][j - 1][1] + a[j] - a[j - 1]);
				if(d[i][j][1] >= b[j])
					d[i][j][1] = (1 << 30);					
			}
		}
		minv = std::min(d[1][n][0], d[1][n][1]);
		if(minv == (1 << 30))
			printf("No solution\n");
		else
			printf("%d\n", minv);
	}
	return 0;
}
