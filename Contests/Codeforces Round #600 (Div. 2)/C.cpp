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
	int n,m;
	scanf("%d%d", &n,&m);
	vector<lli> v(n);
	vector<lli> ans(n),msum(n);
	forn(i,n) scanf("%lld", &v[i]);
	sort(v.begin(),v.end());
	forn(i,n) msum[i%m] += v[i];
	lli sum = 0;
	lli k = 0,d=1;
	for(int i = n-1; i >= 0; --i){
		sum += d*v[i];
		if(++k == m) ++d,k = 0;
	}
	for(int i = n-1; i >= 0; --i){
		ans[i] = sum;
		sum -= msum[i%m];
		msum[i%m] -= v[i];
	}
	forn(i,n) printf("%lld ", ans[i]);
	return 0;
}
