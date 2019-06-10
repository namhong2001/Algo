#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>


using namespace std;

typedef tuple<int,int,int> tiii; 

vector<vector<int>> board;
bool cached[46][21];
vector<int> comb[46][21];

vector<int> st_to_vector(int status) {
	vector<int> ret;
	for (int i=1; i<=9; ++i) {
		if (status & 1<<i) ret.push_back(i);
	}
	return ret;
} 

vector<int> get_comb(int sum, int cnt, int used) { 
	if (cached[sum][cnt]) {
		vector<int> tmp = comb[sum][cnt];
		vector<int> ret;
		for (int a : tmp) {
			if (a & used) continue;
			ret.push_back(a);
		}
		return ret;
	} 
	vector<int> ret;
	if (cnt == 1) {
		if (1 <= sum && sum <= 9 && (used & 1<<sum) == 0) {
			ret = {1<<sum};
		} 
		return ret; 
	} else { 
		for (int i=1; i<=9; ++i) {
			if (used & 1<<i) continue;
			if (sum-i <= 0) break;
			vector<int> child = get_comb(sum-i, cnt-1, used|1<<i);
			for (int c : child) {
				c |= 1<<i; 
				ret.push_back(c);
			}
		} 
	}
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	if (used == 0) {
		cached[sum][cnt] = true;
		comb[sum][cnt] = ret;
	}
	return ret;
} 

int wt_cnt[21][21][2]; 
int white_cnt(int x, int y, int dir) { 
	int &ret = wt_cnt[x][y][dir];
	if (ret != -1 ) return ret; 
	ret = 0;
	if (dir == 0) {
		while (++y < board[0].size() && board[x][y] != 0) ret++;
	} else {
		while (++x < board.size() && board[x][y] != 0) ret++;
	}
	return ret;
} 

bool solve(vector<tiii> &ho, int ho_index, vector<tiii> &ve, int ve_index) { 
	//cerr << ho_index << ' ' << ve_index << endl;
	/*
	for (auto b : board) {
		for (auto a : b) {
			cerr << a << ' ';
		}
		cerr << endl;
	}
	cerr << endl;
	*/
	if (ho_index == (int)ho.size()-1 && ve_index == (int)ve.size()-1) return true;
	if ((ho_index <= ve_index && ho_index < (int)ho.size()-1) || ve_index == (int)ve.size()-1) {
		ho_index++;
		int x, y, sum;
		tie(x, y, sum) = ho[ho_index];
		int cnt = white_cnt(x, y, 0);
		vector<int> cmb = get_comb(sum, cnt, 0); 
		for (int c_st : cmb) { 
			vector<int> c = st_to_vector(c_st);
			do {
				bool possible = true;
				for (int i=0; i<cnt; ++i) { 
					int ny = y+i+1;
					if (board[x][ny] != -1 && board[x][ny] != c[i]) { 
						possible = false;
						break;
					} 
					for (int nx = x-1; nx >= 0; --nx) {
						if (board[nx][ny] == 0) break;
						if (board[nx][ny] == c[i]) {
							possible = false;
							break;
						}
					}
					if (possible == false) break; 
					for (int nx = x+1; nx < board.size(); ++nx) {
						if (board[nx][ny] == 0) break;
						if (board[nx][ny] == c[i]) {
							possible = false;
							break;
						}
					}
					if (possible == false) break; 
				}
				if (!possible) continue; 

				vector<int> used;
				for (int i=0; i<cnt; ++i) { 
					if (board[x][y+i+1] == -1) {
						used.push_back(i);
						board[x][y+i+1] = c[i];
					} 
				} 
				if (solve(ho, ho_index, ve, ve_index)) return true;
				for (int i : used) {
					board[x][y+i+1] = -1;
				} 
			} while (next_permutation(c.begin(), c.end()));
		}
	} else {
		ve_index++;
		int x, y, sum;
		tie(x, y, sum) = ve[ve_index];
		int cnt = white_cnt(x, y, 1);
		vector<int> cmb = get_comb(sum, cnt, 0); 
		for (int c_st : cmb) {
			vector<int> c = st_to_vector(c_st);
			do {
				bool possible = true;
				for (int i=0; i<cnt; ++i) { 
					int nx = x+i+1;
					if (board[nx][y] != -1 && board[nx][y] != c[i]) { 
						possible = false;
						break;
					}
					for (int ny = y-1; ny >= 0; --ny) {
						if (board[nx][ny] == 0) break;
						if (board[nx][ny] == c[i]) {
							possible = false;
							break;
						}
					}
					if (possible == false) break; 
					for (int ny = y+1; ny < board[0].size(); ++ny) {
						if (board[nx][ny] == 0) break;
						if (board[nx][ny] == c[i]) {
							possible = false;
							break;
						}
					}
					if (possible == false) break; 
				}
				if (!possible) continue; 

				vector<int> used;
				for (int i=0; i<cnt; ++i) { 
					if (board[x+i+1][y] == -1) {
						used.push_back(i);
						board[x+i+1][y] = c[i];
					} 
				} 
				if (solve(ho, ho_index, ve, ve_index)) return true;
				for (int i : used) {
					board[x+i+1][y] = -1;
				} 
			} while (next_permutation(c.begin(), c.end()));
		}
	}
	return false;
} 

int main() { 
	int T;
	cin >> T; 
	while (T--) {
		memset(wt_cnt, -1, sizeof(wt_cnt));
		int n;
		cin >> n;
		board.assign(n, vector<int>(n));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cin >> board[i][j];
				board[i][j] *= -1; 
			}
		}
		int q;
		cin >> q;
		vector<tiii> horizontal;
		vector<tiii> vertical;
		while (q--) {
			int x, y, dir, sum;
			cin >> x >> y >> dir >> sum;
			x--, y--;
			if (dir == 0) {
				horizontal.emplace_back(x, y, sum);
			} else {
				vertical.emplace_back(x, y, sum);
			}
		}
		sort(horizontal.begin(), horizontal.end());
		sort(vertical.begin(), vertical.end()); 
		/*
		vector<int> cmb = get_comb(23, 3, 0);
		for (int c : cmb) {
			vector<int> c_vec = st_to_vector(c);
			cerr << "{";
			for (auto a : c_vec) {
				cerr << a << ", ";
			}
			cerr << "}" << endl;
		}
		cerr << endl;
		*/
		solve(horizontal, -1, vertical, -1);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
} 
