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
	int n;
	cin >> n;
	bool ans = false;
	while(n--){
		string s;
		int a,b;
		cin >> s >> a >> b;
		if(a < b){
			if(a >= 2400) ans = true;
		}
	}
	if(ans) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
