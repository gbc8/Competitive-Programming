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
	sf(t);
	while(t--){
		int n,k, ans = inf;
		scanf("%d%d", &n,&k);
		vector<int> v(n),psum(2*k+10);
		forn(i,n) sf(v[i]);
		map<int,int> sum;
		forn(i,n/2) {
			++sum[v[i]+v[n-i-1]];
			++psum[min(1+v[i], 1+v[n-i-1])];
			--psum[max(v[i]+k, v[n-i-1]+k)+1];
		}
		forn(i,2*k + 5) psum[i+1] += psum[i];
		for(int i = 2; i <= 2*k; ++i){
			ans = min(ans, (psum[i]-sum[i]) + (n/2 - psum[i])*2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
