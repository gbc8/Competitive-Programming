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
	int n,x;
	scanf("%d%d", &n,&x);
	vector<lli> v(n+5),sum(n+5),pref(n+5),suf(n+5);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &v[i]);
		sum[i] = sum[i-1]+v[i];
	}
	lli mni = 0,mxi = sum[n-1],g = 0,ans = 0;
	for(int i = 1; i <= n; ++i){
		mni = min(mni,sum[i]);
		pref[i] = max((lli)0, sum[i]-mni);
		ans = max(ans,pref[i]);
	}
	for(int i = n; i > 0; --i){
		mxi = max(mxi,sum[i]);
		suf[i] = max((lli)0, mxi-sum[i-1]);
	}
	for(int i = 1; i <= n; ++i){
		ans = max(ans, x*sum[i] + suf[i+1] + g);
		g = max(g,pref[i]-x*sum[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
