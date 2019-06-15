#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

struct RMQ {
	vector<int> arr;
	vector<int> nodes;
	int n;
	RMQ(vector<int> &arr) {
		this->arr = arr;
		n = arr.size();
		nodes.resize(4*n);
		init(1, 0, n-1);
	}
	int init(int index, int left, int right) {
		if (left == right) return nodes[index] = arr[left];
		int mid = (left + right)/2;
		return nodes[index] = min(init(index*2, left, mid), init(index*2+1, mid+1, right));
	}
	int query(int left, int right, int node_index, int node_left, int node_right) {
		if (node_left > right || node_right < left) return INF;
		if (left <= node_left && node_right <= right) return nodes[node_index];
		int node_mid = (node_left+node_right)/2;
		return min(query(left, right, node_index*2, node_left, node_mid),
				query(left, right, node_index*2+1, node_mid+1, node_right));
	} 
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1); 
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
		int left, right;
		cin >> left >> right;
		cout << rmq.query(left-1, right-1) << '\n';
	}
	return 0;
} 
