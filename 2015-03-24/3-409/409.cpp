
//uva409
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<cstdio>
#define DEFAULT 10000

using namespace::std;

int main() {
	long m, n, cnt, feq[DEFAULT], time = 1;
	string point, p, fun[DEFAULT];
	char word, exc[DEFAULT], good[DEFAULT];
	int maximum, x, y, z;
	while (cin >> m >> n) {
		cout << "Excuse Set #" << time << endl;
		for (int i = 0; i < n; i++)
			fun[i] = "";
		
		map<string, bool> MAP;
		for (int i = 1; i <= m; i++) {
			cin >> point;
			MAP[point] = true;
		}
		maximum = x = cnt = 0;
		y = z = -1;
		getchar();
		
		while (scanf("%c", &word) == 1) {
			good[++z] = word;
			word = tolower(word);
			if (isalpha(word))
				exc[++y] = word;
			else if (word != '\n') {
				exc[y + 1] = '\0';
				p = exc;
				if (MAP[p])
					cnt++;
				y = -1;
			}
			else {
				exc[y + 1] = '\0';
				if (strlen(exc) != 0) {
					p = exc;
					if (MAP[p])
						cnt++;
				}
				feq[x] = cnt;
				if (cnt > maximum)
					maximum = cnt;
				good[z + 1] = '\0';
				fun[x++] = good;
				y = z = -1;
				cnt = 0;
				if (x == n)
					break;
			}
		}
		for (int j = 0; j < x; j++)
			if (maximum == feq[j])
				cout << fun[j];
		cout << endl;
		time++;
	}
	return 0;
}