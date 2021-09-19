vector<vector<int>> g;
vector<int> vs,tin,low;
vector<pii> bridges;
int t = 1;

void dfs(int v, int p){
	vs[v] = 1;
	tin[v] = low[v] = t++;
	for(int u : g[v]){
		if(!vs[u]){
			dfs(u,v);
			low[v] = min(low[v],low[u]);
			if(low[u] > tin[v]) bridges.pb({v,u});
		}else if(u != p){
			low[v] = min(low[v],tin[u]);
		}
	}
}
