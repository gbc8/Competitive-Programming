#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long int
#define pii pair<ll,ll>
#define vi vector<int>
#define vli vector<ll>

using namespace std;

const int mx = 1e6+5;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	deque<ll> dq;
	set<ll> st;
	ll x;
	for(int i = 0; i < n; ++i){
		scanf("%lld", &x);
		if(st.find(x) == st.end()){
			if(st.size() == k){
				st.erase(dq.back());
				dq.pop_back();
			}
			dq.push_front(x);
			st.insert(x);
		}
	}
	printf("%d\n", int(dq.size()));
	for(auto e : dq) printf("%lld ", e); 
	return 0;
}
