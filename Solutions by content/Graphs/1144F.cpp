#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;

using namespace std;

vector<vector<int>> g;
vector<bool> d, c, ed;

bool dfs(int v){	
	for (int u : g[v]){
		if (!d[u]){
			d[u] = true;
			c[u] = !c[v];
			if (!dfs(u)) return false;
		}else if (c[v] == c[u])	return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	vector<pii> edges;
	g.resize(n+1), d.resize(n+1), c.resize(n+1),ed.resize(n+1);
	forn(i,m){
		int x, y;
		scanf("%d%d", &x,&y);
		g[x].pb(y);
		edges.pb({x,y});
		g[y].pb(x);
	}
	bool f = dfs(1);
	if(f){
		puts("YES");
		forn(i,m) {
			if(c[edges[i].ff] < c[edges[i].ss]) printf("1");
			else printf("0");
		}
		puts("");
	}else puts("NO");
	return 0;
}
