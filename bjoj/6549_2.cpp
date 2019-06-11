#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = numeric_limits<int>::max(); 

struct RMQ {  // min
	int n;
	vector<int> range_min; // store index
	vector<int> origin;
	RMQ(const vector<int> &arr) {
		n = arr.size(); 
		origin = arr;
		range_min.resize(n*4);
		init(arr, 0, n-1, 1); 
	}
	int init(const vector<int> &arr, int left, int right, int node) {
		if (left == right) return range_min[node] = left;
		int mid = (left+right) / 2;
		int lm_index = init(arr, left, mid, node*2);
		int rm_index = init(arr, mid+1, right, node*2+1);
		if (arr[lm_index] <= arr[rm_index]) {
			range_min[node] = lm_index;
		} else {
			range_min[node] = rm_index;
		} 
		return range_min[node];
	}
	int query(int left, int right, int node, int node_left, int node_right) {
		if (right < node_left || node_right < left) return -1;
		if (left <= node_left && node_right <= right) return range_min[node];
		int mid = (node_left + node_right) / 2;
		int lm_index = query(left, right, node*2, node_left, mid);
		int rm_index = query(left, right, node*2+1, mid+1, node_right); 
		int ret;
		if (lm_index == -1) {
			ret = rm_index;
		} else if (rm_index == -1) {
			ret = lm_index;
		} else if (origin[lm_index] <= origin[rm_index]) {
			ret = lm_index;
		} else {
			ret = rm_index;
		} 
		return ret;
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

ll histogram(RMQ &rmq, vector<int> &height, int left, int right) { 
	if (right < left) return -1;
	int min_index = rmq.query(left, right);
	ll ret = 1ll * height[min_index] * (right-left+1);
	ret = max(ret, histogram(rmq, height, left, min_index-1));
	ret = max(ret, histogram(rmq, height, min_index+1, right));
	return ret;
} 

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> height(n);
		for (int i=0; i<n; ++i) {
			cin >> height[i];
		}
		RMQ rmq(height);
		cout << histogram(rmq, height, 0, n-1) << endl;
	}
	return 0;
} 
