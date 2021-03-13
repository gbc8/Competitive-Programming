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
        for(int i = 0; i < v.size(); i++)
            update(i, v[i]);
    	}
    	void insert(int pos, T v){
    		//++pos;
    		add(pos,v);
    	}
    	T get(int l, int r){
    		//++l, ++r;
    		return (query(r) - query(l-1));
    	}
};
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	sf(n);
	lli ans = 0;
	vector<pii> ord(n);
	forn(i,n){
		sf(ord[i].ff);
		ord[i].ss = i;
	}
	sort(ord.begin(),ord.end());
	vector<int> v(n),qt(n+10),out(n);
	FenwickTree<int> t(1e6+10);
	set<int> s;
	forn(i,n){
		s.insert(ord[i].ff);
		v[ord[i].ss] = s.size();
	}
	forn(i,n){
		t.insert(++qt[v[n-i-1]], 1);
		out[n-i-1] = qt[v[n-i-1]];
	}
	qt.assign(n+10,0);
	forn(i,n){
		t.insert(out[i], -1);
		ans += t.get(1,qt[v[i]]++);
	}
	printf("%lld\n",ans);
	return 0;
}
