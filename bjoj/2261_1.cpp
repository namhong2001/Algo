#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;


struct comp {
	bool operator < (
}
bool comp(const pii &A, const pii &B) {
	return A.second < B.second;
}

int get_dist(const pii &A, const pii &B) {
	return (A.first - B.first) * (A.first - B.first) +
		(A.second - B.second) * (A.second - B.second);
}

	

int main() {
	int N;
	cin >> N;
	vector<pii> coords(N);
	for (int i=0; i<N; ++i) {
		cin >> coords[i].first >> coords[i].second;
	}
	
	set<pii, comp> cands;
	int ans = get_dist(coords[0], coords[1]); 
	cands.insert(coords[0]);
	cands.insert(coords[1]);
	int left = 0;
	for (int i=2; i<N; ++i) {
		pii &here = coords[i];
		int radius = (int)ceil(sqrt(ans));
		int x_left = here.first-radius;
		while (left < i) {
			if (coords[left].first < x_left) {
				cands.erase(coords[left]);
				++left;
			} else {
				break;
			}
		}
		auto lower = cands.lower_bound({0, here.second-radius});
		auto upper = cands.upper_bound({0, here.second+radius});
		for (auto it = lower; it != upper; ++it) {
			pii &cand = *it;
			ans = min(ans, get_dist(here, cand));
		}
		cands.insert(here);
	}
	cout << ans;
	return 0;
} 
