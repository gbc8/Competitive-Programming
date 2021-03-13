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

class dsu{
	private:
		vector<int> sz, p;
		
		void make(int n){
			sz.resize(n+5), p.resize(n+5);
			for(int i = 0; i <= n; ++i){
				sz[i] = 1;
				p[i] = i;
			}
		}
		
	public:
		void init(int n){
			make(n);
		}
		
		int find(int a){
			if(p[a] != a) p[a] = find(p[a]);
			return p[a];
		}
		
		int get(int a){
			return sz[a];
		}
		
		void join(int a, int b){
			a = find(a);
			b = find(b);
			if(a!=b){
				if(sz[a] > sz[b]){
				  p[b] = a;
				  sz[a] += sz[b];
				}else{
				  p[a] = b;
				  sz[b] += sz[a]; 
				}
			}
		}
};

vector<vector<int>> g;
vector<int> vs,tin,low;
vector<pii> bridges,dedg;
map<pii,bool> b,used;
map<pii,int> ord;
int t = 1;
dsu d;

void dfs1(int v, int p = -1){
	vs[v] = 1;
	tin[v] = low[v] = t++;
	for(int u : g[v]){
		if(!vs[u]){
			dfs1(u,v);
			low[v] = min(low[v],low[u]);
			if(low[u] > tin[v]){
				bridges.pb({v,u});
				b[{u,v}] = b[{v,u}] = true;
			}else d.join(u,v);
		}else if(u != p){
			low[v] = min(low[v],tin[u]);
		}
	}
}

void dfs2(int v){
	vs[v] = 2;
	for(int u : g[v]){
		if(b[{u,v}]) continue;
		if(!used[{v,u}]){
			dedg.pb({v,u});
			used[{v,u}] = used[{u,v}] = 1;
		}
		if(vs[u] == 2) continue;
		dfs2(u);	
	}
}

void dfs3(int v){
	vs[v] = 3;
	for(int u : g[v]){
		if(b[{u,v}] && !used[{v,u}]){
			dedg.pb({u,v});
			used[{v,u}] = used[{u,v}] = 1;
		}
		if(vs[u] == 3) continue;
		dfs3(u);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	scanf("%d%d", &n,&m);
	d.init(n);
	g.resize(n+1),vs.resize(n+1),tin.resize(n+1),low.resize(n+1);
	forn(i,m){
		int a,b;
		scanf("%d%d", &a,&b);
		g[a].pb(b);
		g[b].pb(a);
		ord[{a,b}] = ord[{b,a}] = i+1;
	}
	dfs1(1);
	int mxi = 0, vm = 0;
	for(auto e : bridges){
		if(vs[e.ff] != 2) dfs2(e.ff);
		if(vs[e.ss] != 2) dfs2(e.ss);
		if(d.get(d.find(e.ff)) > mxi){
			mxi = d.get(d.find(e.ff));
			vm = d.find(e.ff);
		}
		if(d.get(d.find(e.ss)) > mxi){
			mxi = d.get(d.find(e.ss));
			vm = d.find(e.ss);
		}
	}
	if(bridges.empty()){
		dfs2(1);
		mxi = n;
	}else dfs3(vm);
	vector<pii> ans(m);
	forn(i,dedg.size()) ans[ord[dedg[i]]-1] = dedg[i];
	printf("%d\n", mxi);
	for(auto e : ans) printf("%d %d\n", e.ff, e.ss);
	return 0;
}
