#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> pkm(n);
	unordered_map<string, int> si;
	for (int i=0; i<n; ++i) {
		cin >> pkm[i];
		si[pkm[i]] = i+1;
	}
	for (int i=0; i<m; ++i) {
		string query;
		cin >> query;
		int num = -1;
		try {
			num = stoi(query);
		} catch (...) {}
		if (num == -1) {
			cout << si[query] << '\n';
		} else {
			cout << pkm[num-1] << '\n';
		}
	}
	return 0;
} 
