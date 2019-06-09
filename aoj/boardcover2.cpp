#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector<vector<pii>> rotations;
int block_size;
int h, w, r, c;
vector<string> board;
int covered[10][10]; 
int best;

vector<string> rotate(const vector<string> &arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i=0; i<arr.size(); ++i) {
		for (int j=0; j<arr[0].size(); ++j) {
			ret[j][arr.size()-i-1] = arr[i][j];
		}
	}
	return ret;
}

void generate_rotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot=0; rot<4; ++rot) {
		int x=-1, y=-1;
		for (int i=0; i<block.size(); ++i) {
			for (int j=0; j<block[i].size(); ++j) {
				if (block[i][j] == '#') {
					if (x == -1) {
						x = i;
						y = j;
					}
					rotations[rot].push_back({i-x, j-y});
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	block_size = rotations[0].size();
} 

bool set(int x, int y, const vector<pii> &block, int delta) {
	bool ret = true;
	for (const auto &p : block) {
		int nx = x+p.first;
		int ny = y+p.second;
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
			ret = false;
			continue;
		} 
		covered[nx][ny] += delta;
		if (covered[nx][ny] > 1) ret = false;
	}
	return ret;
} 

int max_expect(int remain_cnt) {
	return remain_cnt / block_size;
}


void search(int placed, int remain_cnt) {
	if (placed + max_expect(remain_cnt) <= best) return;
	int x=-1, y=-1;
	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			if (covered[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (y != -1) break;
	}

	if (y == -1) {
		best = max(best, placed);
		return;
	}

	for (int i=0; i<rotations.size(); ++i) {
		if (set(x, y, rotations[i], 1)) {
			search(placed+1, remain_cnt-block_size);
		}
		set(x, y, rotations[i], -1);
	}
	covered[x][y] = 1;
	search(placed, remain_cnt-1);
	covered[x][y] = 0;
}

int solve() {
	best = 0;
	int remain_cnt = 0; 
	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			covered[i][j] = board[i][j] == '#' ? 1 : 0;
			if (covered[i][j] == 0) remain_cnt++; 
		}
	} 
	search(0, remain_cnt);
	return best;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> h >> w >> r >> c;
		board.resize(h);
		vector<string> block(r);
		for (int i=0; i<h; ++i) {
			cin >> board[i];
		}
		for (int i=0; i<r; ++i) {
			cin >> block[i];
		} 
		generate_rotations(block);
		cout << solve() << endl;
	}
	return 0;
}
