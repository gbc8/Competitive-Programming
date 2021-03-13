int phi(int n){
	int ret = n;
	for(int i = 2; i*i <= n; ++i){
		if(n%i == 0){
			while(n%i == 0) n /= i;
			ret -= ret/i;
		}
	}
	if(n > 1) ret -= ret/n;
	return ret;
}

void phi(int n){
	vector<int> p(n+1);
	for(int i = 0; i <= n; ++i) p[i] = i; 
	for(int i = 2; i <= n; ++i){
		if(p[i] == i){
			for(int j = i; j <= n; j += i) p[j] -= p[j]/i;
		}
	}
}
