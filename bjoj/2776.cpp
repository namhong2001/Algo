#include <iostream>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		unordered_set<int> viewed;
		for (int i=0; i<N; ++i) {
			int a;
			cin >> a;
			viewed.insert(a);
		}
		int M;
		cin >> M;
		for (int i=0; i<M; ++i) {
			int a;
			cin >> a;
			if (viewed.find(a) == viewed.end()) {
				cout << 0 << '\n';
			} else {
				cout << 1 << '\n';
			}
		}
	}
	return 0;
}
