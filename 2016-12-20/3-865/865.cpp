
//uva865
#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

map<char,char> m;

int main() {
    int t;
    char str[70], str1[70], str2[70];

    scanf("%d",&t);
    getchar();
    getchar();
    while (t--) {
        m.clear();

        gets(str1);
        gets(str2);
        cout << str2 << endl;
        cout << str1 << endl;
        for (int i = 0; i < strlen(str1) && i < strlen(str2); i++)
            m[str1[i]] = str2[i];

        while (gets(str) && strlen(str) != 0) {
            for (int i = 0; i < strlen(str); i++) {
                putchar(m[str[i]] == 0 ? str[i] : m[str[i]]);
            }
            putchar('\n');
        }
        if (t != 0) putchar('\n');
    }

    return 0;
}


