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

lli gcd(lli a, lli b){
	if(b == 0) return a; 
	return gcd(b, a % b); 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,e=0,o=0;
	scanf("%d%d", &n,&m);
	vector<lli> x(n),p(m);
	lli g = 0;
	forn(i,n){
		scanf("%lld", &x[i]);
		if(i) g = gcd(g, x[i]-x[i-1]);
	}
	int j = -1;
	forn(i,m){
		scanf("%lld", &p[i]);
		if(g%p[i] == 0)	j = i+1;
	}
	if(j != -1) printf("YES\n%lld %d\n", x[0], j);
	else puts("NO");
	return 0;
}
