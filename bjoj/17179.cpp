#include <iostream>
#include <vector>

using namespace std;

int N, M, L;

void solve(vector<int> &pos, int slice) {
	auto get_cnt = [&](int limit) {
		int end = 0;
		int cnt = 0;
		for (int p : pos) { 
			if (end + limit <= p) {
				cnt++;
				end = p;
			}
		}
		return cnt;
	};
	int l = 0, r = L+1;
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (get_cnt(mid) < slice) r = mid;
		else l = mid;
	}
	cout << l << endl;
} 

int main() {
	cin >> N >> M >> L;
	vector<int> pos(M+1);
	for (int i=0; i<M; ++i) {
		cin >> pos[i];
	}
	pos.push_back(L);
	for (int i=0; i<N; ++i) {
		int slice;
		cin >> slice; 
		solve(pos, slice+1); 
	}
	return 0;
} 
