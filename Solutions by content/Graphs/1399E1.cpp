#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define lli long long int
#define pii pair<lli,lli>
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;
 
using namespace std;

vector<vector<pii>> g;
map<int,int> cnt;

void dfs(int v, int p = -1, int idx = -1){
	if(g[v].size() == 1) cnt[idx] = 1;
	for(pii x : g[v]){
		if(x.ff != p){
			dfs(x.ff,v,x.ss);
			if(idx != -1)	cnt[idx] += cnt[x.ss];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		int n;
		lli s;
		scanf("%d%lld", &n,&s);
		g.resize(n+1);
		vector<lli> cost(n);
		forn(i,n-1){
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			g[a].pb({b,i});
			g[b].pb({a,i});
			cost[i] = c;
		}
		dfs(1);
		priority_queue<pii> pq;
		lli sum = 0;
		forn(i, n-1){
			sum += cost[i]*cnt[i];
			pq.push({cost[i]*cnt[i] - cost[i]/2*cnt[i],i});
		}
		int ans = 0;
		while(sum > s){
			auto e = pq.top();
			pq.pop();
			sum -= e.ff;
			cost[e.ss] /= 2;
			pq.push({cost[e.ss]*cnt[e.ss] - cost[e.ss]/2*cnt[e.ss],e.ss});
			++ans;
		}
		printf("%d\n", ans);
		g.clear(),cnt.clear();
	}
	return 0;
}
