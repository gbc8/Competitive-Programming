int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool get(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if(c%g) return false;

    x0 *= c/g;
    y0 *= c/g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

void shift(int &x, int &y, int a, int b, int q){
	x += q*b;
	y -= q*a;
}

int get_all(int a, int b, int c, int minx, int maxx, int miny, int maxy){
	int x,y,g;
	if(!get(a,b,c,x,y,g)) return 0;
	a /= g;
	b /= g;
	
	int sa = (a>0)? 1 : -1;
	int sb = (b>0)? 1 : -1;
	
	shift(x, y, a, b, (minx-x)/b);
	if(x < minx) shift(x, y, a, b, sb);
	if(x > maxx) return 0;
	int l1 = x;
	
	shift(x, y, a, b, (maxx-x)/b);
	if(x > maxx) shift(x, y, a, b, -sb);
	int r1 = x;
	
	shift(x, y, a, b, -(miny-y)/a);
	if(y < miny) shift(x, y, a, b, -sa);
	if(y > maxy) return 0;
	int l2 = x;
	
	shift(x, y, a, b, -(maxy-y)/a);
	if(y > maxy) shift(x, y, a, b, sa);
	int r2 = x;
	
	if(l2 > r2) swap(l2,r2);
	
	int l = max(l1,l2);
	int r = min(r1,r2);
	if(l > r) return 0;
	return ((r-l)/abs(b) + 1);
}
