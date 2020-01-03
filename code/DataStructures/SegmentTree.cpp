#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mx = 1e6+5;

vector<ll> el(mx), tree(4*mx);

void build(int pos, int i, int j){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2;
	
	if(i == j) tree[pos] = el[i];
	else{
		tree[pos] = 0;
		build(esq,i, mid);
		build(dir, mid+1,j);
		
		tree[pos] = tree[esq] + tree[dir];
	}
}

void update(int pos, int i, int j, int x, int value){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2;
	
	if(i == j) tree[pos] += value;
	else{
		tree[pos] += value;
		if(x <= mid) update(esq,i,mid,x,value);
		else update(dir,mid+1,j,x,value);
	}
}

int query(int pos, int i, int j, int l, int r){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2;
	int ret;
	if(j < l || i > r) ret = 0;
	else if(i>=l && j<=r) ret = tree[pos];
	else{
		ret = 0;
		ret += query(esq,i,mid,l,r);
		ret += query(dir,mid+1,j,l,r);
	} 
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
