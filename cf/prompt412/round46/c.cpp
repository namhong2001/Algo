#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int cur_min = 1;
	int ans = 0;
	for (int i=0; i<N; ++i) {
		if (arr[i] < cur_min) ans += cur_min - arr[i];
		cur_min = max(cur_min, arr[i]);
		cur_min++;
	} 
	cout << ans;
	return 0;
}

