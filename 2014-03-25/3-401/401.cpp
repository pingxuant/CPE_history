
//uva401
#include<stdio.h>
#include<iostream>
#include<map>
 
using namespace std;

 
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
 
int main() {
    string line;
    bool m = true;
    bool p = true;
    map<char, char> map;
    for(int i = 0; i < s.length(); i++)
        map[s[i]] = r[i];
    while(cin >> line)  {
        m = true;
        
        for(int i = 0; i < line.length() / 2 + line.length() % 2; i++)
            if(line[line.length() - i - 1] != map[line[i]])
                m = false;
        p = true;
        for(int i = 0; i < line.length() / 2; i++)
            if(line[line.length() - i - 1] != line[i])
                p = false;
            
        if(!m && !p)
            cout << line << " -- is not a palindrome.\n";
        else if(!m && p)
            cout << line << " -- is a regular palindrome.\n";
        else if(m && !p)
            cout << line << " -- is a mirrored string.\n";
        else
            cout << line << " -- is a mirrored palindrome.\n";
        
        cout << endl;
    }
	return 0;
}
