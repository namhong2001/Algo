#include <iostream>
#include <set>

using namespace std;

const int INF = 1e6+1;
const int d[3] = {-1, 0, 1};

typedef pair<int,int> pii;
set<pii> targets;

int N; 
int board[50][50];

bool inrange(int x, int y) {
	return 0<=x && x<N && 0<=y && y<N; 
};

bool validate(int x, int y, int mmin, int mmax) {
	return inrange(x, y) && mmin <= board[x][y] && board[x][y] <= mmax;
}; 

int dfs(int x, int y, bool visited[50][50], int mmin, int mmax) {
	visited[x][y] = true; 
	int ret = 0;
	if (targets.find({x, y}) != targets.end()) ret++;
	for (int i=0; i<3; ++i) {
		int nx = x + d[i];
		for (int j=0; j<3; ++j) { 
			int ny = y + d[j]; 
			if (validate(nx, ny, mmin, mmax) && !visited[nx][ny]) {
				ret += dfs(nx, ny, visited, mmin, mmax);
			}
		}
	}
	return ret;
};

bool decision(int mmin, int mmax) {
	bool visited[50][50] = {};
	return dfs(targets.begin()->first, targets.begin()->second, visited, mmin, mmax) == (int)targets.size();
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s; 
		for (int j=0; j<N; ++j) {
			if (s[j] == 'K' || s[j] == 'P') targets.emplace(i, j);
		}
	}
	int target_min = INF, target_max = -1;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> board[i][j];
			if (targets.find({i, j}) != targets.end()) {
				target_min = min(target_min, board[i][j]);
				target_max = max(target_max, board[i][j]);
			}
		} 
	} 

	int l = 0, r = target_min+1;
	while (l+1<r) {
		int mid = (l+r)/2;
		if (decision(mid, INF)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int lb = l;

	l = target_max-1, r = INF;
	while (l+1<r) {
		int mid = (l+r)/2;
		if (decision(lb, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	int ans = r - lb;
	lb--;
	while (target_max - lb  < ans) {
		l = target_max-1, r = INF;
		while (l+1<r) {
			int mid = (l+r)/2;
			if (decision(lb, mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ans = min(ans, r-lb);
		lb--;
	}
	cout << ans << endl;
	return 0;
} 
