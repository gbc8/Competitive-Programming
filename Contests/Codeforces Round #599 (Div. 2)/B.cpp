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
	cin >> t;
	while(t--){
		int n;
		string s,r;
		cin >> n >> s >> r;
		vector<pair<char,char>> v;
		forn(i,n){
			if(s[i] != r[i]){
				v.pb({s[i],r[i]});
			}
		}
		if(v.size() != 2) cout << ("No\n");
		else{
			if(v[0] == v[1]) cout << ("Yes\n");
			else cout << ("No\n");
		}
	}
	return 0;
}
