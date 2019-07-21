#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
const ll MOD = 1e9;

ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i=0; i<N; ++i) {
		cin >> A[i];
	}
	int M;
	cin >> M; 
	vector<int> B(M);
	for (int i=0; i<M; ++i) {
		cin >> B[i];
	}
	ll ans = 1;
	bool over_limit = false;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			ll g = gcd(A[i], B[j]); 
			ans = ans*g;
			if (ans > MOD) {
				ans %= MOD;
				over_limit = true;
			}
			A[i] /= g;
			B[j] /= g;
		}
	}
	if (over_limit) { 
		cout << setw(9) << setfill('0');
	}
	cout << ans << endl;
	return 0;
} 
