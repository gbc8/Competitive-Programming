#include <bits/stdc++.h> 

using namespace std;

const int ms = 1e6+5;

vector<int> sz, p;

void make(){
  for(int i = 0; i <= n; ++i){
    sz[i] = 1;
    p[i] = i;
  }
}

int find(int a){
  if(p[a] != a) p[a] = find(p[a]);
  return p[a];
}

void uniun(int a, int b){
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//resize sz;
	return 0;
}
