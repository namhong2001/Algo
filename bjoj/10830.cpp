#include <iostream> 
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> matrix; 
const ll MOD = 1e3;

matrix operator * (const matrix &A, const matrix &B) {
	int N = A.size();
	matrix ret = matrix(N, vector<int>(N, 0));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			for (int k=0; k<N; ++k) {
				ret[i][j] += A[i][k]*B[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
} 

matrix pow(const matrix &A, ll cnt) { 
	if (cnt == 1) return A; 
	matrix half = pow(A, cnt/2);
	if (cnt%2) {
		return half*half*A;
	} else {
		return half*half;
	}
} 

void print(const matrix &A) {
	int N = A.size();
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
} 

int main() {
	ll N, B;
	cin >> N >> B;
	matrix m = matrix(N, vector<int>(N));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> m[i][j];
			m[i][j] %= MOD;
		}
	}
	print(pow(m, B));
	return 0; 
} 
