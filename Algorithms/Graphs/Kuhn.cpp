
int n, k;
vector<vector<int>> g;
vector<int> match;
vector<bool> used;

bool kuhn(int v) {
	if(used[v]) return false;
	used[v] = true;
	for(int to : g[v]){
		if (match[to] == -1 || kuhn(mt[to])) {
			match[to] = v;
			return true;
		}
	}
	return false;
}

int main(){

	match.assign(k, -1);
	for(int v = 0; v < n; ++v){
		used.assign(n, false);
		kuhn(v);
	}

	for(int i = 0; i < k; ++i){
		if(match[i] != -1) printf("%d %d\n", match[i] + 1, i + 1);
	}
	return 0;
}
