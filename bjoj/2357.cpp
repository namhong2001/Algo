#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct RMQ {
	int n;
	vector<int> min_nodes;
	vector<int> max_nodes;
	RMQ(vector<int> &arr) {
		n = arr.size();
		min_nodes.resize(2*n); 
		max_nodes.resize(2*n); 
		copy(arr.begin(), arr.end(), min_nodes.begin()+n);
		copy(arr.begin(), arr.end(), max_nodes.begin()+n);
		for (int i=n-1; i>0; --i) {
			min_nodes[i] = min(min_nodes[2*i], min_nodes[2*i+1]);
			max_nodes[i] = max(max_nodes[2*i], max_nodes[2*i+1]);
		}
	}
	int get_min(int l, int r) {
		int ans = INF;
		for (l+=n, r+=n; l<r; l/=2, r/=2) {
			if (l&1) ans = min(ans, min_nodes[l++]); 
			if (r&1) ans = min(ans, min_nodes[--r]);
		}
		return ans;
	}
	int get_max(int l, int r) {
		int ans = -1;
		for (l+=n, r+=n; l<r; l/=2, r/=2) {
			if (l&1) ans = max(ans, max_nodes[l++]); 
			if (r&1) ans = max(ans, max_nodes[--r]);
		}
		return ans;
	}
};
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	RMQ rmq(arr);
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << rmq.get_min(a-1, b) << ' ' << rmq.get_max(a-1, b) << '\n';
	}
	return 0;
}
