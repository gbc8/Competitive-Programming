#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,ans = 0;
	sf(n);
	multiset<int> v;
	vector<int> out(n);
	forn(i,n) {
		int x;
		sf(x);
		v.insert(x);
	}
	for(int i = 1; i < n; i += 2){
		out[i] = *v.begin();
		v.erase(v.begin());
	}
	for(int i = 0; i+1 < n; i += 2){
		auto e = v.upper_bound(out[i+1]);
		if(e == v.end()) break;
		out[i] = *e;
		v.erase(e);
	}
	forn(i,n){
		if(out[i] == 0){
			out[i] = *v.begin();
			v.erase(v.begin());
		}
	}
	for(int i = 1; i < n; ++i){
		if(i == n-1) break;
		if(out[i] < out[i-1] && out[i] < out[i+1]) ++ans;
	}
	printf("%d\n", ans);
	for(auto e : out) printf("%d ", e);
	puts("");
	return 0;
}
