#include <bits/stdc++.h>

using namespace std;

//O(n log(n))
int lis(int A[], int n){
	vector<int> S;
	for(int i = 0; i < n; i++){
		auto it = lower_bound(S.begin(), S.end(), A[i]);
		if(it == S.end())
			S.push_back(A[i]);
		else
			*it = A[i];
	}
	return S.size();
}

//O(n²)
void lis(vector<int> &A, int n){
	vector<int> dp(1e5,1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(A[j] < A[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
