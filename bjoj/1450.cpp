#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void add(vector<int> &set, int ith, ll sum, vector<ll> &subset) {
	if (ith == (int)set.size()) {
		subset.push_back(sum);
		return;
	}
	add(set, ith+1, sum, subset);
	add(set, ith+1, sum+set[ith], subset); 
} 

int main() {
	int N, C;
	cin >> N >> C;
	vector<int> A, B;
	for (int i=1; i<=N; ++i) {
		int c; 
		cin >> c;
		if (i <= N/2) A.push_back(c);
		else B.push_back(c);
	}
	vector<ll> subsetA, subsetB;
	add(A, 0, 0, subsetA);
	add(B, 0, 0, subsetB);
	sort(subsetB.begin(), subsetB.end());
	ll ans = 0;
	for (ll a : subsetA) {
		auto upper = upper_bound(subsetB.begin(), subsetB.end(), C-a); 
		ans += distance(subsetB.begin(), upper);
	}
	cout << ans; 
	return 0;
}

