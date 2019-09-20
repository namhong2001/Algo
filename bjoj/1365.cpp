#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> M;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		auto lower = lower_bound(M.begin(), M.end(), a);
		if (lower != M.end()) *lower = a;
		else M.push_back(a);
	}
	cout << N - M.size(); 
	return 0;
}

