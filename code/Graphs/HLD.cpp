#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<int> head, pos, chainSize, chainId, subtsize,tin,tout;
vector<vector<int>> up, g;
int chainNo, lg, t;

void hld(int cur){
	if(head[chainNo] == -1) head[chainNo] = cur;
	chainId[cur] = chainNo;
	//pos[cur] = chainSize[chainNo];
	++chainSize[chainNo];
	int heavy = -1, size = -1;
	//find heavy node
	for(auto e : g[cur]){
		if(subtsize[e] > size){
			heavy = e;
			size = subtsize[e];
		}
	}
	if(heavy != -1) hld(heavy);
	//light nodes
	for(auto e : g[cur]){
		if(e != heavy){
			++chainNo;
			hld(e);
		}
	}
}

bool ancestor(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	for(int i = lg; i >= 0; --i){
		if(!ancestor(up[u][i],v)) u = up[u][i];
	}
	return up[u][0];
}

void dfs(int u, int p){
	tin[u] = ++t;
	up[u][0] = p;
	subtsize[u] = 1;
	for(int i = 1; i <= lg; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for(int v : g[u]){
		if(v != p) {
			dfs(v,u);
			subtsize[u] += subtsize[v];
		}
	}
	tout[u] = ++t;
}

void init(int n, int root = 0){
	chainNo = 0, t = 0, lg = ceil(log2(n));
	head.assign(n,-1);
	pos.resize(n);
	chainSize.resize(n);
	chainId.resize(n);
	tin.resize(n);
	tout.resize(n);
	subtsize.assign(n,0);
	up.assign(n, vector<int>(lg+1));
	dfs(root,root);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
