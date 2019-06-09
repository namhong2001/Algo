#include <iostream>
#include <vector>
#include <algorithm> 
#include <list>

using namespace std; 

typedef long long ll;

ll perm_cnt[21];

int n;
vector<int> kth_perm(ll k) {
	vector<int> ret;
	list<int> remain;
	for (int i=1; i<=n; ++i) remain.push_back(i);
	while (!remain.empty()) {
		for (auto it=remain.begin(); it != remain.end(); ++it) {
			int r = *it;
			if (perm_cnt[remain.size()-1] > k || k == 0) {
				ret.push_back(r);
				remain.erase(it);
				break; 
			} else {
				k -= perm_cnt[remain.size()-1];
			}
		}
	}
	return ret;
}

ll order(vector<int> &perm) {
	ll k = 1;
	list<int> remain;
	for (int i=1; i<=n; ++i) remain.push_back(i);
	for (int p : perm) {
		auto it = find(remain.begin(), remain.end(), p);
		ll dist = distance(remain.begin(), it);
		remain.erase(it);
		k += dist * perm_cnt[remain.size()];
	}
	return k;
} 

int main() {
	cin >> n;
	perm_cnt[0] = 0;
	perm_cnt[1] = 1; 
	for (int i=2; i<n; ++i) {
		perm_cnt[i] = perm_cnt[i-1] * i;
	}
	int problem;
	cin >> problem;
	if (problem == 1) {
		ll k;
		cin >> k;
		k--;
		vector<int> perm = kth_perm(k);
		for (int p : perm) {
			cout << p << ' ';
		}
	} else if (problem == 2) {
		vector<int> perm(n);
		for (int i=0; i<n; ++i) {
			cin >> perm[i]; 
		}
		cout << order(perm);
	} 

	return 0;
} 
