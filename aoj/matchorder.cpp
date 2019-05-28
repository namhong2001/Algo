#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<int> russia(n);
		vector<int> korea(n);
		for (int i=0; i<n; ++i) {
			cin >> russia[i];
		}
		for (int i=0; i<n; ++i) {
			cin >> korea[i];
		}
		sort(russia.begin(), russia.end());
		sort(korea.begin(), korea.end());
		int ri = 0;
		int cnt = 0;
		for (auto k : korea) {
			if (russia[ri] <= k) {
				cnt++;
				ri++;
			}
			else continue;
		}
		cout << cnt << endl;
	}
	return 0;
} 
