#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int X[N];
		int Y[N];
		for (int i=0; i<N; ++i) {
			cin >> X[i] >> Y[i];
		}
		bool choice[N] = {};
		for (int i=N/2; i<N; ++i) {
			choice[i] = true;
		}
		double ans = 1e9;
		do {
			int x = 0;
			int y = 0;
			for (int i=0; i<N; ++i) {
				if (choice[i]) {
					x += X[i];
					y += Y[i];
				} else {
					x -= X[i];
					y -= Y[i];
				}
			}
			ans = min(ans, sqrt(1ll*x*x+1ll*y*y)); 
		} while (next_permutation(choice, choice+N));
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
} 
