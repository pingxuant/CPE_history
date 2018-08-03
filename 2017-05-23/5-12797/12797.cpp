
//uva12797
/// brute-force + bfs
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#define INF (1<<30)

using namespace std;

char m[105][105];
bool vis[105][105];
bool p[256]; /// permission
int N, ans;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

class Pos{
public:
    int x, y, c;
    Pos() {}
    Pos(int _x, int _y, int _c = 1): x(_x), y(_y), c(_c) {}
    bool legal() { return (x >= 1 && x <= N && y >= 1 && y <= N && p[m[x][y]] == true && vis[x][y] == false); }
};

bool finish(Pos cur) {
    return (cur.x == N && cur.y == N);
}

void bfs() {
    if (p[m[1][1]] == false || p[m[N][N]] == false) /// no permission in begin or end.
        return;

    queue<Pos> myq;
    while(!myq.empty()) 
		myq.pop();
    Pos cur, nxt, goal;
    memset(vis, false, sizeof(vis));
    myq.push(Pos(1, 1, 1));
    vis[1][1] = true;

    while(!myq.empty()) {
        cur = myq.front(); 
        myq.pop();
        if (finish(cur) == true) {
            ans = min(ans, cur.c);
            return;
        }
        for (int i = 0; i < 4; i++){
            nxt = Pos(cur.x + dir[i][0], cur.y + dir[i][1], cur.c + 1);
            if (nxt.legal() == true) {
                vis[nxt.x][nxt.y] = true;
                myq.push(nxt);
            }
        }
    }
}

void rec(int i) {
    if (i == 10)
        bfs();
    else {
        p[i + 'a'] = true;
        rec(i + 1);
        p[i + 'a'] = false;
        p[i + 'A'] = true;
        rec(i + 1);
        p[i + 'A'] = false;
    }
}

void solve() {
    memset(p,false,sizeof(p));
    rec(0); /// recursive to trace all permutation for 0~9 (a~j)
}

int main() {
    while(scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; i++)
            scanf("%s", m[i] + 1);
        ans = INF;
        solve();
        printf("%d\n",ans == INF ? -1 : ans);
    }
    return 0;
}
