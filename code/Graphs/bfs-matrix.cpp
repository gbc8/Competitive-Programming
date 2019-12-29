#include <bits/stdc++.h> 

using namespace std;

const int MAXN = 1e3+5;

int adj[MAXN][MAXN];
int dist[MAXN];

void bfs(int origem) {
	memset(dist, -1, sizeof dist);
	queue<int> fila;
	dist[origem] = 0;
	fila.push(origem);
	while (!fila.empty()) {
		int u = fila.front();
		fila.pop();
		for (int v = 0; v < MAXN; ++v) {
			if (adj[u][v] != 0) {
				if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				fila.push(v);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//define ms;
	return 0;
}
