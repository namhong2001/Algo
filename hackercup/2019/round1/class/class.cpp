#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007; 

int N, K;
ll pow2(ll cnt) {
	if (cnt == 0) return 1ll;
	else if (cnt == 1) return 2ll;
	if (cnt % 2 == 0) {
		ll half = pow2(cnt/2);
		return (half * half) % MOD;
	} else {
		ll half = pow2(cnt/2);
		return (half * half * 2) % MOD;
	}
	return 0; // error;
} 

ll get_ans(vector<bool> &change) {
	ll ret = 0;
	for (int i=0; i<N; ++i) { 
		if (change[i]) {
			ret += pow2(i+1);
			ret %= MOD;
		}
	}
	return ret;
}


int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> N >> K;
		string vote;
		cin >> vote;
		vector<bool> change(N, false);
		int sum = 0;
		for (int i=N-1; i>=0; --i) {
			if (vote[i] == 'A') {
				sum--;
			} else {
				sum++;
			}
			if (sum > K) {
				change[i] = true;
				sum -= 2;
			}
			if (sum < 0) sum = 0;
		}
		cout << "Case #" << t << ": " << get_ans(change) << '\n';
	}
	return 0;
} 
