#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int w;
	while (cin >> w) {
		w *= 1e7;
		int n;
		cin >> n;
		vector<int> blocks(n);
		for (int i=0; i<n; ++i) {
			cin >> blocks[i];
		}
		sort(blocks.begin(), blocks.end());
		bool answered = false;
		for (auto it = blocks.begin(); it != blocks.end(); ++it) {
			auto lower = lower_bound(blocks.begin(), blocks.end(), w-*it);
			if (lower != blocks.end() && *lower == w-*it && it != lower) {
				cout << "yes " << *it << ' ' << *lower << endl;
				answered = true;
				break;
			} 
		}
		if (!answered) {
			cout << "danger" << endl;
		}
	}
	return 0;
} 
