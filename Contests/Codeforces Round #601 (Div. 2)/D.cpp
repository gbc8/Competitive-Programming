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

vector<char> val;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(char i = '0'; i <= '9'; ++i) val.pb(i);
	for(char i = 'a'; i <= 'z'; ++i) val.pb(i);
	for(char i = 'A'; i <= 'Z'; ++i) val.pb(i);
	int t;
	cin >> t;
	while(t--){
		int n,m,k,r=0;
		cin >> n >> m >> k;
		char f[n][m],out[n][m];
		vector<pii> c;
		forn(i,n){
			forn(j,m){
				cin >> f[i][j];
				if(f[i][j] == 'R') ++r;
			}
		}
		int d = 1;
		forn(i,n){
			if(d) forn(j,m) c.pb({i,j});
			else for(int j = m-1; j >= 0; --j) c.pb({i,j});
			d = 1-d;
		}
		vector<int> cnt(k, r/k);
		forn(i,r%k) ++cnt[i];
		int i;
		for(i = 0; i < k; ++i){
			for(int j = 0; j < cnt[i];){
				int a = c.back().ff, b = c.back().ss;
				c.pop_back();
				out[a][b] = val[i];
				if(f[a][b] == 'R') ++j;
			}
		}
		while(!c.empty()){
			int a = c.back().ff, b = c.back().ss;
			c.pop_back();
			out[a][b] = val[i-1];
		}
		forn(j,n){
			forn(k,m){
				cout << out[j][k];
			}
			cout << "\n";
		}
	}
	return 0;
}
