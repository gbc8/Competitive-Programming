#include <bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;

using namespace std;

struct edge{
  long long u,v, cost;
  bool operator <(edge b){
    return cost <b.cost;
  }
};

vector<ll> sz(mx), p(mx);
vector<edge> edg;
vector<edge> mst;
ll total;

void make(){
  for(int i = 1; i <= n; ++i){
    sz[i] = 1;
    p[i] = i;
  }
}

int find(ll a){
  if(p[a] != a) p[a] = find(p[a]);
  return p[a];
}

void uniun(ll a, ll b){
  a = find(a);
  b = find(b);
  if(a!=b){
    if(sz[a] > sz[b]){
      p[b] = a;
      sz[a] += sz[b];
    }else{
      p[a] = b;
      sz[b] += sz[a]; 
    }
  }
}


void ksk(){
  sort(edg.begin(), edg.end());
  total = 1;
  for(int i = 1; i <= m; ++i){
    if(find(edg[i].u) != find(edg[i].v)){
      uniun(edg[i].u, edg[i].v);
      mst.push_back(edg[i]);
      total += edg[i].cost;
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//resize arrays;
	//make();
	return 0;
}
