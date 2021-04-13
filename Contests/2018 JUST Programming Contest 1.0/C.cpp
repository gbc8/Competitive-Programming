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
vector<int> p(mx);
void phi(int n = mx){
	for(int i = 0; i <= n; ++i) p[i] = i; 
	for(int i = 2; i <= n; ++i){
		if(p[i] == i){
			for(int j = i; j <= n; j += i) p[j] -= p[j]/i;
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	phi(mx);
	int t;
	sf(t);
	while(t--){
		int m;
		sf(m);
		printf("%lld\n", (m-1)*1ll*p[m]);
	}
	return 0;
}
