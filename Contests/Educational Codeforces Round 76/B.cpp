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
		int x,y;
		scanf("%d%d",&x,&y);
		if(x == 1 && y == 1) puts("YES");
		else if(x == 2 && y <= 3) puts("YES");
		else if(x == 3 && y <= 3) puts("YES");
		else if(x >= 4) puts("YES");
		else puts("NO");
	}
	return 0;
}
