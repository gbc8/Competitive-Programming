#include <bits/stdc++.h>
#define ll long long int
const int mod = 1e3; 
using namespace std;

const int m = 2; // size of matrix
struct Matrix {
	ll mat[m][m];
	Matrix operator * (const Matrix &p) {
		Matrix ans;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				for(int k = ans.mat[i][j] = 0; k < m; k++)
					ans.mat[i][j] = ( ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
		return ans;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
