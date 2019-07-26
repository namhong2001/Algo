#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

map<int,int> d[1001]; // [vertices][sum][prime]

const int LIMIT = 1001;
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
		if (isprime[i]) primes.push_back(i);
	}
} 

bool find(int sum, int n) { 
	if (n == 1) {
		if (d[1][sum] > 0) {
			return true;
		} else {
			return false;
		}
	}
	int &ret = d[n][sum]; 
	if (ret > 0) {
		return true;
	} else if (ret == -1) {
		return false;
	}
	for (auto p : primes) {
		if (find(sum-p, n-1)) {
			ret = p; 
			return true;
		}
	}
	ret = -1;
	return false;
} 

void solve(int n) { 
	auto start = lower_bound(primes.begin(), primes.end(), n); 
	vector<int> ans; 
	int edges; 
	for (auto i=start; i != primes.end(); ++i) {
		int sum = (*i)*2; 
		if (find(sum, n)) { 
			edges = *i;
			while (n > 0) {
				ans.push_back(d[n][sum]);
				sum -= d[n][sum];
				n--;
			}
			break;
		}
	}
	if (ans.empty()) {
		cout << -1 << endl;
	} else {
		sort(ans.begin(), ans.end(), greater<int>());
		cout << edges << endl;
		for (int i=0; i<(int)ans.size(); ++i) {
			for (int j=i+1; j<(int)ans.size(); ++j) { 
				while (ans[i] > 0 && ans[j] > 0) {
					ans[i]--, ans[j]--;
					cout << i+1 << ' ' << j+1 << '\n';
				} 	
				if (ans[i] == 0) break;
			}
		}
	}
} 
				
int main() {
	int N;
	cin >> N;
	eratos();
	for (auto p : primes) {
		d[1][p] = p;
	}
	solve(N); 
	return 0;
}
