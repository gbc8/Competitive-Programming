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
	cin >> t;
	while(t--){
		int n,m, diff = 0, ans = 0;
		string s;
		cin >> n >> m >> s;
		vector<bool> eql(n,true);
		for(int i = 0; i <= n-i-1; ++i){
			if(s[i] != s[n-i-1]){
				eql[i] = false;
				eql[n-i-1] = false;
				++diff;
			}
		}
		forn(i,m){
			int p;
			char c;
			cin >> p >> c;
			--p;
			s[p] = c;
			if(eql[p] == true){
				if(s[p] != s[n-p-1]){
					eql[p] = false;
					eql[n-p-1] = false;
					++diff;
				}
			}else if(eql[p] == false){
				if(s[p] == s[n-p-1]){
					eql[p] = true;
					eql[n-p-1] = true;
					--diff;
				}
			}
			if(diff == 0) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
