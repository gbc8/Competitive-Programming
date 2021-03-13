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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	sf(n);
	map<int,int> cnt;
	vector<pair<pii,int>> v(n),out(n);
	map<pii,unordered_set<int>> get;
	forn(i,n-2){
		scanf("%d%d%d", &v[i].ff.ff, &v[i].ff.ss, &v[i].ss);
		int j = v[i].ff.ff, k = v[i].ff.ss, l = v[i].ss;
		get[{j,k}].insert(l);
		get[{k,j}].insert(l);
		get[{j,l}].insert(k);
		get[{l,j}].insert(k);
		get[{k,l}].insert(j);
		get[{l,k}].insert(j);
		++cnt[v[i].ff.ff];
		++cnt[v[i].ff.ss];
		++cnt[v[i].ss];
	}
	forn(i,n-2){
		int j = v[i].ff.ff, k = v[i].ff.ss, l = v[i].ss;
		vector<pii> x = {{cnt[j],j},{cnt[k],k},{cnt[l],l}};
		sort(x.begin(),x.end());
		if(x[0].ff == 1 && x[1].ff == 2 && x[2].ff == 3){
			out[0] = {{x[0].ss,x[1].ss},x[2].ss};
			get[{x[1].ss,x[2].ss}].erase(x[0].ss);
		}
	}
	for(int i = 1; i < n-2; ++i){
		int j = out[i-1].ff.ss, k = out[i-1].ss;
		out[i] = {{j,k},*get[{j,k}].begin()};
		get[{k,*get[{j,k}].begin()}].erase(j);
	}
	printf("%d %d %d ", out[0].ff.ff, out[0].ff.ss, out[0].ss);
	for(int i = 1; i < n-2; ++i) printf("%d ", out[i].ss);
	return 0;
}
