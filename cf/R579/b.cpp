#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;
vector<bool> isprime;
void eratos(int limit) {
	primes.clear();
	isprime.assign(limit, true);
	isprime[0] = isprime[1] = false;
	for (int i=2; i<=sqrt(limit); ++i) {
		if (!isprime[i]) continue;
		for (int j=i+i; j<limit; j+=i) {
			isprime[j] = false;
		}
	}
	for (int i=2; i<limit; ++i) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}
} 

int main() {
	int Q;
	cin >> Q;
	eratos(10001); 
	for (int i=0; i<Q; ++i) {
		int N;
		cin >> N;
		vector<int> pcnt(primes.size(), 0);
		vector<int> stick(4*N);
		vector<int> stickCnt(10001, 0);
		for (int i=0; i<4*N; ++i) {
			cin >> stick[i];
			int s = stick[i];
			stickCnt[s]++;
			for (int j=0; j<(int)primes.size(); ++j) { 
				if (s == 1) break;
				int p = primes[j];
				while (s % p == 0) {
					s /= p;
					pcnt[j]++;
				}
			} 
		}
		int area = 1;
		int ok = true;
		for (int i=0; i<(int)primes.size(); ++i) {
			if (pcnt[i]) {
				if (pcnt[i]%N) {
					ok = false;
					break;
				} else {
					area *= pow(primes[i], pcnt[i]/N/2);
				}
			}
		}
		if (!ok) {
			cout << "NO" << endl;
		}
		for (int i=0; i<10001; ++i) {
			stickCnt[i] *= 2;
		}
		for (int i=0; i<4*N; ++i) {
			int s = stick[i];
			if (stickCnt[s] <= 0) {
				ok = false;
				break;
			}
			stickCnt[s]--;
			int ss = area/s;
			if (stickCnt[ss] <= 0) {
				ok = false;
				break;
			}
			stickCnt[ss]--;
		}
		if (ok) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} 
	return 0;
}

