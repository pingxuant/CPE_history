
//uva10700
#include <iostream>
#include <sstream>
#include <cstdlib> // Just for exit()
using namespace std;

// Note the case of 20*20*20*20*20*20*20*20*20*20*20*20=4096*10^12.
typedef long long int lint;

const int MX_BUF = (1 + 2) * 12; // (sizeof(op)+strlen("20"))*12

lint max(istream &is) {
	lint major = 1,minor;
	is >> minor;
	char op;
	while (is >> op) {
		if (op=='+') {
			int num;
			is >> num;
			minor += num;
		}
		else if (op == '*') {
			major *= minor;
			is >> minor;
		}
		else
			exit(1);
	}
	return major * minor;
}

lint min(istream &is) {
	lint major = 0,minor;
	is >> minor;
	char op;
	while (is >> op) {
		if (op == '*') {
			int num;
			is >> num;
			minor *= num;
		}
		else if (op == '+') {
			major += minor;
			is >> minor;
		}
		else
			exit(1);
	}
	return major + minor;
}

int main() {
	int n;
	cin >> n;
	cin.get(); // To eliminate '\n'
	while (n--) {
		char buf[MX_BUF];
		cin.getline(buf, MX_BUF);
		
		istringstream iss1(buf), iss2(buf); // `iss.seekg(0)' dosen't work.
		cout << "The maximum and minimum are " << max(iss1);
		cout << " and " << min(iss2) << "." << endl;
	}
	return 0;
}

