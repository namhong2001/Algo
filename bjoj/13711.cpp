#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	int pos[N+1]; 
	for (int i=1; i<=N; ++i) {
		int p;
		cin >> p;
		pos[p] = i;
	}
	vector<int> M;
	for (int i=1; i<=N; ++i) {
		int p;
		cin >> p;
		int num = pos[p];
		auto lower = lower_bound(M.begin(), M.end(), num);
		if (lower != M.end()) *lower = num;
		else M.push_back(num);
	}
	cout << M.size(); 
	return 0;
}

