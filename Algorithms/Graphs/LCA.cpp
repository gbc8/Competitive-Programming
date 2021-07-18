#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g,up;
vector<int> h;

void dfs(int v, int p){
	h[v] = h[p]+1;
	up[v][0] = p;
	for(int i = 1; i <= 20; ++i) up[v][i] = up[up[v][i-1]][i-1];
	for(int u : g[v]){
		if(u != p){
			dfs(u,v);
		}
	}
}

int lca(int v, int u){
	if(h[v] < h[u]) swap(u,v);
	int d = h[v]-h[u];
	for(int i = 20; i >= 0; --i){
		if((1 << i) <= d){
			v = up[v][i];
			d -= (1<<i);
		}
	}
	if(v == u) return v;
	for(int i = 20; i >= 0; --i){
		if(up[v][i] != up[u][i]){
			v = up[v][i];
			u = up[u][i];
		}
	}
	return up[v][0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
