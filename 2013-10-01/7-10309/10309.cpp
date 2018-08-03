
//uva10309
#include "cstdio"
#include "cstdlib"
#include "cstring"

char grid[12][12];
char light[12][12];

void invert(int r, int c) {
	if(light[r][c] != '#')
		light[r][c] = '#';
	else
		light[r][c] = 'O';
}

void press_light(int r, int c) {
	invert(r-1, c);
	invert(r, c-1);
	invert(r, c);
	invert(r, c+1);
	invert(r+1, c);
}

int test(int pattern) {
	int presses = 0;

	memcpy(light, grid, sizeof(grid));	
	for(int c = 1; c <= 10; c++) {
		if(pattern & 1) {
			press_light(1, c);
			presses++;
		}
		pattern >>= 1;
	}

	for(int r = 2; r <= 10; r++) {
		for(int c = 1; c <= 10; c++) {
			if(light[r - 1][c] == 'O') {
				press_light(r, c);
				presses++;
			}
		}
	}

	for(int c = 1; c <= 10; c++)
		if(light[10][c] == 'O')
			return -1;

	return presses;
}

int main(void) {
	char name[1024];
	while(fgets(name, sizeof(name), stdin) && strcmp(name, "end\n")) {
		for(int r = 1; r <= 10; r++)
			fgets(&grid[r][1], 13, stdin);

		int answer = 0x7FFFFFFF;
		for(int p = 0; p < 1024; p++) {
			int result = test(p);
			if(result >= 0 && answer > result)
				answer = result;
		}			
		if(answer == 0x7FFFFFFF)
			answer = -1;

		for(int i = 0; name[i]; i++) {
			if(name[i] == '\n') {
				name[i] = 0;
				break;
			}
		}
		printf("%s %d\n", name, answer);
	}	

	return 0;
}

