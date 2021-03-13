#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int mx = 1e6+9;
int n,m,a,b,c;
 
ll v[mx], tree[4*mx],check[4*mx], divs[mx];
 
void fastp(){
	memset(divs, 0, sizeof(divs));
	memset(check, 0, sizeof(check));
	for(ll i = 1; i <= mx; i += 1){
		for(ll j = i; j <= mx; j += i) ++divs[j];
	}
}
 
void build(int pos, int i, int j){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2;
	
	if(i == j) {
		tree[pos] = v[i];
		if(tree[pos] <= 2) check[pos] = 1;
	} else{
		tree[pos] = 0;
		build(esq,i, mid);
		build(dir, mid+1,j);
		
		tree[pos] = tree[esq] + tree[dir];
		if(check[esq] == 1 && check[dir] == 1) check[pos] = 1;
	}
}

ll query(int pos, int i, int j, int l, int r){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2;
	ll ret;
	if(j < l || i > r) ret = 0;
	else if(i>=l && j<=r) ret = tree[pos];
	else{
		ret = 0;
		ret += query(esq,i,mid,l,r);
		ret += query(dir,mid+1,j,l,r);
	} 
	return ret;
}
 
void rep(int pos, int i, int j, int l, int r){
	int esq = 2*pos;
	int dir = 2*pos + 1;
	int mid = (i+j)/2; 
	if(check[pos] == 1 || (j < l || i > r)) {
		return;
	}
	if(i == j && (i>=l && j<=r)) {
		tree[pos] = divs[tree[pos]];
		if(tree[pos] <= 2) check[pos] = 1;
	}else{
		rep(esq,i, mid,l,r);
		rep(dir, mid+1,j,l,r);
		tree[pos] = tree[esq] + tree[dir];
		if(check[esq] == 1 && check[dir] == 1) check[pos] = 1;
	}

}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n,&m);
	memset(tree, 0, sizeof(tree));
	for(int i = 0; i < n;++i) scanf("%lld", &v[i]);
	build(1,0,n-1);
	fastp();
	while(m--){
		scanf("%d%d%d", &a,&b,&c);
		if(a == 2)printf("%lld\n", query(1,1,n,b,c));
		else rep(1,1,n,b,c);
	}
	return 0;
}
