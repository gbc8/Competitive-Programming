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
	int n;
	sf(n);
	vector<int> a(n);
	multiset<int> s;
	forn(i,n) sf(a[i]);
	forn(i,n){
		int x;
		sf(x);
		s.insert(x);
	}
	forn(i,n){
		int m = n - a[i];
		if(s.count(m)){
			printf("0 ");
			s.erase(s.find(m));
			continue;
		}
		auto e = s.upper_bound(m);
		if(e != s.end() && (a[i]+(*s.begin()))%n > (a[i]+(*e))%n){
			printf("%d ", (a[i]+(*e))%n);
			s.erase(e);
		}else{
			printf("%d ", (a[i]+(*s.begin()))%n);
			s.erase(s.begin());
		}
	}
	return 0;
}
