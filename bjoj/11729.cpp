#include <iostream>
#include <cmath>

using namespace std;

void print(int from, int to, int cnt) {
	if (cnt == 1) {
		cout << from+1 << ' ' << to+1 << '\n';
		return;
	}
	bool arr[3] = {};
	arr[from] = true;
	arr[to] = true;
	for (int i=0; i<3; ++i) {
		if (!arr[i]) {
			print(from, i, cnt-1);
			cout << from+1 << ' ' << to+1 << '\n';
			print(i, to, cnt-1);
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	cout << (int)pow(2, N) - 1 << '\n';
	print(0, 2, N);
	return 0;
} 
