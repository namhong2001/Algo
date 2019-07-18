#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	int len[N+1] = {}; 
	int maxlen = 0;
	for (int i=1; i<=N; ++i) {
		int num;
		cin >> num;
		len[num] = len[num-1]+1;
		maxlen = max(maxlen, len[num]);
	} 
	cout << N-maxlen << endl; 
	return 0;
} 
