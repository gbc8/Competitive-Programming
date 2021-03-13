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
 
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	sf(n);
	set<int> in,out;
	vector<int> v(n),ans;
	forn(i,n) sf(v[i]);
	int l = 0;
	forn(i,n){
		if(v[i] < 0){
			v[i] = -v[i]; 
			if(!in.count(v[i])){
				puts("-1");
				return 0;
			}else{
				out.insert(v[i]);
				in.erase(v[i]);
				if(in.empty()){
					ans.pb(i-l+1);
					l = -1;
					out.clear();
				}
			}
		}else{
			if(l == -1) l = i;
			if(in.count(v[i]) || out.count(v[i])){
				puts("-1");
				return 0;
			}else{
				in.insert(v[i]);
			}
		}
	}
	if(!in.empty()){
		puts("-1");
		return 0;
	}
	printf("%d\n", int(ans.size()));
	for(auto e : ans) printf("%d ", e);
	puts("");
	return 0;
}
