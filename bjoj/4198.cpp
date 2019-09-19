#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> &arr, int s) {
	vector<int> M;
	for (int i=s+1; i<(int)arr.size(); ++i) {
		if (arr[i] < arr[s]) continue;
		auto lower = lower_bound(M.begin(), M.end(), arr[i]);
		if (lower != M.end()) *lower = arr[i];
		else M.push_back(arr[i]);
	}
	return M.size();
} 

int lds(vector<int> &arr, int s) {
	vector<int> M;
	for (int i=s+1; i<(int)arr.size(); ++i) {
		if (arr[i] > arr[s]) continue;
		auto lower = lower_bound(M.begin(), M.end(), arr[i], greater<int>());
		if (lower != M.end()) *lower = arr[i];
		else M.push_back(arr[i]);
	}
	return M.size();
} 

int main() {
	int N;
	cin >> N;
	if (N <= 2) {
		cout << N; 
		return 0;
	}
	vector<int> arr(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	int ans = 0; 
	for (int i=0; i<N; ++i) {
		ans = max(ans, lis(arr, i) + lds(arr, i) + 1);
	}
	cout << ans; 
	return 0;
}

