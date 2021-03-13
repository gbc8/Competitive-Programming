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
const int mod = 1e9+7;

using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h,w,f=0;
	scanf("%d%d", &h,&w);
	vector<vector<int>> g(h+5,vector<int>(w+5));
	vector<int> r(h),c(w);
	forn(i,h){
		sf(r[i]);
		forn(j,r[i]) g[i][j] = 1;
		g[i][r[i]] = -1;
	}
	forn(i,w){
		sf(c[i]);
		forn(j,c[i]){
			if(g[j][i] == -1) f = 1;
			else g[j][i] = 1;
		}
		if(g[c[i]][i] == 1) f = 1;
		else g[c[i]][i] = -1;
	}
	if(f) puts("0");
	else{
		int x = 0,ans = 1;
		forn(i,h){
			forn(j,w){
				if(g[i][j] == 0) ++x;
			}
		}
		forn(i,x)	ans = (ans*2)%mod;
		printf("%d\n", ans);
	}
	return 0;
}
