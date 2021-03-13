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
	int n,x=0;
	sf(n);
	vector<lli> v(n+10),ans(n+10);
	forn(i,n/2) scanf("%lld", &v[i+1]);
	ans[n] = v[1];
	for(int i = 2; i <= n/2; ++i){
		if(v[i] <= v[i-1] && !x){
			ans[n-i+1] = v[i];
		}else{
			ans[n-i+1] = ans[n-i+2];
			ans[i] = v[i]-ans[n-i+1];
			if(ans[i] < ans[i-1]){
				lli d = ans[i-1]-ans[i];
				ans[i] += d;
				ans[n-i+1] -= d;
			}
			x = 1;
		}
	}  
	forn(i,n) printf("%lld ", ans[i+1]);
	puts("");
	return 0;
}
