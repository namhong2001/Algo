#include <iostream>
#include <queue>
#include <vector> 

using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		priority_queue<int> mmax;
		priority_queue<int, vector<int>, greater<int>> mmin;
		cout << (M+1)/2 << '\n';
		int cnt = 0;
		for (int i=0; i<M; ++i) {
			int a;
			cin >> a;
			if (mmax.size() > mmin.size()) {
				mmin.push(a);
			} else {
				mmax.push(a);
			}
			if (mmax.size() > 0 && mmin.size() > 0 && mmax.top() > mmin.top()) {
				int maxtop = mmax.top();
				int mintop = mmin.top();
				mmax.pop();
				mmin.pop();
				mmax.push(mintop);
				mmin.push(maxtop);
			}
			if (i%2 == 0) {
				if (mmax.size() > mmin.size()) {
					cout << mmax.top() << ' ';
				} else {
					cout << mmin.top() << ' ';
				}
				cnt++;
				if (cnt == 10) {
					cout << '\n';
					cnt = 0;
				}
			}
		}
	}
	return 0;
} 
