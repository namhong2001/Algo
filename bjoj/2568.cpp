#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5e5;

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
	vector<int> P(N+1, -1);
	for (int i=1; i<=N; ++i) {
		if (arr[i] == 0) continue;
		auto lower = lower_bound(M.begin(), M.end(), arr[i]);
		if (lower != M.end()) {
			*lower = arr[i];
			P[i] = lower - M.begin();
		} else {
			M.push_back(arr[i]);
			P[i] = M.size() - 1;
		} 
	}
	vector<bool> selected(N+1);
	int pos = M.size()-1;
	for (int i=N; i>0; --i) {
		if (P[i] == pos) {
			selected[i] = true;
			pos--;
		}
		if (pos < 0) break;
	} 
	cout << C - M.size() << '\n';
	for (int i=1; i<=N; ++i) {
		if (!selected[i] && arr[i]) cout << i << '\n';
	}
	return 0;
}

