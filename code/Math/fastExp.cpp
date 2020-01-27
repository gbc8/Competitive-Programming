#include <bits/stdc++.h>
#define ll long long int
const int mod = 5;

using namespace std;

ll fexp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans * a % mod; 
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//define mod
	return 0;
}
