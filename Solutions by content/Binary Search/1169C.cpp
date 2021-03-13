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
int n,m;
vector<int> v;

bool check(int x){
	int ai = 0;
	forn(i,n){
		if((v[i] + x) >= m){
			if((v[i]+x)%m >= ai) continue; 
		}
		if((v[i]+x) < ai) return false;
		ai = max(ai,v[i]);
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n,&m);
	v.resize(n);
	forn(i,n) sf(v[i]);
	int l = 0, r = m;
	while(l < r){
		int x = (l+r)/2;
		if(check(x)) r = x;
		else l = x+1;
	}
	printf("%d\n", l);
	return 0;
}
