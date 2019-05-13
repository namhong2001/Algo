#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> tree(n);
	for(int i=0; i<n; ++i) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	vector<ll> p_sum(n);
	p_sum[0] = tree[0];
	for (int i=1; i<n; ++i) {
		p_sum[i] = p_sum[i-1]+tree[i];
	}
	vector<ll> remain(n);
	remain[0] = p_sum[n-1];
	for (int i=1; i<n; ++i) {
		remain[i] = p_sum[n-1] - p_sum[i-1] - 1ll*tree[i-1]*(n-i);
	}
	auto lower = lower_bound(remain.rbegin(), remain.rend(), m);
	int idx = n-1-(int)distance(remain.rbegin(), lower);
	ll r = *lower;
	ll plus = (r-m)/(n-idx);
	cout << tree[idx-1]+plus << endl;
	return 0;
}
