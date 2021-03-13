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

vector<vector<int>> g;
vector<int> vs;
deque<int> topo;

void dfs(int v, int p = -1){
	vs[v] = true;
	for(int u : g[v]){
		if(!vs[u]) dfs(u,v);
	}
	topo.push_front(v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		int n,m,x = 0;
		scanf("%d%d", &n,&m);
		g.resize(n+1);
		vs.resize(n+1,0);
		vector<pii> e;
		vector<int> p(n+1);
		forn(i,m){
			int x,a,b;
			scanf("%d%d%d", &x,&a,&b);
			if(x == 1) g[a].pb(b);
			e.pb({a,b});
		}
		for(int i = 1; i <= n; ++i){
			if(!vs[i]) dfs(i);
		}
		forn(i,n) p[topo[i]] = i;
		for(int i = 1; i <= n && !x; ++i){
			for(int v : g[i]){
				if(p[i] > p[v]){
					x = 1;
					break;
				}
			}
		}
		if(x)	puts("NO");
		else{
			puts("YES");
			for(pii a : e){
				if(p[a.ff] > p[a.ss]) printf("%d %d\n", a.ss, a.ff);
				else printf("%d %d\n", a.ff,a.ss);
			}
		}
		topo.clear(),g.clear(),vs.clear();
	}
	return 0;
}
