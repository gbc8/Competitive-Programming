#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mx = 1e6+5;

ll ft[mx];

ll lso(ll i){
	ll l = i & (-i);
	return l;
}

void update(int pos, int val){
	if(pos == 0) return;
	ft[pos] += val;
	for(pos = pos+lso(pos); pos <= m; pos += lso(pos)){
		ft[pos] += val;
	}
}

ll query(int pos){
	ll ans = ft[pos];
	for(pos = pos-lso(pos); pos > 0; pos -= lso(pos)){
		ans += ft[pos];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//define m
	return 0;
}
