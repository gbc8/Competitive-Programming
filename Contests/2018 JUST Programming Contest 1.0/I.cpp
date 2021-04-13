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
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b,c,d;
		scanf("%d%d%d%d", &a,&b,&c,&d);
		if(a+c > b+d){
			puts("1");
			continue;
		}
		if(a+c < b+d){
			puts("2");
			continue;
		}
		if(a+c == b+d){
			if(c > b){
				puts("1");
				continue;
			}
			if(c < b){
				puts("2");
				continue;
			}
		}
		puts("-1");
	}
	return 0;
}
