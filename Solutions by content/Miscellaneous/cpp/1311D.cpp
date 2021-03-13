#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = INT_MAX;
 
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		ll a,b,c;
		ll ans = inf;
		ll ansa,ansb,ansc;
		scanf("%lld%lld%lld", &a,&b,&c);
		if(b%a == 0 && c%b == 0){
			printf("0\n %lld %lld %lld\n", a,b,c);
			continue;
		}
		for(ll i = 1; i < int(2e4); ++i){
			for(ll k = i; k < int(2e4); k += i){
				for(ll l = k; l < int(2e4); l += k){
					if((abs(a-i) + abs(b-k) + abs(c-l)) < ans){
						ans = (abs(a-i) + abs(b-k) + abs(c-l));
						ansa = i;
						ansb = k;
						ansc = l;
					}
				}
			} 
		}
		printf("%lld\n%lld %lld %lld\n", ans, ansa,ansb,ansc);
	}
	return 0;
}
