
//uva337
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
	int n, cases = 0;
	while(scanf("%d", &n) == 1 && n) {
		char g[10][10];
		while(getchar() != '\n');
		memset(g, ' ', sizeof(g));
		int px = 0, py = 0;
		bool insertmode = false;
		string cmd, cmds = "";
		while(n--) {
			getline(cin, cmd);
			cmds += cmd;
		}
		int i, j;
		for(i = 0; i < cmds.length(); i++) {
			if(cmds[i] == '^') {
				i++;
				if(cmds[i] == 'b') {
					py = 0;
				}
				else if(cmds[i] == 'c') {
					memset(g, ' ', sizeof(g));
				}
				else if(cmds[i] == 'd') {
					px++;
					if(px >= 10)
						px = 9;
				}
				else if(cmds[i] == 'e') {
					for(j = py; j < 10; j++)
						g[px][j] = ' ';
				}
				else if(cmds[i] == 'h') {
					px = 0, py = 0;
				}
				else if(cmds[i] == 'i') {
					insertmode = true;
				}
				else if(cmds[i] == 'l') {
					if(py > 0)
						py--;
				}
				else if(cmds[i] == 'o') {
					insertmode = false;
				}
				else if(cmds[i] == 'r') {
					py++;
					if(py >= 10)
						py = 9;
				}
				else if(cmds[i] == 'u') {
					if(px > 0)
						px--;
				}
				else if(cmds[i] == '^') {
					goto printss;
				}
				else {
					px = cmds[i] - '0';
					i++;
					py = cmds[i] - '0';
				}

			}
			else {
				printss:
				if(insertmode) {
					for(j = 8; j >= py; j--)
						g[px][j + 1] = g[px][j];
					g[px][py] = cmds[i];
				}
				else
					g[px][py] = cmds[i];
				py++;
				if(py >= 10)
					py = 9;
			}
		}
		
		printf("Case %d\n", ++cases);
		puts("+----------+");
		for(int i = 0; i < 10; i++, puts("|")) {
			putchar('|');
			for(int j = 0; j < 10; j++)
				putchar(g[i][j]);
		}
		puts("+----------+");

	}
	return 0;
}
