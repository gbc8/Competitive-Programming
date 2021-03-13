#include <bits/stdc++.h>
#define ll long long int
using namespace std;

template<class T>
struct FenwickTree{
	private:
		vector<T> bit;
  	int n;
	
		int lso(int i){
			int l = i&(-i);
			return l;
		}
		void add(int pos, T val){
			if(pos == 0) return;
			bit[pos] += val;
			for(pos = pos+lso(pos); pos <= n; pos += lso(pos)){
				bit[pos] += val;
			}
		}
		T query(int pos){
			T ans = bit[pos];
			for(pos = pos-lso(pos); pos > 0; pos -= lso(pos)){
				ans += bit[pos];
			}
			return ans;
		}
		
		public:
			FenwickTree(int x) {
		  	n = x;
		    bit.assign(n+10, 0);
		  }
		  FenwickTree(vector<T> v) : FenwickTree(v.size()){
        for (int i = 0; i < v.size(); i++)
            update(i, v[i]);
    	}
    	void insert(int pos, T v){
    		add(pos,v);
    	}
    	int get(int l, int r){
    		return (query(r) - query(l-1));
    	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
