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

int n,m,w;
vector<ll> v;

bool check(ll val){
	ll cnt = 0, nd = 0;
	vector<ll> b(n);
	forn(i,n){
		if(i-w >= 0) cnt -= b[i-w];
		if(v[i]+cnt < val){
			b[i] = val-v[i]-cnt;
			nd += b[i], cnt += b[i];
		}
	}
	return (nd <= m);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n,&m,&w);
	v.resize(n);
	forn(i,n) scanf("%lld", &v[i]);
	ll l = 1, r = 1e9+1e5;
	while(r-l > 1){
		ll x = (l+r)/2;
		if(check(x)) l = x;
		else r = x;
	}
	if(check(r)) l = r;
	printf("%lld\n",l);
	return 0;
}
