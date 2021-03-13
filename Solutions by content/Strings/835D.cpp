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
int dp[5100][5100];
int n;
 
vector<lli> build(string &s){
	vector<lli> h(s.size());
	p[0] = 1;
	h[0] = s[0];
	for(int i = 1; i < s.size(); ++i){
		p[i] = (p[i-1]*31)%mod;
		h[i] = ((h[i-1]*31) + s[i])%mod; 
	}
	return h;
}
 
lli getkey(int l, int r, vector<lli> &h){
	lli res = h[r];
	if(l > 0) res = ((res - p[r-l+1] * h[l-1]) % mod + mod)%mod;
	return res;
}
 
int degree(int l, int r){
	if(l == r) return 1;
	if(dp[l][r] != -1) return dp[l][r];
	int sz = r-l+1;
	int x = degree(l,l+sz/2-1), y = degree(r-sz/2 + 1,r);
	if(x == y && getkey(l,r,h1) == getkey(n-r-1,n-l-1,h2)) return dp[l][r] = x+1;
	return dp[l][r] = 0;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	t = s;
	n = s.size();
	reverse(t.begin(),t.end());
	p.resize(n);
	h1 = build(s), h2 = build(t);
	vector<int> ans(n+1);
	vector<pii> pl;
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			if(getkey(i,j,h1) == getkey(n-j-1, n-i-1,h2)) ++ans[degree(i,j)];
		}
	}
	int p = 0;
	for(int i = n; i > 0; --i){
		int x = ans[i];
		ans[i] += p;
		p += x;
	}
	forn(i,n) cout << ans[i+1] << " ";
	cout << '\n';
	return 0;
}
