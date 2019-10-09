#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	if (N == 1) {
		if (arr[0] == 15) cout << "DOWN";
		else if (arr[0] == 0) cout << "UP";
		else cout << -1;
	} else {
		if (arr[N-2] < arr[N-1]) {
			if (arr[N-1] != 15) cout << "UP";
			else cout << "DOWN";
		} else {
			if (arr[N-1] != 0) cout << "DOWN";
			else cout << "UP";
		}
	} 
	return 0;
}

