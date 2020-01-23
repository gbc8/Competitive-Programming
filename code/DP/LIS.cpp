#include <bits/stdc++.h>

using namespace std;

//n log(n)
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
