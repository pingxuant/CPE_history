
//uva540
#include <cstdio>
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int team[1000005];
deque< deque<int> > dq;
deque< deque<int> >::iterator it;

int main(void) {
	int t, n, element, x, i, cas = 1;
	char cmd[10];

	while(scanf("%d", &t) && t) {
		memset(team, 0, sizeof(team));
		dq.clear();

		for(i = 1; i <= t; ++i) {
			scanf("%d", &n);
			while(n--) {
				scanf("%d", &element);
				team[element] = i;
			}
		}

		printf("Scenario #%d\n", cas++);
		while(scanf("%s", cmd) && strcmp(cmd, "STOP")!=0) {
			if(strcmp(cmd, "ENQUEUE") == 0) {
				scanf("%d", &x);

				for(it = dq.begin(); it != dq.end(); ++it) {
					if(team[it->front()] == team[x]) {
						it->push_back(x);
						break;
					}
				}
				if(it == dq.end()) {
					deque<int> tmp;
					tmp.push_back(x);
					dq.push_back(tmp);
				}
			}
			else if(strcmp(cmd, "DEQUEUE") == 0) {
				x = dq.front().front();
				if(dq.front().size() == 1) dq.pop_front();
				else dq.front().pop_front();
				printf("%d\n", x);
			}
		}
		printf("\n");
	}
	return 0;
}
