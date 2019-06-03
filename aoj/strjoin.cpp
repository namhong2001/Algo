#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i=0; i<n; ++i) {
			int l;
			cin >> l;
			pq.push(l);
		}
		int ans = 0;
		while (pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			ans += a+b;
			pq.push(a+b); 
		} 
		cout << ans << endl;
	}
	return 0;
} 
