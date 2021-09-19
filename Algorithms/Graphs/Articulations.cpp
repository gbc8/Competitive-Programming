vector<vector<int>> g;
vector<bool> vs;
vector<int> tin, low;
set<int> aps;
int t, n;

void dfs(int v, int p) {
	vs[v] = true;
  tin[v] = low[v] = t++;
  int children = 0;
  for(int to : g[v]) {
  	if(to == p) continue;
    if(!vs[to]) {
    	dfs(to, v);
      low[v] = min(low[v], low[to]);
      if(low[to] >= tin[v] && p != -1) aps.insert(v);
      ++children;
   	}else low[v] = min(low[v], tin[to]);
  }
  if(p == -1 && children > 1) aps.insert(v);
}

void find_aps() {
	t = 1;
  vs.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for(int i = 1; i <= n; ++i) {
    if(!vs[i]) dfs(i, -1);
  }
}
