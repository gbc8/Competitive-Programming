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
	int n,cnt = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == '8')	++cnt;
	}
	if(cnt <= (n-11)/2) cout << ("NO\n");
	else{
		int d = (n-11)/2;
		for(int i = 0; i < n; ++i){
			if(s[i] == '8'){
				if(d) --d;
				else{
					if(i+10 >= n){
						cout << "NO\n";
						return 0;
					}
					break;
				}
			}
		}
		cout << "YES\n";
	}
	return 0;
}


