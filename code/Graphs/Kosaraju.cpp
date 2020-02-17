#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<vector<int>> g,gt,components; //g: graph, gt : transpose graph 
vector<bool> vs;
vector<int> component;
stack<int> s;
int ncomp = 0;
int n,m,x,y;

void dfs(int u){
	vs[u] = true;
	for(int v : g[u]){
		if(!vs[v]) dfs(v);
	}
	s.push(u);
}

void dfs2(int u){
	printf("%d ", u); 
  component[u] = ncomp;
  components[ncomp].pb(u);
	vs[u] = true;
	for(int v : gt[u]){
		if(!vs[v]) dfs2(v);
	}
}

void kosaraju(){
	for(int i = 1; i <= n; ++i){
		if(!vs[i]) dfs(i);
	}
	vs.assign(n+1, false);
	while(s.size()){
		int v = s.top();
		s.pop();
		if(!vs[v]){
			printf("Component %d: ", ncomp);
			dfs2(v);
			++ncomp;
			puts("");
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n,&m);
	g.resize(n+1);
	gt.resize(n+1);
	vs.resize(n+1,false);
	component.resize(n+1,0);
	components.resize(n+1);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &x,&y);
		g[x].pb(y);
		gt[y].pb(x); 
	}
	kosaraju();
	return 0;
}
