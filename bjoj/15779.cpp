#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	int len = 2;
	int ans = 0;
	for (int i=2; i<N; ++i) {
		if (arr[i-2] <= arr[i-1] && arr[i-1] <= arr[i]) {
			len = 2;
		} else if (arr[i-2] >= arr[i-1] && arr[i-1] >= arr[i]) {
			len = 2;
		} else {
			len++;
		}
		ans = max(ans, len);
	} 
	cout << ans; 
    return 0;
}

