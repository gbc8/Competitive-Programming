#include <bits/stdc++.h> 

using namespace std; 

vector<vector<int>> g;
vector<bool> d, c;

bool dfs(int v){
	d[v] = true;
	for(int u : g[v]){
		if(!d[u]){
			c[u] = !c[v];
			if(!dfs(u)) return false;
		}else if(c[v] == c[u])	return false;
	}
	return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
