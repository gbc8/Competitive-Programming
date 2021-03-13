#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define lli long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5,x = 1234567,y = 123456,z = 1234;
const int inf = 0x3f3f3f3f;
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	sf(n);
	for(int a = 0; a*x <= n ;++a){
		for(int b = 0; b*y <= n ;++b){
			if((n-a*x-b*y) >= 0 && (n-a*x-b*y)%z == 0){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
