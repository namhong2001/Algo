#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;


int n;
vector<vector<int>> d;
vector<vector<int>> cost;

int get_min(int stat, int step) {
	if (step == 0) return 0;
	int &ret = d[step][stat];
	if (ret != -1) return ret;
	ret = INF;
	for (int i=0; i<n; ++i) {
		if ((stat & 1<<i) == 0) {
			int c = INF;
			for (int j=0; j<n; ++j) {
				if (i == j) continue;
				if (stat & 1<<j) c = min(c, cost[j][i]);
			}
			ret = min(ret, get_min(stat | 1<<i, step-1) + c);
		}
	}
	return ret;
} 

int main() {
	cin >> n;
	cost.assign(n, vector<int>(n, 0));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> cost[i][j];
		}
	}
	string s;
	cin >> s;
	int st = 0;
	int ycnt = 0;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'Y') {
			st |= 1<<i;
			ycnt++;
		}
	}
	int p;
	cin >> p;
	int needcnt = p-ycnt; 
	if (needcnt <= 0) { 
		cout << 0 << endl;
		return 0;
	}
	if (ycnt == 0) {
		cout << -1 << endl;
		return 0;
	}
	d.assign(needcnt+1, vector<int>(1<<n, -1));
	cout << get_min(st, needcnt) << endl;
	return 0;
} 
