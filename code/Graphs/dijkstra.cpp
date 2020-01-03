#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

const int ms = 1e6+5;

vector<vector<pair<int,int>>> graph;
vector<int> dist;

void dijkstra(int origin){
	d[origin] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq; //min priority queue
	pq.push({origin,0});
	
	while(!pq.empty()){
		ii u = pq.top();
		pq.pop();
		auto e = graph[u.first];
		for(auto &j : e){
			if((u.second + j.second) < d[j.first]){
				dist[j.first] = u.second + j.second;
				pq.push({j.first, dist[j.first]});
			}
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
