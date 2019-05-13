#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> card(n);
	for(int i=0; i<n; ++i) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());
	int m;
	cin >> m;
	while (m--) {
		int value;
		cin >> value;
		if(binary_search(card.begin(), card.end(), value)) {
			cout << 1 << ' ';
		} else {
			cout << 0 << ' ';
		}
	}
	return 0;
}

