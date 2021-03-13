#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;

const int inf = 0x3f3f3f;
vector<vector<int>> dist;

void floyd(){
   for(int k = 1; k <= n; k++) {
 		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//resize dist;
	return 0;
}
