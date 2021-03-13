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
vector<vector<int>> dist;
int n,m,k;
	
void dijkstra(int source){
	dist[source].resize(n+1,inf);
	dist[source][source] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, source);
	while(!pq.empty()){
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if(d > dist[source][u]) continue;
		for(auto e : g[u]){
			int v = e.first, w = e.second;
			if(dist[source][u] + w < dist[source][v]) {
				dist[source][v] = dist[source][u] + w;
				pq.emplace(dist[source][v], v);
			}
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n,&m,&k);
	g.resize(n+1),dist.resize(n+1);
	vector<pii> r(k);
	forn(i,m){
		int x,y,w;
		scanf("%d%d%d", &x,&y,&w);
		g[x].pb({y,w});
		g[y].pb({x,w});
	}
	lli sum = inf;
	for(int i = 1; i <= n; ++i) dijkstra(i);
	forn(i,k) scanf("%d%d", &r[i].ff, &r[i].ss);
	for(int i = 1; i <= n; ++i){
		for(auto j : g[i]){
			lli psum = 0;
			for(auto k : r){
				int x = dist[k.ff][k.ss];
				x = min(x,dist[k.ff][i]+ dist[j.ff][k.ss]);
				psum += min(x, dist[k.ff][j.ff] + dist[i][k.ss]);
			}
			sum = min(psum,sum);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
