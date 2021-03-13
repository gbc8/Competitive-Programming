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
		int n, ans = inf;
		sf(n);
		vector<int> v(n);
		forn(i,n) sf(v[i]);
		map<int,int> mp;
		for(int i = 0; i < n; ++i){
			if(mp.count(v[i])) ans = min(ans,i-mp[v[i]]+1);
			mp[v[i]] = i;
		}
		if(ans == inf) ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}
