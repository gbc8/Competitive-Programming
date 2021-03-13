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
	int t;
	sf(t);
	while(t--){
		int n,m;
		scanf("%d%d", &n,&m);
		vector<int> v(n);
		int mn = inf, pos = 0;
		forn(i,n){
			sf(v[i]);
			if(v[i] < mn) mn = v[i], pos = i;
		}
		if(n == 2 || n != m) {
			puts("-1");
		}else{
			vector<pii> ans;
			lli c = 0;
			forn(i,n){
				int j = i+1, l = i+2;
				if(l > n) l = 1;
				c += (v[j-1]+v[l-1]);				
				ans.pb({j,l});
			}
			printf("%lld\n", c);
			forn(i,n) printf("%d %d\n", ans[i].ff, ans[i].ss);
		}
	}
	return 0;
}
