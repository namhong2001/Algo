#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;

const int INF = 987654321;

vector<pii> coords;

int dist(int a, int b) {
	return (coords[b].first - coords[a].first)*(coords[b].first - coords[a].first) +
		(coords[b].second - coords[a].second)*(coords[b].second - coords[a].second);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	coords.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> coords[i].first >> coords[i].second;
	}
	sort(coords.begin(), coords.end());
	int ans = INF;
	for (int i=0; i<N; ++i) {
		const int radius = (int)ceil(sqrt(ans));
		const int y_upper = min(coords[i].second + radius, 10000);
		const int y_lower = max(coords[i].second - radius, -10000);
		const int x_upper = min(coords[i].first + radius, 10000);

		for (int j=i+1; j<N; ++j) {
			if (coords[j].second < y_lower || coords[j].second > y_upper) continue;
			if (coords[j].first > x_upper) break;
			ans = min(ans, dist(i, j));
		}
	}
	cout << ans;
	return 0;
} 
