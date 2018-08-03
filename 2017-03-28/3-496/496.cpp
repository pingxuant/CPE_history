
//uva496
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
    int s1[1000], s2[1000], n, m, match = 0;
    char c;
    while (scanf("%d%c", &s1[0], &c) == 2) {
        for (n = 1; c != '\n'; n++)
            scanf("%d%c", &s1[n], &c);
        c = 0;
        for (m = 0; c != '\n'; m++)
            scanf("%d%c", &s2[m], &c);
        sort(s1, s1 + n);
        sort(s2, s2 + m);
        match = 0;
        for (int i = 0, j = 0;i < n && j < m;) {
            if (s2[j] == s1[i]) {
                    match++;
                    i++;
                    j++;
                    continue;
            }
            if (s1[i] > s2[j])
                j++;
            else
                i++;
        }
        if (match == 0)
            cout << "A and B are disjoint\n";
        else if (match == n && match == m)
            cout << "A equals B\n";
        else if (match == n)
            cout << "A is a proper subset of B\n";
        else if (match == m)
            cout << "B is a proper subset of A\n";
        else
            cout << "I'm confused!\n";
    }
    return 0;
}

