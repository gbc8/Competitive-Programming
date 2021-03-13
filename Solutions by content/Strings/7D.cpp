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

string s,t;
vector<lli> p,h1,h2;
vector<int> mp(5*1e6+10,0);
int n;

void build(){
	p[0] = 1;
	h1[0] = s[0];
	h2[0] = t[0];
	for(int i = 1; i < s.size(); ++i){
		p[i] = (p[i-1]*31)%mod;
		h1[i] = ((h1[i-1]*31) + s[i])%mod; 
		h2[i] = ((h2[i-1]*31) + t[i])%mod;
	}
}

lli getkey(int l, int r, vector<lli> &h){
	lli res = h[r];
	if(l > 0) res = ((res - p[r-l+1] * h[l-1]) % mod + mod)%mod;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	t = s;
	n = s.size();
	reverse(t.begin(),t.end());
	p.resize(n), h1.resize(n), h2.resize(n);
	build();
	int ans = 1;
	mp[0] = 1;
	for(int i = 1; i < n; ++i){
		if(getkey(0,i,h1) == getkey(n-i-1,n-1,h2)){
			ans += (mp[i] = 1+mp[(i+1)/2-1]);
		}
	}
	cout << ans << '\n';
	return 0;
}
