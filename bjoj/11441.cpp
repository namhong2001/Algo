#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> inputs(n);
	for (int i=0; i<n; ++i) cin >> inputs[i];
	vector<int> psum(n+1, 0);
	partial_sum(inputs.begin(), inputs.end(), psum.begin()+1);
	int m;
	cin >> m; 
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << psum[b] - psum[a-1] << '\n';
	}
	return 0;
}
