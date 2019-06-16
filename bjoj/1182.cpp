#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
int n, s;
int solve(int start, int sum) {
	int ret = 0;
	for (int i=start; i<(int)seq.size(); ++i) {
		if (sum+seq[i] == s) ret++;
		ret += solve(i+1, sum+seq[i]);
	}
	return ret;
} 

int main() {
	cin >> n >> s;
	seq.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> seq[i];
	}
	cout << solve(0, 0);
	return 0;
} 
