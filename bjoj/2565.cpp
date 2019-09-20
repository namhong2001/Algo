#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 500;

int main() {
	int C;
	cin >> C;
	vector<int> arr(N+1);
	for (int i=0; i<C; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	vector<int> M;
	for (int i=1; i<=N; ++i) {
		if (arr[i] == 0) continue;
		auto lower = lower_bound(M.begin(), M.end(), arr[i]);
		if (lower != M.end()) *lower = arr[i];
		else M.push_back(arr[i]);
	}
	cout << C - M.size(); 
	return 0;
}

