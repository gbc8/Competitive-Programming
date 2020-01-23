#include <bits/stdc++.h>

using namespace std;

//n²
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> dp(1e5,1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(A[j] < A[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	} 
	return 0;
}
