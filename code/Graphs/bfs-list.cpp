#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

vector<int> adj[ms];
int dist[ms];

void bfs(int origem) {
	memset(dist, -1, sizeof dist);
	queue<int> q;
	dist[origem] = 0; 
	q.push(origem);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
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
