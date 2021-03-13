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
 
vector<vector<int>> g,g2;
vector<bool> d, c;
 
bool dfs(int v){
	for(int u : g2[v]){
		if(!d[u]){
			d[u] = true;
			c[u] = !c[v];
			if(!dfs(u)) return false;
		}else if(c[v] == c[u])	return false;
	}
	return true;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	scanf("%d%d", &n,&m);
	g.resize(n+1),d.resize(n+1),c.resize(n+1),g2.resize(n+1);
	vector<pii> edges;
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		edges.pb({a,b});
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> v1(n+1,1);
	for(int i = 1; i <= n; ++i){
		if(g[i].size() != n){
			for(int u : g[i]){
				v1[u] = 0;
			}
			break;
		}
	}
	int vb = -1;
	for(auto e : edges){
		if(v1[e.ff] || v1[e.ss]) continue;
		g2[e.ff].pb(e.ss);
		g2[e.ss].pb(e.ff);
		vb = e.ff;
	}
	if(vb == -1 || !dfs(vb)){
		puts("-1");
		return 0;
	}
	vector<int> ans(n+1),cnt(4,0);
	for(int i = 1; i <= n; ++i){
		if(v1[i] == 1) ans[i] = 1,++cnt[1];
		else{
			if(c[i]) ans[i] = 2,++cnt[2];
			else ans[i] = 3,++cnt[3];
		}
	}
	for(int i = 1; i <= n; ++i){
		//printf("%d %d %d %d\n", i, int(g[i].size()), cnt[ans[i]],n-cnt[ans[i]]);
		if(g[i].size() != n-cnt[ans[i]]){
			puts("-1");
			return 0;
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}
