#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i=0; i<n; ++i) cin >> arr[i];
	if (next_permutation(arr.begin(), arr.end())) {
		for (int a : arr) {
			cout << a << ' ';
		}
	} else {
		cout << -1;
	}
	return 0;
} 
