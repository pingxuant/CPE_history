
//uva240
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct symbol{
	int l;  // alphabet level
	int f;  // frequency
	int fa; // father
	int leaf; // -1 = not leaf, 0..1..2....n-1 means from left to right
	bool iss; // is symbol?
	bool exist; // can be merged?
	symbol(int _l = 0, int _f = 0, int _fa = 0, int _leaf = -1, bool _iss = true, bool _exist = true):\
	 l(_l), f(_f), fa(_fa), leaf(_leaf), iss(_iss), exist(_exist) {}
}v[100];

int R, N, num, vsize, tcnt = 0;
int lans[26];
char pans[26][26];

void huffman() {
	int i, j, del = 0;
	while(num != 1) {

		int pick[10];
		for(i = 0; i < R; i++) {
			for(j = 0; j < vsize && v[j].exist == false; j++);

			int cur = j;
			for(j = cur+1; j < vsize; j++) {
				if(v[j].exist == false) continue;
				if(v[j].f < v[cur].f ||(v[j].f == v[cur].f && v[j].l < v[cur].l)) {
					cur = j;
				}
			}
			pick[i] = cur;
			v[cur].exist = false;
		}

		int tmpl = 27, tmpf = 0; // 27 is greater than 26
		for(i = 0; i < R; i++) {
			tmpf += v[pick[i]].f;
			tmpl = min(tmpl, v[pick[i]].l);
			v[pick[i]].fa = vsize;
			v[pick[i]].leaf = i;
		}
		v[vsize] = symbol(tmpl, tmpf, -1, -1, false, true);
		del += R;
		num -=(R - 1);
		vsize++;
	}

	double totlen = 0, totfreq = 0;
	memset(lans, 0, sizeof(lans));
	for(i = 0; i < vsize; i++) {
		if(v[i].iss == true) {
			int cur = i;
			while(v[cur].fa != -1) {
				pans[v[i].l][lans[v[i].l]] = '0' + v[cur].leaf;
				lans[v[i].l]++;
				cur = v[cur].fa;
			}
			totfreq += v[i].f;
			totlen += lans[v[i].l] * v[i].f;
		}
	}

	totlen /= totfreq;

	printf("Set %d; average length %.2lf\n", ++tcnt, totlen);
	for(i = 0; i < N; i++) {
		printf("    %c: ",'A'+i);
		for(j = lans[i]-1; j >= 0; j --) {
			printf("%c",pans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	int i, f;
	while(scanf("%d",&R) && R) {
		scanf("%d", &N);
		for(i = 0; i * (R - 1) + R < N; i++);
		num = i * (R - 1) + R;
		if(num != N) {
			num = num - N;
			for(i = 0; i < num; i++) {
				v[i] = symbol(26, 0, -1, -1, false, true);
			}
		}
		else
			num = 0;

		for(i = 0; i < N; i++, num++) {
			scanf("%d", &f);
			v[num] = symbol(i, f, -1, -1, true, true);
		}
		vsize = num;
		huffman();
	}
	return 0;
}
