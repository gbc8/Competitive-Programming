#include <bits/stdc++.h>
#define ll long long int

using namespace std;

template<class T>
struct FenwickTree2D{
	private:
		vector<vector<T>> bit;
		int n, m;
		
		int lso(int i){
			int l = i&(-i);
			return l;
		}
    void add(int p1, int p2, T v){
			for (int i = p1; i < n; i += lso(i)){
  		  for (int j = p2; j < m; j += lso(j)){
  		    bit[i][j] += v;
    	  }
  	  }
    }
    T query(int x, int y){
    	T ret = 0;
    	for (int i = x; i >= 0; i -= lso(i)){
    	  for (int j = y; j >= 0; j = (j & (j + 1)) - 1){
    	    ret += bit[i][j];
    	  }
    	}
    	return ret;
    }
	public:
		FenwickTree2D(int x, int y){
			n = x;
			m = y;
			bit.resize(n+10, vector<T>(m+10));
		}
		void insert(int x, int y, T v){
			add(x,y,v);
		}
		T get(int x, int y){
			query(x,y);
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
