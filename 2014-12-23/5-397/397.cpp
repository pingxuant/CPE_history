
//uva397
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool first(char c) {
	if (c == '*' || c == '/') return true;
	return false;
}


int main() {
	char var[10], check;
	int opd[25];
	bool opflag[25], nxt = false;
	char opn[25];
	int opcnt, i, j, cnt;
	while (scanf("%d", &opd[0]) != EOF) {
		if (nxt == true) printf("\n");
		cnt = opcnt = 0;
		memset(opflag, false, sizeof(opflag));
		while(1) {
			while (scanf("%c", &check) && check == ' ');
			if (check == '=') {
				scanf("%s",var);
				break;
			}
			else
				opn[opcnt] = check;
			
			scanf("%d", &opd[++opcnt]);
		}

		while (cnt != opcnt) {
			for (i = 0; i <= opcnt; i++) {
				if (opflag[i] == false) {
					printf("%d ", opd[i]);
					if (i != opcnt) printf("%c ", opn[i]);
				}
			}
			printf("= %s\n", var);
			
			for (i = 0; i < opcnt; i++) 
				if (opflag[i] == false && first(opn[i]) == true)
					break;

			if (i == opcnt)
				for (i = 0; i < opcnt; i++)
					if (opflag[i] == false)
						break;

			for (j = i + 1; ; j++)
				if (opflag[j] == false)
					break;

			opflag[i] = true;

			if (opn[i] == '*')
				opd[j] = opd[i] * opd[j];
			else if (opn[i] == '/')
				opd[j] = opd[i] / opd[j];
			else if (opn[i] == '+')
				opd[j] = opd[i] + opd[j];
			else if (opn[i] == '-')
				opd[j] = opd[i] - opd[j];
			cnt++;
		}

		printf("%d = %s\n", opd[j], var);
		nxt = true;
	}
	return 0;
}
