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
		int a,b, ans = 0;
		scanf("%d%d", &a,&b);
		if(a > b) swap(a,b);
		b -= a;
		ans += b/5;
		b %= 5;
		ans += b/2;
		b %= 2;
		ans += b;
		printf("%d\n", ans);
	}
	return 0;
}
