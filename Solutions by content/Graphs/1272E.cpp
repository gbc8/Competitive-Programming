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
vector<int> d,ans;
int n;
 
void bfs(vector<int> &source, vector<int> &goal) {
	queue<int> q;
	d.resize(n+1);
	d.assign(n+1,-1);
	for(int i = 0; i < source.size(); ++i){	
		d[source[i]] = 0;	
		q.push(source[i]);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : g[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 0; i < goal.size(); ++i){
		if(d[goal[i]] == -1) continue;
		ans[goal[i]] = d[goal[i]];
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sf(n);
	g.resize(n+1),ans.resize(n+1,-1);
	vector<int> v(n), e, o;
	forn(i,n){
		sf(v[i]);
		if(v[i]%2) o.pb(i);
		else e.pb(i);
		if(i-v[i] >= 0) g[i-v[i]].pb(i);
		if(i+v[i] < n) g[i+v[i]].pb(i); 
	}
	bfs(e,o);
	bfs(o,e);
	forn(i,n) printf("%d ", ans[i]);
	puts("");
	return 0;
}
