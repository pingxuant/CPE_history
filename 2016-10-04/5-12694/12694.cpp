
//uva12694
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> A, pair<int,int> B) {
	return (A.second == B.second) ? (A.first < B.first) : (A.second < B.second);
}

int main(void) {
	vector<pair<int,int>> meeting;
	int T, T_S, T_E, count, start;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++) {
		count = 0;
		start = 0;

		meeting.clear();

		while(scanf("%d %d", &T_S, &T_E) && T_S + T_E) {
			meeting.push_back(make_pair(T_S, T_E));
		}
		sort(meeting.begin(), meeting.end(), cmp);

		for(int j = 0; j < meeting.size(); j++)
		{
			if(start <= meeting[j].first)
			{
				count++;
				start = meeting[j].second;
			}
		}
		printf("%d\n", count);
	}
}
