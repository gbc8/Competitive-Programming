#include <bits/stdc++.h> 

using namespace std; 

vector<vector<int>> g;
vector<bool> d, c;

bool dfs(int v){
	
	for (int u : g[v]){
		if (!d[u]){
			d[u] = true;
			c[u] = !c[v];

			if (!dfs(u)) return false;
		
		}else if (c[v] == c[u])	return false;
	}
	return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//resize g,d,c
	return 0;
}
