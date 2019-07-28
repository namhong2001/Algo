#include <iostream>
#include <set>
#include <vector>
#include <algorithm> 

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int N, G, M;
		cin >> N >> G >> M;
		vector<int> H(G);
		vector<string> D(G);
		for (int i=0; i<G; ++i) {
			cin >> H[i] >> D[i];
			H[i]--;
		}
		vector<int> pos(G);
		vector<pii> occupied;
		vector<vector<bool>> has_dir(N, vector<bool>(2, false));
		for (int i=0; i<G; ++i) {
			if (D[i] == "C") {
				pos[i] = (H[i] + M) % N;
			} else {
				pos[i] = ((H[i] - M) % N + N) % N;
			}
			occupied.emplace_back(pos[i], i);
			int dir = D[i] == "C" ? 0 : 1; 
			has_dir[pos[i]][dir] = true;
		}
		sort(occupied.begin(), occupied.end());
		vector<int> ans(G);
		for (int i=0; i<G; ++i) {
			int cur = occupied[i].second; 
			string cur_d = D[cur];
			int cur_p = occupied[i].first; 
			if (cur_d == "C") {
				auto lower = lower_bound(occupied.begin(), occupied.end(), make_pair(cur_p, -1));
				auto pre = lower;
				if (lower == occupied.begin()) {
					pre = prev(occupied.end());
				} else {
					pre = prev(lower);
				} 
				int pre_p = pre->first;
				int dist = 0;
				if (pre_p < cur_p) {
					dist = cur_p - pre_p;
				} else {
					dist = cur_p + N - pre_p;
				}
				if (has_dir[pre_p][1]) { 
					ans[cur] = dist/2 + 1;;
				} else {
					ans[cur] = dist;
				}
				ans[cur] = min(ans[cur], M+1);
			} else {
				auto upper = upper_bound(occupied.begin(), occupied.end(), make_pair(cur_p, (int)1e5+1));
				auto next = upper;
				if (upper == occupied.end()) { 
					next = occupied.begin();
				} else {
					next = upper;
				} 
				int next_p = next->first;
				int dist = 0;
				if (cur_p < next_p) {
					dist = next_p - cur_p;
				} else {
					dist = next_p + N - cur_p;
				}
				if (has_dir[next_p][0]) { 
					ans[cur] = dist/2 + 1;
				} else {
					ans[cur] = dist;
				}
				ans[cur] = min(ans[cur], M+1);
			}
		} 
		cout << "Case #" << t << ": ";
		for (int a : ans) {
			cout << a << ' ';
		}
		cout << '\n';
	} 
	return 0;
}
