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
 
bool check(ll y){
	if(y < 11) return 0;
	string s1 = "";
	while(y){
		s1 += y%10+'0';
		y /= 10;
	}
	reverse(s1.begin(), s1.end());
	int n = s1.size();
	string s = s1.substr(0, (n+1)/2);
	string t = s1.substr((n+1)/2);
	ll a = stoll(s), b = stoll(t);
	return __gcd(a,b)==1;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		ll a, b, ans = -1;
		scanf("%lld%lld", &a, &b);
		for(ll i = b; i >= a; --i){
			if(check(i)){
				ans = i;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

