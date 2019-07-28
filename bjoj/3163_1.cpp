#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, L, K; 
		cin >> N >> L >> K;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		vector<int> ids(N);
		for (int i=0; i<N; ++i) { 
			int p, id;
			cin >> p >> id;
			ids[i] = id;
			if (id < 0) { 
				pq.emplace(p, -1);
			} else {
				pq.emplace(L-p, 1);
			}
		}
		int left = 0;
		int right = N-1;
		int ith = 0;
		while (!pq.empty()) {
			pii cur = pq.top();
			pq.pop();
			int dist = cur.first;
			int id = cur.second < 0 ? ids[left++] : ids[right--];
			if (!pq.empty()) {
				pii next = pq.top(); 
				if (next.first == dist) {
					int next_id = next.second < 0 ? ids[left] : ids[right];
					if (next_id < id) {
						pq.pop();
						next.second < 0 ? left-- : right++;
						ith++;
						if (ith == K) {
							cout << next_id << '\n';
							break;
						}
					}
				}
			}
			ith++;
			if (ith == K) {
				cout << id << '\n';
				break;
			}
		}
	}
	return 0;
} 
