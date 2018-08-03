
//uva11003
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 1005
#define MAX_W 3005

using namespace std;


struct Box {
	int weight;
	int capacity;
};

Box boxes[MAX_N];
int n, dp[MAX_N][MAX_W];
int recurse(int capacity, int i);

int main() {
	while (cin >> n) {
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> boxes[i].weight >> boxes[i].capacity;
		memset(dp, -1, sizeof(dp));
		int lmax = 1;
		for (int i = 0; i < n; i++) {
			lmax = max(recurse(boxes[i].capacity, i + 1) + 1, lmax);
		}
		cout << lmax << endl;
	}
}

int recurse(int capacity, int i) {
	if (i == n || !capacity)
		return 0;
	int &memo = dp[i][capacity];
	if (memo != -1)
		return memo;
	if (boxes[i].weight <= capacity)
		return memo = max(recurse(min(capacity - boxes[i].weight, boxes[i].capacity), i + 1) + 1,recurse(capacity, i + 1));
	else
		return memo = recurse(capacity, i + 1);
}