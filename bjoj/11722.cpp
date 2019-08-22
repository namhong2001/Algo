#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> ans;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i]; 
	}
	reverse(arr.begin(), arr.end()); 
	for (int i=0; i<N; ++i) {
		int a = arr[i];
		auto lower = lower_bound(ans.begin(), ans.end(), a);
		if (lower == ans.end()) {
			ans.push_back(a);
		} else {
			*lower = a; 
		}
	}
	cout << ans.size() << endl; 
	return 0;
}

