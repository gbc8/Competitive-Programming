#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int inf = 0x3f3f3f3f;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	scanf("%d%d", &n,&m);
	vector<int> v(n),ans(n,-1);
	deque<pii> s;
	deque<int> dq;
	forn(i,n) sf(v[i]);
	forn(i,m){
		int t,r;
		scanf("%d%d",&t,&r);
		while(!s.empty() && s.back().ff <= r) s.pop_back();
		s.pb({r,t});
	}
	int k = n;
	while(k > s[0].ff) ans[k-1] = v[k-1], --k;
	for(int i = 0; i < s[0].ff; ++i) dq.pb(v[i]);
	sort(dq.begin(),dq.end());
	forn(i,s.size()){
		if(i){
			int l = s[i-1].ff-1;
			while(l > s[i].ff){
				if(s[i-1].ss == 1){
					ans[l-1] = dq.back();
					dq.pop_back();
				}else{
					ans[l-1] = dq.front();
					dq.pop_front(); 
				}
				--l;
			}
		}
		if(s[i].ss == 1){
			ans[s[i].ff-1] = dq.back();
			dq.pop_back();
		}else{
			ans[s[i].ff-1] = dq.front();
			dq.pop_front();
		}
	}
	k = s.back().ff-1;
	while(k > 0){
		if(s.back().ss == 1){
			ans[k-1] = dq.back();
			dq.pop_back();
		}else{
			ans[k-1] = dq.front();
			dq.pop_front();
		}
		--k;
	}
	forn(i,n) printf("%d ", ans[i]);
	puts("");
	return 0;
}
 
