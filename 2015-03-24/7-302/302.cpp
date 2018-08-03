
//uva302
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
#define SIZE 50
#define BIG 2000

using namespace std;

struct road{
	int cnt, good;
	road(int num = 0, int v = 0) : cnt(num), good(v) {}
	bool operator < (const road & e) const {
		return cnt >= e.cnt;
	}
};

int cari[BIG];
priority_queue<road> g[SIZE];

list<int> bvc(int x) {
	list<int> rail, form;
	while (!g[x].empty()) {
		road aux = g[x].top();
		g[x].pop();
		if (cari[aux.cnt])
			continue;
		cari[aux.cnt] = 1;
		form = bvc(aux.good);
		rail.splice(rail.begin(), form);
		rail.push_front(aux.cnt);
	}
	return rail;
}

int main() {
	int a, b, c, dig, go = 0, map[SIZE];
	bool check;
	while (cin >> a >> b) {
		if (a == 0 || b == 0)
			break;
		dig = 0;
		memset(map, 0, sizeof(map));
		memset(cari, 0, sizeof(cari));
		cin >> c;
		for (int i = 0; i < SIZE; i++)
			while (!g[i].empty())
				g[i].pop();
			
		road e1(c, b);
		g[a].push(e1);
		road e2(c, a);
		g[b].push(e2);
		map[a]++; map[b]++;
		dig = max(dig, max(a, b));
		go = min(a, b);
		while (cin >> a >> b) {
			if (a == 0 || b == 0)
				break;
			cin >> c;
			road e3(c, b);
			road e4(c, a);
			g[b].push(e4);
			g[a].push(e3);
			map[a]++; map[b]++;
			dig = max(dig, max(a, b));
		}
		check = true;
		for (int i = 0; i <= dig; i++)
			if (map[i] & 1)
				check = false;
		if (check == false) {
			cout << "Round trip does not exist." << endl;
			cout << endl;
		}
		else {
			list<int> tail = bvc(go);
			for (list<int>::iterator it = tail.begin(); it != tail.end(); it++){
				if (it != tail.begin())
					cout << " ";
				cout << *it;
			}
			puts("\n");
		}
	}
	return 0;
}