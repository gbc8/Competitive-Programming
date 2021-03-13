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
const int mod = 998244353;
 
using namespace std;
 
vector<vector<int>> g;
vector<bool> d,c;
int x = 0, y = 0;

bool dfs(int v){
	d[v] = true;
	if(c[v]) ++x;
	else ++y;
	for(int u : g[v]){
		if(!d[u]){		
			c[u] = !c[v];	
			if(!dfs(u)) return false;
		}else if(c[v] == c[u])	return false;
	}
	return true;
}

void solve(){
	int n,m;
	lli ans=1;
	scanf("%d%d", &n,&m);
	g.resize(n+1),c.resize(n+1,false),d.resize(n+1,false);
	forn(i,m){
		int a,b;
		scanf("%d%d", &a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 1; i <= n; ++i){
		x = 0, y = 0;
		if(!d[i]){
			if(!dfs(i)){
				puts("0");
				return;
			}
			lli pa = 1, pb = 1;
			forn(j,x) pa = (pa*2)%mod;
			forn(j,y) pb = (pb*2)%mod;
			ans = (((pa + pb)%mod) * ans)%mod; 
		}
	}
	printf("%lld\n", ans);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		solve();
		g.clear(),c.clear(),d.clear();
	}
	return 0;
}
