#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	map<int,int> cnt; 
	for (int i=2; i<10000; ++i) {
		while (N%i == 0) {
			cnt[i]++;
			N /= i;
		}
	}
	if (N > 1) {
		cnt[N]++;
	}
	for (auto p : cnt) {
		for (int i=0; i<p.second; ++i) {
			cout << p.first << '\n';
		}
	} 
	return 0;
}

