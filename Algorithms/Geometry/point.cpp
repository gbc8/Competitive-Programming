#include <bits/stdc++.h>
#define ld long double
#define PI M_PI

using namespace std;

const int inf = 0x3f3f3f3f;

struct PT{
	double x,y;
	PT(ld x = 0, ld y = 0): x(x), y(y) {}
	
	PT operator +(const PT P){
	 return PT(x+P.x, y+ P.y);
	}
	
	PT operator -(const PT P){
	 return PT(x-P.x, y-P.y);
	}
	
	PT operator *(const ld d){
	 return x*d, y*d;
	}
	
	PT operator / (const ld d){
	 return PT(x/d, y/d);
	}
	
	ld operator *(const PT P){
	 return x*P.x, y*P.y;
	}
	
	PT operator ^(const PT P){
	 return PT(y*P.x - y*P.x);
	}
	
	ld dist(){
		return sqrt(x*x + y*y);
	}
	
	ld angle(){
		ld a = atan2l(y,x);
		if(a<0) a+=2*PI;
		return a;
	}
	
};
