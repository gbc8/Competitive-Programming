#include <bits/stdc++.h>

using namespace std;

class LCA{
	private:
		vector<int> height, euler, first, tree;
		vector<bool> vs;
		int n;
		
		void dfs(vector<vector<int>> &g, int u, int h = 0){
			vs[u] = true;
			height[u] = h;
			first[u] = euler.size();
			euler.push_back(u);
			for(auto v : g[u]){
				if(!vs[v]){
					dfs(g, v, h+1);
					euler.push_back(u);
				}
			}
		}
		
		void build(int pos, int i, int j){
			if(i == j) tree[pos] = euler[i];
			else{
				int esq = 2*pos;
				int dir = 2*pos + 1;
				int mid = (i+j)/2;
				build(esq, i, mid);
				build(dir, mid+1, j);
				int l = tree[esq], r = tree[dir];
				tree[pos] = (height[l] < height[r])? l : r;
			}
		}
		
		int query(int pos, int i, int j, int l, int r){
			int esq = 2*pos;
			int dir = 2*pos + 1;
			int mid = (i+j)/2;
			if(i > r || j < l) return -1;
			else if(i >= l && j <= r) return tree[pos];
			else{
				int left = query(esq, i, mid, l, r);
				int right = query(dir, mid+1, j, l, r);
				if(left == -1) return right;
				if(right == -1) return left;
				return (height[left] < height[right])? left : right;
			}
		}
	
		
	public:
		LCA(vector<vector<int>> &g, int root = 0){
			n = g.size();
			height.resize(n);
			first.resize(n);
			euler.reserve(2*n);
			vs.assign(n,0);
			dfs(g,root);
			tree.resize(euler.size()*4);
			build(1,0,euler.size()-1);
		}
		
		int qry(int u, int v){
			int l = first[u], r = first[v];
			if(l > r) swap(l,r);
			return query(1,0,euler.size()-1,l,r);
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
