#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int alpha[26] = {0};
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s;
		for (int j=0; j<(int)s.size(); ++j) {
			alpha[s[j]-'A'] += pow(10, s.size()-1-j);
		}
	}
	sort(alpha, alpha+26, greater<int>());
	int ans = 0;
	for (int i=0; i<=9; ++i) {
		ans += alpha[i] * (9-i);
	}
	cout << ans;
	return 0;
} 
