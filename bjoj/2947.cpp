#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	vector<int> arr(5);
	for (int i=0; i<5; ++i) {
		cin >> arr[i];
	}
	while (true) {
		for (int i=1; i<5; ++i) {
			if (arr[i-1] > arr[i]) {
				swap(arr[i-1], arr[i]);
				for (int a : arr) {
					cout << a << ' ';
				}
				cout << '\n';
			}
		}
		int i;
		for (i=0; i<5; ++i) {
			if (arr[i] != i+1) break;
		}
		if (i == 5) break;
	} 
	return 0;
} 
