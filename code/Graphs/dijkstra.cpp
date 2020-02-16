#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int ms = 1e6+5;

vector<vector<pair<int,int>>> graph;
vector<int> dist;

void dijkstra(int source){
	dist[source] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, source);
	
	while (!pq.empty()){
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for(auto e : graph[u]){
			int v = e.first, w = e.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//resize graph and dist;
	//make();
	return 0;
}
