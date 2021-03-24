#include <bits/stdc++.h>

using namespace std;

const int ms = 20;
const int inf = 0x3f3f3f3f;

int v, dp[ms][1 << ms], graph[ms][ms], n;

int solve(int pos, int visited){
	if(visited == (1<<n) - 1) return 0;
	int ans = dp[pos][visited];
	if(~ans) return ans;
	ans = inf;
	for(int i = 0; i < n; i++){
		if(!(visited & (1<<i))){
			ans = min(ans, graph[pos][i] + solve(i, visited|(1<<i)));
		}
	}
	return dp[pos][visited] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
