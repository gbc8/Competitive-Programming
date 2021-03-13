#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
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
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,sz = 0;
	sf(n);
	vector<int> v(n);
	vector<pii> ord(n);
	ordered_set s;
	forn(i,n){
		sf(v[i]);
		ord[i] = {v[i],i};
	}
	sf(m);
	vector<pair<pii,int>> qry(m);
	vector<int> out(m);
	forn(i,m){
		scanf("%d%d", &qry[i].ff.ff, &qry[i].ff.ss);
		qry[i].ss = i; 
	}
	sort(ord.begin(),ord.end(), [&](pii &a, pii &b){
		if(a.ff != b.ff) return a.ff > b.ff;
		return a.ss < b.ss;
	});
	sort(qry.begin(),qry.end());
	forn(i,m){
		while(sz < qry[i].ff.ff) s.insert(ord[sz++].ss);
		out[qry[i].ss] = v[*s.find_by_order(qry[i].ff.ss-1)];
	}
	forn(i,m) printf("%d\n", out[i]);
	return 0;
}
