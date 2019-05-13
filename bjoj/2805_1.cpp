#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


int n, m;
vector<ll> p_sum;
vector<int> tree;

ll remains(int height) {
	auto it = lower_bound(tree.begin(), tree.end(), height);
	if (it == tree.end()) return 0;
	int idx = (int)distance(tree.begin(), it); 	
	ll ret = p_sum[n-1];
	ret -= idx>0 ? p_sum[idx-1] : 0;
	ret -= 1ll*(n-idx)*height;
	return ret;
}

int bs(int first, int last) {
	int count = last-first;
	while (count > 0) {
		int step = count/2;
		int mid = first + step;
		if (remains(mid) < 1ll*m) {
			count = step;
		} else {
			first = mid+1;
			count -= step+1;
		}
	}
	// first is upper_bound
	return first-1;
}
		
int main() {
	cin >> n >> m;
	p_sum.resize(n);
	tree.resize(n);
	for(int i=0; i<n; ++i) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	p_sum[0] = tree[0];
	for (int i=1; i<n; ++i) {
		p_sum[i] = p_sum[i-1]+tree[i];
	}	
	cout << bs(0, 1e9+1) << endl;
	return 0;
}
