
//uva591
# include <stdio.h>
# define n_max 50

int main() {
	int n, h[n_max], sum, avg, move;
	int i, cnt = 1;
	while (scanf("%d", &n) && (n != 0)) {
		for (sum = 0, i = 0; i < n; sum += h[i++])
			scanf("%d", &h[i]);
		avg = sum / n;
		for (move = 0, i = 0; i < n; i++)
			if (h[i] > avg)
				move += h[i] - avg;
		printf("Set #%d\n", cnt++);
		printf("The minimum number of moves is %d.\n\n", move);
	}
	return 0;
}
