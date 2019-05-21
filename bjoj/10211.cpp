#include <iostream>
#include <vector>


using namespace std;

const int INF = 987654321;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> inputs(n);
		for (int i=0; i<n; ++i) cin >> inputs[i];
		
		int ans = -INF;
		int sum = 0;
		for (int i=0; i<n; ++i) {
			sum += inputs[i]; 
			ans = max(ans, sum);
			if (sum < 0) {
				sum = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
