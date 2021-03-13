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

template<class T, class T2>
class SegTree{
	private:
		int n;
		vector<T> tree;
		
		void build(vector<T2> &v, int pos, int i, int j){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			
			if(i == j) tree[pos] = v[i];
			else{
				build(v, esq, i, mid);
				build(v, dir, mid+1,j);
				
				tree[pos] = max(tree[esq],tree[dir]); //merge
			}
		}
		
		void update(int pos, int i, int j, int x, T2 value){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			
			if(i == j) tree[pos] += value;
			else{
				if(x <= mid) update(esq,i,mid,x,value);
				else update(dir,mid+1,j,x,value);
				
				tree[pos] = max(tree[esq],tree[dir]); //merge
			}
		}

		T query(int pos, int i, int j, int l, int r){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			T ret = 0; 
			if(j < l || i > r) ret = 0; //default value;
			else if(i>=l && j<=r) ret = tree[pos];
			else{
				ret = max(query(esq,i,mid,l,r),query(dir,mid+1,j,l,r)); //merge
			} 
			return ret;
		}
	public:
		SegTree(vector<T2> &v){
			n = v.size();
			tree.resize(4*n);
			build(v,1,0,n-1);
		}
		T qry(int l, int r){
			return query(1,0,n-1,l,r);
		}
		void upd(int x, T2 val){
			update(1, 0, n-1, x, val);
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	sf(t);
	while(t--){
		int n,m,k=0,d=0;
		sf(n);
		vector<int> v(n);
		forn(i,n) sf(v[i]);
		sf(m);
		vector<pii> rd(m);
		vector<int> h(m),hs(m);
		forn(i,m) scanf("%d%d", &rd[i].ff, &rd[i].ss);
		sort(rd.begin(), rd.end());
		forn(i,m) h[i] = rd[i].ff, hs[i] = rd[i].ss;
		SegTree<int,int> s(v), s2(hs);
		while(k < n){
			int l = 0, r = n-k+1, f = -1;
			while(r-l > 1){
				int mid = (l+r)/2, mxi = s.qry(k,k+mid-1);
				int p = upper_bound(h.begin(),h.end(), mxi-1)-h.begin();
				if(p < m && s2.qry(p,m) >= mid) f = mid, l = mid;
				else r = mid;
			}
			if(f == -1){
				d = -1;
				break;
			}
			k += f;
			++d;
		}
		printf("%d\n", d);
	}
	return 0;
}
