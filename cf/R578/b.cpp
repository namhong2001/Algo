#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<int> blocks(N);
		for (int i=0; i<N; ++i) {
			cin >> blocks[i];
		}
		bool isOk = true;
		for (int i=0; i<N-1; ++i) {
			int low = max(0, blocks[i+1] - K);
			if (low < blocks[i]) {
				M += blocks[i] - low;
			} else if (low > blocks[i]) {
				M -= low - blocks[i];
				if (M < 0) {
					isOk = false;
					break; 
				}
			}
		}
		if (isOk) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} 
	return 0;
}

