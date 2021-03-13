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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	stack<pair<char,int>> st;
	for(int i = n-1; i >= 0; --i){
		if(st.empty()) st.push({s[i],i});
		else{
			if(s[i] < st.top().ff) st.push({s[i],i});
			else st.push(st.top());
		}
	}
	for(int i = 0; i < n-1; ++i){
		st.pop();
		if(s[i] > st.top().ff){
			cout << "YES\n" << i+1 << ' ' << st.top().ss+1 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
