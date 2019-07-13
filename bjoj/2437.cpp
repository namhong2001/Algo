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
	int sum = 0;
	for (int i=0; i<N; ++i) {
		if (sum + 1 < arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1 << endl;
	return 0;
}


