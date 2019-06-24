#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

const int d[2] = {-1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, T;
	cin >> N >> T;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	vector<int> rm; // relative minimum
	for (int i=0; i<N; ++i) {
		if (i == 0) {
			if (arr[i] <= arr[i+1]) rm.push_back(i);
		} else if (i == N-1) {
			if (arr[i] <= arr[i-1]) rm.push_back(i);
		} else {
			if (arr[i-1] >= arr[i] && arr[i] <= arr[i+1]) rm.push_back(i);
		}
	} 
	vector<int> tarr;
	auto decision = [&](int diff) {
		tarr = arr;
		vector<bool> visited(N, false);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for (int i : rm) {
			pq.emplace(tarr[i], i);
		}
		int cnt = 0;
		while (!pq.empty()) {
			int here = pq.top().second; 
			int value = pq.top().first;
			pq.pop(); 
			if (visited[here]) continue;
			visited[here] = true;
			cnt += tarr[here] - value;
			if (cnt > T) return false;
			tarr[here] = value;
			for (int i=0; i<2; ++i) {
				int next = here + d[i];
				if (next < 0 || next >= N || visited[next]) continue;
				pq.emplace(min(tarr[next], tarr[here]+diff), next);
			}
		}
		return true;
	};
	
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l+r)/2;
		if (decision(mid)) {
			r = mid;
		} 
		else l = mid+1;
	}
	decision(l);
	for (int a : tarr) {
		cout << a << ' ';
	}
	return 0;
} 
