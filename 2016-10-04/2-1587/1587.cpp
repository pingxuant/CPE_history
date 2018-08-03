
//uva1587
#include <stdio.h>

struct pallet {
	int w, h;
} box[6];

int n = 6;
int result = 0;

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int n) {
	int min;

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++){
			if (box[j].w < box[min].w)
				min = j;
		}

		swap(&box[i].w, &box[min].w);
		swap(&box[i].h, &box[min].h);
	}

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++){
			if (box[j].h < box[min].h)
				min = j;			
		}
		if (box[min].w <= box[i].w) {
			swap(&box[i].w, &box[min].w);
			swap(&box[i].h, &box[min].h);
		}
	}
}

int compare() {
	if (box[0].w == box[1].w && box[0].h == box[1].h && box[2].w == box[3].w && 
	    box[2].h == box[3].h && box[4].w == box[5].w && box[4].h == box[5].h) {
			
		if (box[0].w == box[2].w && box[0].h == box[4].w && box[2].h == box[4].h)
			result = 1;
		else 
			result = 0;	
	}
	else 
		result = 0;

	return result;
}

int main() {

	while (~scanf("%i %i", &box[0].w, &box[0].h)) {
		if (box[0].w > box[0].h)
			swap(&box[0].w, &box[0].h);

		for (int i = 1; i < 6; i++) {
			scanf("%i %i", &box[i].w, &box[i].h);
			if (box[i].w > box[i].h)
				swap(&box[i].w, &box[i].h);
		}

		sort(n);

		result = compare();
		if (result == 0)
			printf("IMPOSSIBLE\n");
		else 
			printf("POSSIBLE\n");
	}

	return 0;
}
