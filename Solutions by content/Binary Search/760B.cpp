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

int n,m,k;

bool check(ll x){
	ll sum = x;
	sum += (((x-1)+(x-min((ll)k-1,x-1)))*min((ll)k-1,x-1))/2;
	sum += (((x-1)+(x-min((ll)n-k,x-1)))*min((ll)n-k,x-1))/2;
	return sum <= m;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n,&m,&k);
	m -= n;
	ll l = 1, r = m;
	while(r-l > 1){
		ll mid = (l+r)/2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	ll ans = check(r)? r : l;
	printf("%lld\n", ans+1);
	return 0;
}
