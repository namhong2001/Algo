#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int arr[], int N) {
	vector<int> M; 
	for (int i=1; i<=N; ++i) {
		auto lower = lower_bound(M.begin(), M.end(), arr[i]);
		if (lower != M.end()) *lower = arr[i];
		else M.push_back(arr[i]);
	}
	return M.size();
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	int arr[N+1];
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
	}
	cout << lis(arr, N); 
	return 0;
}

