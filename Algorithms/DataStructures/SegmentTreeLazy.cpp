#include <bits/stdc++.h>
#define ll long long

using namespace std;

template<class T, class T2>
class SegTree{
	private:
		int n;
		vector<T> tree;
		vector<T> lazy;
		
		void build(vector<T2> &v, int pos, int i, int j){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			if(i == j) tree[pos] = v[i];
			else{
				build(v, esq, i, mid);
				build(v, dir, mid+1,j);
				
				tree[pos] = tree[esq] + tree[dir]; //merge
			}
		}
		
		void update(int pos, int i, int j, int l, int r, T2 val){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			
			if(lazy[pos]){
				tree[pos] += (j-i+1)*lazy[pos];
				if(i != j){
					lazy[esq] += lazy[pos];
					lazy[dir] += lazy[pos]; 
				}
				lazy[pos] = 0;
			}
			if(i > r || j < l) return;
			else if(i >= l && j <= r){
				tree[pos] += (j-i+1)*val;
				if(i != j){
					lazy[esq] += val;
					lazy[dir] += val;
				}
			}else{
				update(esq, i, mid, l, r, val);
				update(dir, mid+1, j, l, r, val);
				tree[pos] = tree[esq] + tree[dir];
			}
		}
		
		T query(int pos, int i, int j, int l, int r){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			T ret; //Put default value
			if(j < l || i > r) {
				ret = 0;
				return ret;
			}
			if(lazy[pos]){
				tree[pos] += (j-i+1) * lazy[pos]; 
				if(i != j){
					lazy[esq] += lazy[pos];
					lazy[dir] += lazy[pos]; 
				}
				lazy[pos] = 0;
			}
			if(i >= l && j <= r) return tree[pos];
			else{
				ret += query(esq, i, mid, l, r); 
				ret += query(dir, mid+1, j, l, r);
			}
			return ret;
		}
		
	public:
		SegTree(vector<T2> &v){
			n = v.size();
			tree.resize(4*n);
			lazy.resize(4*n,0); 
			build(v,1,0,n-1);
		}
		T qry(int l, int r){
			return query(1, 0, n-1, l, r);
		}
		void upd(int l, int r, T2 val){
			update(1, 0, n-1, l, r, val);
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
