#include <iostream>
#include <queue> 

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			} else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		} else {
			pq.emplace(abs(a), a);
		}
	}
	return 0;
} 
