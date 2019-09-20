#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	int arr[N] = {}; 
	int P[N] = {};
	vector<int> M;
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
		auto lower = lower_bound(M.begin(), M.end(), arr[i]);
		if (lower != M.end()) { 
			*lower = arr[i];
			P[i] = lower - M.begin();
		} else {
			M.push_back(arr[i]);
			P[i] = M.size()-1; 
		}
	} 
	vector<int> ans; 
	int pos = M.size()-1;
	for (int i=N-1; i>=0; --i) {
		if (P[i] == pos) ans.push_back(arr[i]), pos--;
		if (pos < 0) break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int a : ans) {
		cout << a << ' ';
	} 
	return 0;
}

