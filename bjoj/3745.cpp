#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	while (cin >> N) {
		vector<int> M;
		for (int i=0; i<N; ++i) {
			int a;
			cin >> a;
			auto lower = lower_bound(M.begin(), M.end(), a);
			if (lower != M.end()) *lower = a;
			else M.push_back(a);
		}
		cout << M.size() << '\n';
	} 
	return 0;
}

