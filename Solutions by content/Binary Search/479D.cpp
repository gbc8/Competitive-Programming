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
	int n,l,x,y;
	scanf("%d%d%d%d", &n,&l,&x,&y);
	vector<int> v(n);
	forn(i,n) sf(v[i]);
	int px = 0, py = 0;
	forn(i,n){
		px |= binary_search(v.begin(), v.end(), v[i]+x);
		px |= binary_search(v.begin(), v.end(), v[i]-x);
		py |= binary_search(v.begin(), v.end(), v[i]+y);
		py |= binary_search(v.begin(), v.end(), v[i]-y);
	}
	if(px && py) puts("0");
	else if(px || py){
		puts("1");
		int k;
		if(px) k = y;  
		else k = x;
		printf("%d\n", k);
	}else{
		forn(i,n){
			int b = v[i]-x;
			int c = v[i]+x;
			if(b > 0 && binary_search(v.begin(), v.end(), b-y)){
				printf("1\n%d\n", b);
				return 0;
			}
			if(b > 0 && binary_search(v.begin(), v.end(), b+y)){
				printf("1\n%d\n", b);
				return 0;
			}
			if(c < l && binary_search(v.begin(), v.end(), c-y)){
				printf("1\n%d\n", c);
				return 0;
			}
			if(c < l && binary_search(v.begin(), v.end(), c+y)){
				printf("1\n%d\n", c);
				return 0;
			}
		}
		forn(i,n){
			int b = v[i]-y;
			int c = v[i]+y;
			if(b > 0 && binary_search(v.begin(), v.end(), b-x)){
				printf("1\n%d\n", b);
				return 0;
			}
			if(b > 0 && binary_search(v.begin(), v.end(), b+x)){
				printf("1\n%d\n", b);
				return 0;
			}
			if(c < l && binary_search(v.begin(), v.end(), c-x)){
				printf("1\n%d\n", c);
				return 0;
			}
			if(c < l && binary_search(v.begin(), v.end(), c+x)){
				printf("1\n%d\n", c);
				return 0;
			}
		}
		printf("2\n%d %d\n", x,y);
	}
	return 0;
}
