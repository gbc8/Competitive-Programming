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
 
template<class T, class T2>
class SegTree{
	private:
		int n;
		vector<T> tree;
		
		void build(vector<T2> &v, int pos, int i, int j){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			
			if(i == j) tree[pos] = {v[i],i};
			else{
				build(v, esq, i, mid);
				build(v, dir, mid+1,j);
				
				tree[pos] = max(tree[esq], tree[dir]); //merge
			}
		}
		
		void update(int pos, int i, int j, int x, T2 val){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			
			if(i == j) tree[pos] = {val, x};
			else{
				if(x <= mid) update(esq,i,mid,x, val);
				else update(dir,mid+1,j,x, val);
				
				tree[pos] = max(tree[esq], tree[dir]); //merge
			}
		}
 
		T query(int pos, int i, int j, int l, int r){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			T ret = {-1,-1}; 
			if(j < l || i > r) ret = {-1,-1}; //default value;
			else if(i>=l && j<=r) ret = tree[pos];
			else{
				ret = max(query(esq,i,mid,l,r), query(dir,mid+1,j,l,r)); //merge
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
	int n;
	sf(n);
	vector<int> v(3*n), ans(3*n,-1);
	forn(i,n) {
		sf(v[i]);
		v[i+n] = v[i];
		v[i+2*n] = v[i];	
	}
	SegTree<pii,int> st(v);
	queue<int> q;
	q.push(0);
	for(int i = 1; i < 3*n; ++i){
		while(st.qry(0,i-1).ff > 2*v[i]){
			auto e = st.qry(0,i-1);
			while(!q.empty() && q.front() <= e.ss) {
				ans[q.front()] = i-q.front();
				q.pop();
			}
			st.upd(e.ss,-1);
		}
		if(ans[i] == -1) q.push(i);
		if(q.front() >= n) break;
	}
	forn(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
	return 0;
}

