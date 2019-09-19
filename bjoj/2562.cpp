#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N = 9;
	vector<int> arr(N); 
	for (int i=0; i<N; ++i) cin >> arr[i];
	auto m = max_element(arr.begin(), arr.end());
	cout << *m << '\n';
	cout << m - arr.begin() + 1;
	return 0;
}

