#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> sensor(n);
	for (int i=0; i<n; ++i) {
		cin >> sensor[i];
	}
	sort(sensor.begin(), sensor.end());
	vector<int> dist(n-1);
	for (int i=1; i<n; ++i) {
		dist[i-1] = sensor[i] - sensor[i-1];
	}
	sort(dist.begin(), dist.end(), greater<int>());
	int blank = 0;
	int cnt = 0;
	for (int d : dist) {
		if (cnt == k-1) break;
		blank += d;
		cnt++;
	}
	cout << sensor[n-1] - sensor[0] - blank << endl;
	return 0;
} 
