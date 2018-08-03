
//uva245
#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
#include <string>
#include <iterator>

using namespace std;

list<string> dict;

int main() {

	char buffer[51];
	while(buffer[0] = cin.get()) {
		if(buffer[0] == '0')break; // END
		if(isdigit(buffer[0])) {
			cin.putback(buffer[0]);
			int num;
			cin >> num;
			
			std::list<string>::iterator it = dict.begin();
			advance(it,num-1);
			cout << *it ;
			
			dict.push_front(*it);
			dict.erase(it);
			continue;
		}	
		if(!isalpha(buffer[0])) { // non-Alpha
			cout << buffer[0]; 
			continue;
		}	
		int i = 1;
		for(; isalpha(cin.peek()); ++i) {
			cin.get(buffer[i]);
		}
		buffer[i] = '\0';
		cout << buffer;
		dict.push_front(buffer);
	}
	
	return 0;
}



