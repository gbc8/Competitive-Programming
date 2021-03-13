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
	int l,r;
	scanf("%d%d", &l,&r);
	for(int i = l; i <= r; ++i){
		string nb = to_string(i);
		set<int> s;
		for(auto e : nb) s.insert(e);
		if(s.size() == nb.size()){
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
