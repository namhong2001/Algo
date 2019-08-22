#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> ans;
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		auto lower = lower_bound(ans.begin(), ans.end(), a);
		if (lower == ans.end()) {
			ans.push_back(a);
		} else {
			*lower = a; 
		}
	}
	cout << ans.size() << endl; 
	return 0;
}

