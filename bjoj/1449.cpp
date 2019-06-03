#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	double n, l;
	cin >> n >> l;
	vector<double> leak(n);
	for (int i=0; i<n; ++i) {
		cin >> leak[i];
	}
	sort(leak.begin(), leak.end());
	double end = 0;
	int ans = 0;
	for (double a : leak) {
		if (a <= end-0.5) {
			continue;
		} else {
			end = a+l-0.5;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
			
			

		

	

