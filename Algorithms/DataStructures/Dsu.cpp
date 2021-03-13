#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

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
		
		int find(int a){
			if(p[a] != a) p[a] = find(p[a]);
			return p[a];
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
	return 0;
}
