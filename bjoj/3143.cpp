#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> aset(n);
	vector<pair<int,int>> bset(n);
	for (int i=0; i<n; ++i) {
		cin >> aset[i];
	}
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		bset[i] = {a,b};
	}
	sort(aset.begin(), aset.end());
	sort(bset.begin(), bset.end());
	priority_queue<pair<int,int>> pq;
	int ans = 0;
	int bidx = 0;
	for (int a : aset) {
		
		




