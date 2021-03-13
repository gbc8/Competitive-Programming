#include <bits/stdc++.h>

using namespace std;

const int ms = 1e6+5;

int trie[ms][3], terminal[ms], z;

void init(){
	memset(trie[0], -1, sizeof(trie[0]));
	memset(terminal, 0, sizeof(terminal));
	z = 1;
}

void insert(string &p){
	int cur = 0;
	for(int i = 0; i < p.size(); ++i){
		int id =	p[i]-'a';
		if(trie[cur][id] == -1){
			memset(trie[z], -1, sizeof(trie[z]));
			trie[cur][id] = z++;
		}
		cur = trie[cur][id];
	}
	++terminal[cur];
}

int count(string &p, int curr, int flag, int sz){
	if(flag > 1 || curr == -1) return 0;
	if(sz == p.size() && flag) return terminal[curr];
	int a = 0, b = 0, c = 0;
	int id = p[sz]-'a';
	a += count(p, trie[curr][0], flag + (id != 0), sz+1);
	b += count(p, trie[curr][1], flag + (id != 1), sz+1);
	c += count(p, trie[curr][2], flag + (id != 2), sz+1);
	return ((a | b) | c);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	init();
	string s;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> s;
		insert(s);
	}
	for(int i = 0; i < m; ++i){
		cin >> s;
		int x = count(s,0,0,0);
		if(x) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
