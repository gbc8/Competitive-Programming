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

int count(string &p){
	int cur = 0;
	for(int i = 0; i < p.size(); ++i){
		int id = p[i]-'a';
		if(trie[cur][id] == -1){
			return false;
		}
		cur = trie[cur][id];
	}
	return terminal[cur];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
