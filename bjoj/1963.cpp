#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N_MAX = 1e4;

bool is_prime[N_MAX];

void make_prime() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i=2; i<sqrt(N_MAX); ++i) {
		if (!is_prime[i]) continue;
		for (int j=i+i; j<N_MAX; j+=i) {
			is_prime[j] = false;
		}
	}
} 

int solve(int a, int b) {
	vector<int> d(N_MAX, -1);
	queue<int> q;
	q.push(a);
	d[a] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == b) return d[b]; 
		for (int pos=0; pos<4; ++pos) {
			int mod = pow(10, pos);
			int div = pow(10, pos+1);
			int base = here/div*div + here%mod;
			for (int i=0; i<10; ++i) {
				int next = base + i*mod;
				if (next == here || next < 1e3 || next >= 1e4 || !is_prime[next] || d[next] != -1) continue;
				q.push(next);
				d[next] = d[here]+1;
			}
		}
	}
	return -1;
} 

int main() {
	int T;
	cin >> T;
	make_prime();
	while (T--) {
		int a, b;
		cin >> a >> b;
		int ans = solve(a, b);
		if (ans == -1) {
			cout << "Impossible" << '\n';
		} else {
			cout << ans << '\n';
		}
	}
	return 0;
} 
