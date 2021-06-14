vector<int> pi;

void prefix(string &s){
	int n = s.size();
	pi = vector<int>(n);
	for(int i = 1; i < n; ++i){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]) j = p[j-1];
		if(s[i] == s[j]) ++j;
		p[i] = j;
	}
}

void search(string &s, string &p){
	vector<int> occurr;
	int j = 0, n = s.size(), m = p.size();
	for(int i = 0; i < n; ++i){
		while(j > 0 && s[i] != p[j]) j = pi[j-1];
		++j;
		if(j == m){
			occurr.push_back(i-j+1);
			j = pi[j-1];
		}
	}
}
