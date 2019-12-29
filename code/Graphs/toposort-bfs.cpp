#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

//using a priority queue we can get the topo order with the lowest or greatest lexicograph order

void bfs() {
	vector<int> topo_order;
	priority_queue<int> PQ;
	for (int u = 0; u < n; ++u) {
		if (indegree[u] == 0) PQ.push(u);
	}
	while (!PQ.empty()) {
		int u = PQ.top();
		PQ.pop();
		topo_order.push_back(u);
		for (int v : adj[u]) {
			if (--indegree[v] == 0) {
				PQ.push(v);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//define ms;
	return 0;
}
