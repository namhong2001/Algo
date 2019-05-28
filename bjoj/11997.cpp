#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int INF = 987654321;

typedef pair<int,int> pii;

int main() {
	int n;
	cin >> n;
	vector<pii> coords;
	for (int i=0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		coords.push_back({x,y});
	}
	auto comp = [&](const pii &A, const pii &B) {
		return A.first < B.first && A.second < B.second;
	};
	sort(coords.begin(), coords.end(), comp);
	int ans = INF;
	for (int i=0; i<=1e6; i+=2) {
		int l=0, r=1e6;
		while (l<r) {
			int mid = (l+r)/2;
			auto it1 = lower_bound(coords.begin(), coords.end(), make_pair(i, 1e6), comp); 
			auto it2 = lower_bound(coords.begin(), coords.end(), make_pair(1e6, mid), comp); 
			auto it3 = lower_bound(coords.begin(), coords.end(), make_pair(i, mid), comp); 
			int cnt_it1 = distance(coords.begin(), it1);
			int cnt_it2 = distance(coords.begin(), it2);
			int cnt_it3 = distance(coords.begin(), it3);
			int left_top = cnt_it3;
			int left_bottom = cnt_it2 - cnt_it3;
			int right_top = cnt_it1 - cnt_it3;
			int right_bottom = n - cnt_it2 - cnt_it1 + cnt_it3;
			int left_max = max(left_top, left_bottom);
			int right_max = max(right_top, right_bottom);
			if (left_max == right_max) {
				ans = min(ans, left_max);
				break;
			} else if (left_max > right_max) {
				ans = min(ans, left_max);
				r = mid-1;
			} else {
				ans = min(ans, right_max);
				l = mid+1;
			}
		} 
	}
	cout << ans << endl; 
	return 0;
} 
