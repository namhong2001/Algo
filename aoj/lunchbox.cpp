#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> micro(n); 
		vector<int> eating(n); 
		for (int i=0; i<n; ++i) {
			cin >> micro[i];
		}
		for (int i=0; i<n; ++i) {
			cin >> eating[i];
		}
		vector<pii> lunch(n);
		for (int i=0; i<n; ++i) {
			lunch[i] = {eating[i], micro[i]};
		}
		sort(lunch.begin(), lunch.end(), greater<pii>());
		int ans = 0;
		int cur_micro = 0;
		for (int i=0; i<n; ++i) {
			cur_micro += lunch[i].second;
			ans = max(ans, cur_micro + lunch[i].first); 
		}
		cout << ans << endl;
	}
	return 0;
} 
