#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


const int LIMIT = 1e6;
bool isPrime[LIMIT];
vector<int> primes;
void eratos() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<=(int)sqrt(LIMIT); ++i) {
		if (!isPrime[i]) continue;
		for (int j=i+i; j<LIMIT; j+=i) {
			isPrime[j] = false;
		}
	}
	for (int i=2; i<=LIMIT/2; ++i) {
		if (isPrime[i]) primes.push_back(i);
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	eratos();
	while (true) {
		int N; 
		cin >> N;
		if (N == 0) break;
		for (int p : primes) {
			if (isPrime[N-p]) {
				cout << N << " = " << p << " + " << N-p << '\n';
				break;
			}
		} 
	}
	return 0;
} 
