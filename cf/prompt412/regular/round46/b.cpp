#include <iostream>

using namespace std;

const int INF = 987654321;

int main() {
	int T;
	cin >> T; 
	while (T--) {
		int N;
		cin >> N; 
		int arr[N+1];
		for (int i=0; i<N; ++i) cin >> arr[i];
		int ans = 0;
		int mmin = INF;
		for (int i=N-1; i>=0; --i) {
			if (arr[i] > mmin) ans++;
			mmin = min(mmin, arr[i]);
		}
		cout << ans << '\n';
	} 
	return 0;
}

