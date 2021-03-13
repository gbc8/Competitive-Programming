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

vector<lli> build(vector<lli> &p, string &s, lli c, lli mod){
	vector<lli> h(s.size());
	p[0] = 1;
	h[0] = s[0];
	for(int i = 1; i < s.size(); ++i){
		p[i] = (p[i-1]*c)%mod;
		h[i] = ((h[i-1]*c) + s[i])%mod; 
	}
	return h;
}

lli getkey(int l, int r, vector<lli> &h, vector<lli> &p, lli mod){
	lli res = h[r];
	if(l > 0) res = ((res - p[r-l+1] * h[l-1]) % mod + mod)%mod;
	return res;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	int k,n,ans=0;
	cin >> s >> t >> k;
	n = s.size();
	vector<lli> p1(s.size()), p2(s.size());
	vector<lli> h1 = build(p1,s,31,1e9+7), h2 = build(p2,s,51,1e9+11);
	map<pair<lli,lli>,bool> mp;
	vector<int> v(n);
	forn(i,n){
		v[i] = (1-(t[s[i]-'a']-'0'));
		if(i) v[i] += v[i-1];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 1; i+j <= n; ++j){
			lli key1 = getkey(i,i+j-1,h1,p1,1e9+7), key2 = getkey(i,i+j-1,h2,p2,1e9+11);
			if(!mp[{key1,key2}]){
				mp[{key1,key2}] = 1;
				int bad = v[i+j-1];
				if(i > 0) bad -= v[i-1];
				if(bad <= k) ++ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
