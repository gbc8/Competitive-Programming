#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int mx = 1e6+5;
 
ll ft1[mx],ft2[mx] ,v[mx],inv[mx], v1[mx];
map<ll,ll> id;
ll t,n,m,r = 0, p,y;
 
ll lso(ll i){
	ll l = i & (-i);
	return l;
}
 
void ajuste(ll *ft, ll pos, ll val){
	if(pos == 0) return;
	ft[pos] += val;
	for(pos = pos+lso(pos); pos <= mx; pos += lso(pos)){
		ft[pos] += val;
	}
}
 
ll intervalo(ll *ft,ll pos){
	ll ans = ft[pos];
	for(pos = pos-lso(pos); pos > 0; pos -= lso(pos)){
		ans += ft[pos];
	}
	return ans;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%lld", &n);
	memset(ft1, 0, sizeof(ft1));
	memset(ft2, 0, sizeof(ft2));
	ll vl = 1;
	for(ll i = 1; i <= n; ++i)	{
		scanf("%lld", &v[i]);
		id[v[i]] = i;
	}
	
	for(auto e : id) v1[e.second] = vl++;
	
	for(ll i = n; i > 0; --i){
		inv[i] = intervalo(ft1,v1[i]);
		ajuste(ft1,v1[i], 1);
	}
	
 
	for(ll i = n; i > 0; --i){
		r += intervalo(ft2,v1[i]);
		ajuste(ft2,v1[i]+1,inv[i]);
	}
	printf("%lld\n", r);
	return 0;
}
