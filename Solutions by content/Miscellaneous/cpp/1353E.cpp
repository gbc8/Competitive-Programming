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
		int n,k,all=0,ans=inf;
		string s;
		cin >> n >> k >> s;
		vector<int> c(n+10,0);
		forn(i,n) all += s[i]-'0';
		for(int i = 0; i < k; ++i){
			int d = 0;
			for(int j = i; j < n; j += k){
				if(s[j] == '1') ++d;
				else --d;
				d = max(0,d);
				ans = min(ans,all-d);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
