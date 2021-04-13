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
 
int n,m,k,x,y,z,t, ext = -1, stf;
int firsts[50], wa[50][50], og[50];
pii sld, rl;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n,&m,&k);
		vector<pair<pii, pii>> v(k);
		ext = -1, stf = -1;
		memset(firsts, -1, sizeof(firsts));
		memset(wa, 0, sizeof(wa));
		memset(og, 0, sizeof(og));
		sld = {0, -1}, rl = {0, -1};
		for(int i = 0; i < k; ++i) {
			int a,b;
			scanf("%d%d%d%d:%d", &v[i].ff.ff, &v[i].ff.ss, &v[i].ss.ff, &a, &b);
			v[i].ss.ss = a*60+b;
		}
		sort(v.begin(), v.end(), [&](pair<pii, pii> &a, pair<pii, pii> &b){
				return (a.ss.ss < b.ss.ss);
		});
		for(int i = 0; i < k; ++i){
			x = v[i].ff.ff; y = v[i].ff.ss; z = v[i].ss.ff;
			if(!z) ++wa[y][x];
			else {
				if(firsts[x] == -1) firsts[x] = y;
				if(ext == -1) ext = y;
				if(wa[y][x] == 0) ++og[y];
				stf = y;
				if(og[y] > sld.ss || (og[y]==sld.ss && y < sld.ff)) sld = {y, og[y]};
				if(wa[y][x] > rl.ss || (wa[y][x] == rl.ss && y < rl.ff)) rl = {y, wa[y][x]};
			}
		}
		for(int i = 1; i <= n; ++i) {
			printf("%d", firsts[i]);
			if(i != n) printf(" ");
		}
		puts("");
		printf("%d %d %d %d\n", ext, stf, sld.ff, rl.ff);
	}
	return 0;
}
