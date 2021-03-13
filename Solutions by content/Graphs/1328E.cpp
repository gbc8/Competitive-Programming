#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define lli long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;
 
using namespace std;
 
vector<int> tin, tout, d;
vector<vector<int>> up;
vector<vector<int>> g;
int t = 0,l;
 
void dfs(int u, int p = -1, int dt = 0){
	tin[u] = ++t;
	up[u][0] = (p==-1)? u : p;
	d[u] = dt;
	for(int v : g[u]){
		if(v != p) dfs(v,u, dt + 1);
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
	int n,m;
	scanf("%d%d",&n,&m);
	g.resize(n+1),tin.resize(n+1),tout.resize(n+1), d.resize(n+1,0);
	l = ceil(log2(n));
	up.assign(n+1,vector<int>(l+1));
	forn(i,n-1){
		int a,b;
		scanf("%d%d", &a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	forn(i,m){
		int k,dpt = -1;
		sf(k);
		vector<int> v(k);
		forn(j,k){
			sf(v[j]);
			if(dpt == -1) dpt = v[j];
			if(d[v[j]] > d[dpt]) dpt = v[j];
		}
		bool ans = true;
		forn(j,k){
			if(dpt == v[j]) continue;
			if(!ancestor(up[v[j]][0], dpt)){
				ans = false;
				break;
			}
		}
		printf((ans? "YES\n" : "NO\n"));
	}
	return 0;
}
