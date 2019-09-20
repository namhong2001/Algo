#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	vector<int> arr(3, y);
	int cnt = 0;
	while (true) {
		if (arr[0] == x && arr[1] == x && arr[2] == x) break;
		sort(arr.begin(), arr.end());
		arr[0] = min(x, arr[1]+arr[2]-1);
		cnt++;
	}
	cout << cnt << endl; 
	return 0;
} 
