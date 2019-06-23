#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

struct Segment {
	vector<int> nodes;
	int n; 
	Segment(int n): n(n) {
		nodes.resize(2*n);
		for (int i=n; i<2*n; ++i) nodes[i] = 1;
		for (int i=n-1; i>0; --i) nodes[i] = nodes[2*i] + nodes[2*i+1];
	}
	int query(int l, int r) {
		int ret = 0;
		for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
			if (l&1) ret += nodes[l++];
			if (r&1) ret += nodes[--r];
		}
		return ret;
	}
	void update(int index, int num) {
		int ni = n+index;
		nodes[ni] = num; 
		ni /= 2;
		while (ni > 0) {
			nodes[ni] = nodes[2*ni] + nodes[2*ni+1];
			ni /= 2;
		} 
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> order(n);
	unordered_map<int,int> b_index;
	for (int i=0; i<n; ++i) {
		cin >> order[i];
	}
	for (int i=0; i<n; ++i) {
		int id;
		cin >> id;
		b_index[id] = i; 
	}
	Segment seg(n);
	ll ans = 0;
	for (int id : order) {
		int bi = b_index[id];
		ans += seg.query(0, bi+1)-1;
		seg.update(bi, 0);
	}
	cout << ans;
	return 0;
} 
