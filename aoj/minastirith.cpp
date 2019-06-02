#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 987654321;

typedef pair<double,double> pdd;

const double R = 8.0;
const double PI = acos(-1.0);

pdd get_range(double y, double x, double r) {
	double loc = atan2(y, x);
	double theta = asin(r/2.0/R)*2;
	loc = fmod(loc+2*PI, 2*PI);
	return {loc-theta, loc+theta};
} 


int solve_linear(double begin, double end, vector<pdd> &ranges) {
	int ans = 0;
	int index = 0;
	while (begin < end) {
		double cur_end = begin; 
		while (index < ranges.size() && ranges[index].first <= begin) {
			cur_end = max(cur_end, ranges[index].second);
			index++; 
		}
		if (cur_end == begin) return INF;
		begin = cur_end;
		ans++;
	}
	return ans;
} 

string solve_circle(vector<pdd> &ranges) { 
	int ans = INF;
	for (pdd &range : ranges) {
		if (range.first <= 0 || range.second >= 2*PI) {
			double begin = fmod(range.second, 2*PI);
			double end = fmod(range.first + 2*PI, 2*PI); 
			ans = min(ans, solve_linear(begin, end, ranges));
		}
	}
	if (ans == INF) return "IMPOSSIBLE";
	return to_string(ans+1);
} 

int main() {
	int C; 
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		vector<pdd> ranges;
		for (int i=0; i<n; ++i) {
			double y, x, r;
			cin >> y >> x >> r;
			ranges.push_back(get_range(y, x, r));
		}
		sort(ranges.begin(), ranges.end());
		cout << solve_circle(ranges) << endl;
	}
	return 0;
} 
