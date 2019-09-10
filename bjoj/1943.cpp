#include <iostream>

using namespace std;

const int INF = 987654321;

int main() { 
	int T = 3;
	while(T--) {
		int N;
		cin >> N;
		const int M = 1e5;
		bool d[M+1] = {};
		d[0] = true;
		int sum = 0;
		for (int i=1; i<=N; ++i) {
			int w, m;
			cin >> w >> m;
			sum += w*m;
			for (int r=0; r<w; ++r) {
				int last_ok = -INF;
				for (int j=0; w*j+r<=M; ++j) {
					if (d[w*j+r]) last_ok = j;
					d[w*j+r] = j-last_ok <= m;
				}
			}
		}
		if (sum%2) cout << "0" << '\n';
		else cout << d[sum/2] << '\n';
	} 
	return 0;
}

