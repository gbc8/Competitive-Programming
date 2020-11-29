#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

vector<int> adj[ms];
int dist[ms];

void bfs(int origem){
	memset(dist, -1, sizeof dist);
	queue<int> q;
	dist[origem] = 0; 
	q.push(origem);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

//toposort
//using a priority queue we can get the topo order with the lowest or greatest lexicograph order

void bfs() {
	vector<int> topo_order;
	priority_queue<int> pq;
	for(int u = 0; u < n; ++u){
		if(indegree[u] == 0) pq.push(u);
	}
	while(!pq.empty()){
		int u = pq.top();
		pq.pop();
		topo_order.push_back(u);
		for(int v : adj[u]){
			if(--indegree[v] == 0){
				pq.push(v);
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
