//check

int biggest(int l, int r){
	int m;
	while(r-l > 1){
		m = (l+r)/2;
		if(check(m)) l = m;
		else r = m;
	}
	return check(r)? r : l;
}

int smallest(int l, int r){
	int m;
	while(l < r){
		m = (l+r)/2;
		if(check(m)) r = m;
		else l = m+1;
	}
	return l;
}
