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

lli p[mx], h[mx];
string s;

void build(){
	p[0] = 1;
	h[0] = s[0];
	for(int i = 1; i < s.size(); ++i){
		p[i] = (p[i-1]*31)%mod;
		h[i] = ((h[i-1]*31) + s[i])%mod; 
	}
}

lli getkey(int l, int r){
	lli res = h[r];
	if(l > 0) res = ((res - p[r-l+1] * h[l-1]) % mod + mod)%mod;
	return res;
}

bool check(int m){
	int n = s.size();
	lli prefix = getkey(0,m-1);
	lli suffix = getkey(n-m,n-1);
	if(prefix != suffix) return false;
	for(int i = 1, j = m; j < n-1; ++i, ++j){
		if(getkey(i,j) == prefix) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	build();
	for(int i = s.size()-2; i > 0; --i){
		if(check(i)){
			forn(j,i) cout << s[j];
			cout << '\n';
			return 0;
		}
	}
	cout << "Just a legend\n";
	return 0;
}
