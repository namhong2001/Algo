#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std; 

const double INF = 987654321;

vector<double> coord;
vector<vector<double>> diff_sum;

double expected_coord(int first, int last, int ith) {
	return coord[first] + (coord[last]-coord[first]) * (ith-first)/(last-first);
}

double dist_diff(int first, int last, int ith) {
	return abs(coord[ith] - expected_coord(first, last, ith));
} 

vector<vector<double>> d;
double total_diff(int last, int cnt) { 
	if (last+1 < cnt) return INF;
	if (last+1 == cnt) return 0;
	if (cnt == 2) return diff_sum[0][last];

	double &ret = d[last][cnt];
	if (ret != -1) return ret;
	ret = INF;
	for (int l=last-1; l>0 && l+1 >= cnt-1; --l) {
		ret = min(ret, total_diff(l, cnt-1) + diff_sum[l][last]);
	}
	return ret;
} 

int main() {
	int t;
	cin >> t;
	while (t--) {
		int h, c;
		cin >> h >> c;
		coord.resize(h);
		for (int i=0; i<h; ++i) {
			cin >> coord[i];
		} 
		diff_sum.assign(h, vector<double>(h, 0));
		for (int i=0; i<h-1; ++i) {
			for (int j=i+1; j<h; ++j) {
				double &ds = diff_sum[i][j];
				for (int k=i+1; k<j; ++k) {
					ds += dist_diff(i, j, k);
				}
			}
		}
		d.assign(h, vector<double>(c+1, -1));
		double ans;
		if (h == c) ans = 0;
		else ans = total_diff(h-1, c) / h;
		cout << fixed << setprecision(4) << ans << endl;
	}
	return 0;
} 
