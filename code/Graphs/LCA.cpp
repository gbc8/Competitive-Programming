#include <bits/stdc++.h>

using namespace std;

int t,l,n;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<int>> g;

void dfs(int u, int p){
	tin[u] = ++t;
	up[u][0] = p;
	for(int i = 1; i <= l; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for(int v : g[u]){
		if(v != p) dfs(v,u);
	}
	tout[u] = ++t;
}

bool ancestor(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	for(int i = l; i >= 0; --i){
		if(!ancestor(up[u][i],v)) u = up[u][i];
	}
	return up[u][0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
