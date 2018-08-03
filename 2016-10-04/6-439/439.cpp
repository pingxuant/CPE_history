
//uva 439
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int mov[8][2] = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}};

class pos{
    public:
    int r, c, cnt;
    pos() {}
    pos(int _r, int _c, int _cnt) : r(_r), c(_c), cnt(_cnt) {}
    bool operator==(const pos p) {
		return r==p.r && c==p.c;
	}
};

bool legal(pos p) {
    return (p.c >= 1 && p.c <= 8 && p.r >= 1 && p.r <= 8);
}



int main() {
	
    char s[5], t[5];
    queue<pos> q;
    pos cur, goal;
    int ans;
	
    while (scanf("%s %s", &s, &t) == 2) {
        goal = pos(t[1] - '0', t[0] - 'a' + 1, 0);
        while (!q.empty())
            q.pop();
        q.push(pos(s[1] - '0', s[0] - 'a' + 1, 0));
        while (1) {
            cur = q.front();
	    q.pop();
            if (cur == goal) {
                ans = cur.cnt;
                break;
            }

            for (int i = 0 ; i < 8 ; i++) {
                pos tmp = pos(cur.r + mov[i][0], cur.c + mov[i][1], cur.cnt + 1);
                if (legal(tmp)) {
                    q.push(tmp);
                }
            }
        }

        printf("To get from %s to %s takes %d knight moves.\n", s, t, ans);
    }

    return 0;
}

