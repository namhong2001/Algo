#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = -1;
	for (int i=0; i<N-2; ++i) {
		int a = arr[i];
		int b = arr[i+1];
		int c = arr[i+2];
		if (a+b > c) {
			ans = max(ans, a+b+c);
		}
	}
	cout << ans << endl; 
	return 0;
}

