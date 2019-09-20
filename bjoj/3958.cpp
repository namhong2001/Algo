#include <iostream>
#include <vector>

using namespace std;

const int T = 25000; 

int main() {
	int N;
	cin >> N;
	int a[N+1], b[N+1], t[N+1];
	for (int i=1; i<=N; ++i) cin >> a[i] >> b[i] >> t[i];
	int d[T+1] = {};
	for (int i=1; i<=N; ++i) {
		if (b[i] == 0) {
			for (int j=0; j+t[i]<=T; ++j) {
				d[j+t[i]] = max(d[j+t[i]], d[j] + a[i]);
			}
		} else {
			vector<int> fun = {0}; 
			for (int k=1; ;++k) {
				int f = a[i] - (k-1)*(k-1)*b[i];
				if (f < 0) break;
				fun.push_back(fun.back() + f);
			}
			for (int j=T; j>=0; --j) {
				for (int k=1; k<(int)fun.size(); ++k) {
					int pre = j - k*t[i];
					if (pre < 0) break;
					d[j] = max(d[j], d[pre] + fun[k]);
				}
			}
		}
	} 
	int Q;
	cin >> Q;
	for (int i=0; i<Q; ++i) {
		int t;
		cin >> t;
		cout << d[t] << '\n';
	} 
	return 0;
}

