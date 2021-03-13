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
		int n;
		sf(n);
		vector<int> a(n),b(n),c(n);
		forn(i,n) sf(a[i]);
		set<int> s;
		forn(i,n){
			sf(b[i]);
			c[i] = b[i]-a[i];
			if(c[i] != 0) s.insert(c[i]);
		}
		if(s.size() > 1){
			puts("NO");
			continue;
		}
		int i = 0;
		while(i < n && c[i] == 0) ++i;
		while(i < n && c[i] == *s.begin()) ++i;
		while(i < n && c[i] == 0) ++i;
		if(i != n || *s.begin() < 0) puts("NO");
		else puts("YES");
	}
	return 0;
}	
