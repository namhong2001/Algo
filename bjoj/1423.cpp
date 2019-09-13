#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll cnt[N+1];
	for (int i=1; i<=N; ++i) cin >> cnt[i];
	ll pwr[N+1];
	for (int i=1; i<=N; ++i) cin >> pwr[i];
	ll D; 
	cin >> D;
	ll d[D+1] = {}; 
	for (int i=1; i<=N; ++i) {
		for (int c=1; c<=min(cnt[i], D); ++c) { 
			for (int j=D; j>=0; --j) { 
				for (int add=1; add+i<=N && j-add>=0; ++add) {
					d[j] = max(d[j], d[j-add] + pwr[i+add] - pwr[i]);
				}
			}
		}
	}
	ll sum = 0;
	for (int i=1; i<=N; ++i) sum += cnt[i]*pwr[i];
	cout << d[D] + sum; 
	return 0;
}

