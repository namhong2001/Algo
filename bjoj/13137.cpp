#include <iostream>
#include <numeric>

using namespace std;

const int P_MAX = 2e5;

int main() {
	int N;
	cin >> N;
	int p[N+1];
	for (int i=1; i<=N; ++i) cin >> p[i];
	int d[P_MAX+1] = {};
	iota(d, d+P_MAX+1, 0); 
	for (int i=2; i<=N; ++i) {
		int c = p[i]; 
		for (int j=c; j<=P_MAX; ++j) {
			if (d[j] < d[j-c] + 1) {
				cout << "No";
				return 0;
			}
			d[j] = min(d[j], d[j-c] + 1);
		}
	}
	cout << "Yes"; 
	return 0;
}

