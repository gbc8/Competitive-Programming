#include <bits/stdc++.h>
#define ll long long int
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
				
				tree[pos] = tree[esq] + tree[dir]; //merge
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
				
				tree[pos] = tree[esq] + tree[dir]; //merge
			}
		}

		T query(int pos, int i, int j, int l, int r){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			T ret; 
			if(j < l || i > r) ret = 0; //default value;
			else if(i>=l && j<=r) ret = tree[pos];
			else{
				ret = query(esq,i,mid,l,r) + query(dir,mid+1,j,l,r); //merge
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
	return 0;
}
