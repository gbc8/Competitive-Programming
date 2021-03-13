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

int n,m,ans = 0;

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
		
		void clear(int n){
			make(n);
		}
		int find(int a){
			if(p[a] != a) p[a] = find(p[a]);
			return p[a];
		}
		
		int get(int a){
			return sz[find(a)];
		}
		
		void join(int a, int b){
			a = find(a);
			b = find(b);
			if(a!=b){
				if(sz[a] > sz[b]){
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
	scanf("%d%d", &n,&m);
	vector<set<int>> g(n+1);
	vector<int> vs(n+1);
	dsu d(n);
	forn(i,m){
		int a,b;
		scanf("%d%d", &a,&b);
		g[a].insert(b);
		g[b].insert(a);
	}
	int x = 0;
	for(int i = 1; i <= n; ++i){
		if(d.find(i) == i) ++x;
	}
	if(x>1){
		puts("0");
		return 0;
	}
	d.clear(n);
	int v = 0, mni = inf;
	for(int i = 1; i < n; ++i){
		if(mni > g[i].size()){
			v = i;
			mni = g[i].size();
		}
	}
	vs[v] = 1;
	for(int i = 1; i <= n; ++i){
			
	}
	return 0;
}
