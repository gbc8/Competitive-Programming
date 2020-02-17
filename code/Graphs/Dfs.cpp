#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

vector<int> adj[ms];
bool vis[ms];

void dfs(int u) {
	vis[u] = true;	
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//define ms;
	return 0;
}
