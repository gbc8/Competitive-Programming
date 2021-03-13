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
 
vector<vector<pii>> g;
 
void dfs(int v, int i, int p, vector<pii> &par){
	par[v] = {p,i};
	for(pii u : g[v]){
		if(u.ff == p) continue;
		dfs(u.ff, u.ss, v, par);
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	sf(n);
	g.resize(n);
	vector<vector<pii>> par(n,vector<pii>(n));
	vector<int> ans(n-1,0);
	forn(i,n-1){
		int a,b;
		scanf("%d%d", &a,&b);
		g[--a].pb({--b,i});
		g[b].pb({a,i});
	}
	forn(i,n) dfs(i,-1,-1,par[i]);
	int m;
	sf(m);
	vector<pair<pii,int>> qry(m);
	forn(i,m) scanf("%d%d%d", &qry[i].ff.ff, &qry[i].ff.ss, &qry[i].ss);
	for(int i = m-1; i >= 0; --i){
		int k = --qry[i].ff.ss, j = --qry[i].ff.ff;
		while(j != k){
			ans[par[j][k].ss] = max(ans[par[j][k].ss],qry[i].ss);
			k = par[j][k].ff;
		}
	}
	forn(i,n-1){
		if(ans[i] == 0) ans[i] = 1e6;
	}
	forn(i,m){
		int k = qry[i].ff.ss, j = qry[i].ff.ff, mni = 1e6;
		while(j != k){
			mni = min(mni,ans[par[j][k].ss]);
			k = par[j][k].ff;
		}
		if(mni != qry[i].ss){
			puts("-1");
			return 0;
		}
	}
	forn(i,n-1) printf("%d ", ans[i]);
	puts("");
	return 0;
}
