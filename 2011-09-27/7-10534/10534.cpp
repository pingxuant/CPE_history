
//uva10534
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS(vector<int>& s, vector<int>& pos) {    // s ����Ӫ� sequence

	if (s.size() == 0) return 0;    // ���o���P�_�� special case

	vector<int> v;
	vector<int>::iterator p;

	pos.clear();
	v.push_back(s[0]);  // ����J�@�ӼƦr�A�K�o v.back() �X��
	pos.push_back(1);

	for (int i = 1; i < s.size(); ++i) {
		int n = s[i];

		if (n > v.back()) {
			v.push_back(n);
			pos.push_back(v.size());
		}
		else {
			p = lower_bound(v.begin(), v.end(), n);
			*p = n;
			pos.push_back(p - v.begin() + 1);
		}
	}

	return v.size();
}

int main() {
	int n, x;
	vector<int> in, rin, prefix, suffix;
	while(cin >> n) {
		in.clear();
		rin.clear();
		prefix.clear();
		suffix.clear();
		
		for(int i = 0; i < n; i++) {
			cin >> x;
			in.push_back(x);
		}
		vector<int>::reverse_iterator rit;
		for(rit = in.rbegin(); rit != in.rend(); rit++)
			rin.push_back(*rit);

		LIS(in, prefix);
		LIS(rin, suffix);

		vector<int>::iterator p;
		vector<int>::reverse_iterator q;
		int Max = 0;
		for(p = prefix.begin(), q = suffix.rbegin(); p != prefix.end(); p++, q++) {
			int tmp = min(*p, *q);
			if(tmp > Max)
				Max = tmp;
		}

		cout << Max * 2 - 1 << endl;

		/* show detail */
		/*cout << "  input: ";
		for(p = in.begin(); p != in.end(); p++)
			cout << *p << " ";
		cout << endl;

		cout << "  Along: ";
		for(p = prefix.begin(); p != prefix.end(); p++)
			cout << *p << " ";
		cout << endl;
		cout << "Reverse: ";
		for(q = suffix.rbegin(); q != suffix.rend(); q++)
			cout << *q << " ";
		cout << endl;*/
	}
	return 0;
}
