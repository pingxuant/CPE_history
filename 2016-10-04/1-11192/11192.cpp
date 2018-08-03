
//uva11192
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int group_count;
	string q;

	while (cin >> group_count >> q && group_count > 0) {
		int group_size = q.size() / group_count;

		for (int i = 0; i < q.size(); i += group_size) {
			string segment = q.substr(i, group_size);
			cout << string(segment.rbegin(), segment.rend());
		}
		cout << endl;
	}
}
