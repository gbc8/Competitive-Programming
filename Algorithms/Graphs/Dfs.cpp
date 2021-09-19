const int ms = 1e6+5;

vector<int> adj[ms];
bool vis[ms];

void dfs(int u) {
	vis[u] = true;	
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
	}
}
