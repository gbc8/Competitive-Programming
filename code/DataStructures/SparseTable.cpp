#include <bits/stdc++.h>
#define ll long long int

using namespace std;

template<class T>
class SparseTable{
	private:
		vector<vector<T>> table;
		vector<int> lg;
	public:
		void build(vector<T> v){
			int n = v.size();
			lg.resize(n+1);
			lg[1] = 0;
			for(int i = 2; i <= n; ++i) lg[i] = lg[i/2] + 1;
			table.resize(n+1, vector<T>(lg[n]+1));
			for(int i = 0; i < n; ++i) table[i][0] = v[i];
			for(int j = 0; j < lg[n]; ++j){
				for(int i = 0; i + (1 << j) < n; ++i){
					table[i][j+1] = max(table[i][j], table[i+(1 << j)][j]);
				}
			}
		}
		T query(int l, int r){
			int j = lg[r-l+1];
			return max(table[l][j], table[r - (1 << j) + 1][j]);
		}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//scanf("%d", &n);
	return 0;
}
