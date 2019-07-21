#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cstring>
#include <cmath>

using namespace std;

const int LIMIT = 1e6+1; 
bool isprime[LIMIT];
vector<int> primes;
void eratos() {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i<=sqrt(LIMIT); ++i) {
		if (isprime[i]) {
			for (int j=i*i; j<LIMIT; j+=i) {
				isprime[j] = false;
			}
		}
	}
	for (int i=2; i<LIMIT; ++i) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}
} 

int main() {
	eratos();
	int N;
	cin >> N;
	vector<map<int,int>> factors(N);
	map<int,int> total_factors;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		for (int p : primes) {
			if (a == 1) break;
			while (a%p == 0) {
				factors[i][p]++;
				total_factors[p]++; 
				a/=p;
			}
		} 
	}
	int g = 1;
	int moves = 0;
	for (auto factor : total_factors) {
		int p, cnt;
		tie(p, cnt) = factor; 
		if (cnt/N) {
			g *= pow(p, cnt/N);
			for (int i=0; i<N; ++i) {
				if (factors[i][p] < cnt/N) {
					moves += cnt/N - factors[i][p];
				}
			}
		}
	}
	cout << g << ' ' << moves << endl;
	return 0;
} 
