
//uva1208
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct _enode
{
    int point1;
    int point2;
    int weight;
}enode;
enode E[10001];

//union_set
int sets[101];
int RANK[101];

void set_inital(int a, int b)
{
    for ( int i = a; i <= b; i++) {
        RANK[i] = 0;
        sets[i] = i;
    }
}

int  set_find(int a)
{
    if (a != sets[a])
        sets[a] = set_find(sets[a]);
    return sets[a];
}

void set_union(int a, int b)
{
    if (RANK[a] < RANK[b])
        sets[a] = b;
    else {
        if (RANK[a] == RANK[b])
            RANK[a]++;
        sets[b] = a;
    }
}
//end_union_set

int cmp_e(enode a, enode b)
{
    if (a.weight == b.weight) {
        if (a.point1 == b.point1)
            return a.point2 < b.point2;
        else return a.point1 < b.point1;
    }else return a.weight < b.weight;
}

void kruskal(int n, int m)
{
    sort(E, E + m, cmp_e);
    set_inital(0, n);
    for (int i = 0; i < m; i++) {
        int A = set_find(E[i].point1);
        int B = set_find(E[i].point2);
        if (A != B) {
            set_union(A, B);
            printf("%c-%c %d\n",E[i].point1 + 'A',E[i].point2 + 'A',E[i].weight);
        }
    }
}

int main()
{
    int t, n, a, c;
    while (~scanf("%d", &t))
    for (int k = 1; k <= t; k++) {
        scanf("%d", &n);
        int e_count = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d%c", &a, &c);
            E[e_count].point1 = i < j ? i : j;
            E[e_count].point2 = j > i ? j : i;
            E[e_count].weight = a;
            if (a) e_count++;
        }

        printf("Case %d:\n",k);
        kruskal(n, e_count);
    }

    return 0;
}
