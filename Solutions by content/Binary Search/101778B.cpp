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
	int t;
	scanf("%d", &t);
	while(t--){
		ll n,a;
		scanf("%lld%lld", &n,&a);
		ll l = 0, r = n, m, ans;
		while(l <= r){
			m = (l+r)/2;
			if(n*a - m*(m+1)/2 >= n-m){
				ans = m;
				l = m+1;
			}else r = m-1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
