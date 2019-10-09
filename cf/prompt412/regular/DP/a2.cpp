#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

struct Matrix {
	ll data[2][2];
	Matrix operator * (const Matrix &rhs) const {
		Matrix ret;
		for (int i=0; i<2; ++i) {
			for (int j=0; j<2; ++j) {
				ret.data[i][j] = 0;
				for (int k=0; k<2; ++k) {
					ret.data[i][j] += data[i][k] * rhs.data[k][j];
					ret.data[i][j] %= MOD;
				}
			}
		}
		return ret;
	}
};

Matrix pow(const Matrix &m, ll n) {
	if (n == 1) return m;
	Matrix half = pow(m, n/2);
	Matrix ret = half*half;
	if (n%2) ret = ret*m;
	return ret;
} 

ll solve(ll A, ll B, ll N, ll K) {
	if (N == 1) return A;
	if (N == 2) return B;
	Matrix k {{{1, K}, {1, 0}}}; 
	k = pow(k, N-2);
	ll ret = k.data[0][0] * B + k.data[0][1] * A;
	ret %= MOD;
	return ret; 
}

int main() {
	ll N, A, B, K;
	cin >> N >> A >> B >> K;
	cout << solve(A, B, N, K); 
    return 0;
}

