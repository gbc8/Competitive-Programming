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
		int n,x,a,b;
		scanf("%d%d%d%d", &n,&x,&a,&b);
		if(a > b) swap(a,b);
		while(b < n && x) ++b,--x;
		while(a > 1 && x) --a,--x;
		printf("%d\n", b-a);
	}
	return 0;
}
