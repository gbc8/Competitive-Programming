#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 2*1e5+10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
 
using namespace std;
 
vector<ll> fact(mx), inverse(mx);
 
ll fexp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans * a % mod; 
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
 
ll C(ll n, ll k){
	if(k > n) return 0;
	return (((fact[n]*inverse[k]))%mod * inverse[n-k])%mod; 
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	fact[0] = 1;
	inverse[0] = 1;
	for(int i = 1; i < mx; ++i) {
		fact[i] = (fact[i-1]*i)%mod;
		inverse[i] = fexp(fact[i], mod-2);
	}
	while(t--){
		int n,m;
		scanf("%d%d", &n,&m);
		n = abs(n);
		if((m-n)%2 || n > m) {
			puts("0");
			continue;
		}
		printf("%lld\n", (C(m, n+(m-n)/2)*fexp(fexp(2,m),mod-2))%mod);
	}
	return 0;
}
