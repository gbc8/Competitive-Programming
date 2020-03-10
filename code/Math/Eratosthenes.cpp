#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int mx = 1e6+5;

bool isprime[mx];
vector<int> primes;

void sieve(){
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	primes.push_back(2);
	for(int i = 3; i <= mx; i += 2){
		if(isprime[i]){
			primes.push_back(i);
			for(int j = i+i; j <= mx; j += i) isprime[j] = 0;
		}
	} 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
