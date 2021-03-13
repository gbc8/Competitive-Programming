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
	int k;
	cin >> k;
	while(k--){
		int n;
		string s,t;
		cin >> n >> s >> t;
		vector<pii> swp;
		forn(i,n){
			if(s[i] != t[i]){
				int p = 0;
				for(int j = i+1; j < n; ++j){
					if(s[j] != t[j] && s[j] == s[i]){
						swp.pb({j,i});
						swap(t[i],s[j]);
						p = 1;
						break;
					}
				}
				if(!p){
					for(int j = i+1; j < n; ++j){
						if(s[j] != t[j] && t[j] == s[i]){
							swp.pb({j,j});
							swap(t[j],s[j]);
							swp.pb({j,i});
							swap(t[i],s[j]);
							p = 1;
							break;
						}		
					}
					if(!p) break;
				}
			}
		}
		if(s == t){
			cout << "Yes\n" << swp.size() << '\n';
			for(auto i : swp) cout << i.ff+1 << " " << i.ss+1 << '\n';
		}else cout << "No\n";
	}
	return 0;
}
