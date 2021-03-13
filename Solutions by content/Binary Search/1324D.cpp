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
	int n;
	sf(n);
	vector<int> a(n),b(n),c(n);
	forn(i,n) sf(a[i]);
	forn(i,n) sf(b[i]);
	forn(i,n) c[i] = a[i]-b[i];
	sort(c.begin(), c.end());
	ll ans = 0;
	for(int i = upper_bound(c.begin(), c.end(),0)-c.begin(); i < n; ++i){
		ans += i-(upper_bound(c.begin(), c.end(), -c[i])-c.begin());
	}
	printf("%lld\n", ans);
	return 0;
}
