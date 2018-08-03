
//uva820
#include <iostream>
#include <cstring>
#include <queue>
#define M 105

using namespace std;

int adj[M][M];		// adjacency matrix

int Edmonds_Karp(int s, int t) {
	int f = 0;	  // max flow
	while (true) {  // break until path not found.
		// BFS
		int q[M];			  // BFS queue
		int Path[M];		   // Path for back trace
		int Head = 0, Tail = 0;

		memset(Path, -1, sizeof(Path));
		q[0] = s;
		Path[s] = s;	// Source, back trace end point
		Tail = 1;

		while(Head < Tail && Path[t] == -1) {
			for(int i = q[Head], j = 0; j < M; ++j) {
				if(Path[j] == -1 && adj[i][j] > 0) {
					q[Tail] = j;
					Path[j] = i;
					++Tail;
				}
			}
			++Head;
		}

		// could find a path from s to t.
		if (Path[t] == -1)
			break;

		int df = 2147483647;
		// back tracing find minimum bandwidth
		int i = Path[t], j = t;
		while(i != j) {
			df = min(df, adj[i][j]);
			j = i;
			i = Path[j];
		}
		
		// refresh each link's bandwidth with Min.
		i = Path[t], j = t;
		while(i != j) {
			adj[i][j] -= df;
			adj[j][i] += df;
			j = i;
			i = Path[j];
		}
		f += df;
	}
	return f;
}

int main() {
	int n;
	int ti = 0;
	while(cin >> n && n) {
		memset(adj, 0, sizeof(adj));
		int s, t, c;
		int x, y, b;
		cin >> s >> t >> c;

		for(int i = 0; i < c; ++i) {
			cin >> x >> y >> b;

			// one pair might has multiple link, but all links are bi-connect
			// so combine their bandwidth.
			adj[x][y] += b;
			adj[y][x] += b;
		}

		cout << "Network " << ++ti << endl;
		cout << "The bandwidth is " << Edmonds_Karp(s, t) << "." << endl << endl;
	}
	return 0;
}
