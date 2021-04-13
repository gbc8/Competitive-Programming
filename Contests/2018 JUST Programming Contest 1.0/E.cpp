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
		int n,x,y;
		scanf("%d%d%d", &n,&x,&y);
		int id = -1, km = inf, c = 0;
		int d,m;
		forn(i,n){
			scanf("%d%d", &d,&m);
			if(d <= x && m >= y){
				if(d < km){
					km = d;
					c = m;
					id = i+1;
				}else if(d == km){
					if(m > c){
						km = d;
						c = m;
						id = i+1;
					}
				}
			}
		}
		printf("%d\n", id);
	}
	return 0;
}
