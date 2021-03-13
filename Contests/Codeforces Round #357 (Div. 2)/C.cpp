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
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<string, int>> ans;
	while(n--){
		string s;
		int x;
		cin >> s;
		if(s[0] == 'i'){
			cin >> x;
			pq.push(x);
		}else if(s[0] == 'g'){
			cin >> x;
			if(pq.empty()){
				ans.pb({"insert",x});
				pq.push(x);
			}else{
				while(!pq.empty() && pq.top() < x){
					pq.pop();
					ans.pb({"removeMin",-1});
				}
				if(pq.empty() || pq.top() > x){
					pq.push(x);
					ans.pb({"insert", x});
				}
			}
		}else if(s[0] == 'r'){
			if(!pq.empty()) pq.pop();
			else ans.pb({"insert", 5});
			
		}
		ans.pb({s,x});
	}
	cout << ans.size() << '\n';
	for(auto e : ans){
		cout << e.ff;
		if(e.ff != "removeMin") cout << ' ' << e.ss << "\n";
		else cout << '\n';
	}
	return 0;
}
