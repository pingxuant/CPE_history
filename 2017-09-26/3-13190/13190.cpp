
//uva13190
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class data{
public:
	int priority;
	string name;
	int frequency;
	int moment;

	data (int pr, string na, int fr, int mo){
		priority = pr;
		name = na;
		frequency = fr;
		moment = mo;
	}

};

bool operator<(const data& d1, const data& d2){
	bool cmp_monent = d1.moment > d2.moment;
	bool cmo_priority = d1.priority > d2.priority;
	if (d1.moment == d2.moment)
		return cmo_priority;
	else
		return cmp_monent;
}

int main(){

	int t, n, k, frequency;
	string name;
	ostringstream s;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		priority_queue<data> pq;

		for (int priority = 0; priority < n; priority++) {
			cin >> name >> frequency;
			int monent = frequency;
			pq.push(data(priority, name, frequency, monent));
		}

		for (int j = 0; j < k; j++) {
			data d = pq.top(); pq.pop();
			s << d.moment << " " << d.name << endl;
			pq.push(data(d.priority, d.name,
			        d.frequency, d.moment + d.frequency));
		}
	}
	cout << s.str();
	return 0;
}
