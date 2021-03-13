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
	vector<int> v(n),vo;
	forn(i,n){
		sf(v[i]);
		if(v[i]) vo.pb(i);
	}
	if(vo.size() == 1){
		puts("-1");
	}else{
		lli ans = LLONG_MAX;
		vector<int> div;
		int sz = vo.size();
		for(int i = 2; i <= sqrt(sz); ++i){
			if(sz%i == 0){
				div.pb(sz/i);
				div.pb(i);
			}
		}
		div.pb(sz);
		for(auto i : div){
			lli p = 0;
			for(int j = 0; j < vo.size(); j += i){
				lli m = vo[(2*j+i-1)/2];
				for(int l = j; l < j+i; ++l) p += abs(vo[l]-m);
			}
			ans = min(ans,p);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
