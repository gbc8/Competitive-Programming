#include <bits/stdc++.h>

using namespace std;

int a, b, d, k;
int dp[19][19][2];

int solve(string &number, int pos, int qnt, int smaller) {
	if(qnt > k) return 0;
	if(pos == number.size() && smaller) return (qnt == k);
	if(dp[pos][qnt][smaller] != -1) return dp[pos][qnt][smaller];
	int ans = 0;
	int lim = (smaller == 0) ? number[pos]-'0' : 9;
	for(int digit = 0; digit <= lim; digit++){
		int new_smaller = smaller || (digit < lim);
		int new_qnt = qnt;
		if(digit == d) new_qnt++;
		ans += solve(number, pos + 1, new_qnt, new_smaller);
	}
	return dp[pos][qnt][smaller] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
