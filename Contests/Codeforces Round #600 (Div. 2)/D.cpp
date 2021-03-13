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

class dsu{
	private:
		vector<int> sz, p;
		
		void make(int n){
			sz.resize(n+5), p.resize(n+5);
			for(int i = 0; i <= n; ++i){
				sz[i] = 1;
				p[i] = i;
			}
		}
		
	public:
		dsu(int n){
			make(n);
		}
		
		int find(int a){
			if(p[a] != a) p[a] = find(p[a]);
			return p[a];
		}
		
		void join(int a, int b){
			a = find(a);
			b = find(b);
			if(a!=b){
				if(a > b){
				  p[b] = a;
				  sz[a] += sz[b];
				}else{
				  p[a] = b;
				  sz[b] += sz[a]; 
				}
			}
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans = 0;
	scanf("%d%d", &n,&m);
	dsu d(n);
	forn(i,m){
		int a,b;
		scanf("%d%d", &a,&b);
		d.join(a,b);
	}
	for(int i = 1; i <= n; ){
		int l = d.find(i), it = i+1;
		while(it < l){
			if(d.find(it) != d.find(i)){
				++ans;
				d.join(it,i);
			}
			++it;
		}
		i = it;
	}
	printf("%d\n", ans);
	return 0;
}
