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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<pii> vans;
	map<int, vector<pii>> mp;
	forn(i,n) cin >> v[i];
	forn(i,n){
		int vl = 0;
		for(int j = i; j > -1; --j){
			vl += v[j];
			mp[vl].pb({j,i});
		}
	}
	for(auto e : mp){
		int x = -1;
		vector<pii> pv;
		for(auto f : e.ss){
			if(f.ff > x) {;
				pv.pb(f);
				x = f.ss;
			}
		}
		if(pv.size() > vans.size()) vans = pv;
	}
	cout << vans.size() << '\n';
	for(auto e : vans) cout << e.ff+1 << " " << e.ss+1 << '\n';
	return 0;
}
