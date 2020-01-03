#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int mx = 1e6+5;
const int mod = 1e9+9;

ll p[mx], h[mx];
string s;

void build(){
	p[0] = 1;
	h[0] = s[0];
	for(int i = 1; i < s.size(); ++i){
		p[i] = (p[i-1]*31)%mod;
		h[i] = ((h[i-1]*31) + s[i])%mod; 
	}
}

ll getkey(int l, int r){
	ll res = h[r];
	if(l > 0) res = ((res - p[r-l+1] * h[l-1]) % mod + mod)%mod;
	return res;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
