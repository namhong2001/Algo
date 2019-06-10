#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 20; 
const int BLACK = 0;
const int WHITE = 1;

int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int q, sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN];
int candidates[10][46][1024];

int getSize(int mask) {
	return __builtin_popcount(mask);
}

int getSum(int mask) {
	int sum = 0;
	for (int i=1; i<=9; ++i) {
		if (mask & 1<<i) sum += i;
	}
	return sum;
} 

void generateCandidates() {
	memset(candidates, 0, sizeof(candidates));
	for (int set=0; set<1024; set+=2) {
		int l = getSize(set);
		int s = getSum(set);
		int subset = set;
		while(true) {
			candidates[l][s][subset] |= (set & ~subset);
			if (subset == 0) break;
			subset = (subset - 1) & set;
		}
	}
} 

void put(int x, int y, int val) {
	for (int h=0; h<2; ++h) {
		known[hint[x][y][h]] += (1<<val);
	}
	value[x][y] = val;
}
void remove(int x, int y, int val) {
	for (int h=0; h<2; ++h) {
		known[hint[x][y][h]] -= (1<<val);
	}
	value[x][y] = 0; 
}

int getCandHint(int hint) {
	return candidates[length[hint]][sum[hint]][known[hint]];
}

int getCandCoord(int x, int y) {
	return getCandHint(hint[x][y][0]) & getCandHint(hint[x][y][1]);
}

void printSolution() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (color[i][j] == BLACK) {
				cout << BLACK << ' ';
			} else {
				cout << value[i][j] << ' ';
			}
		}
		cout << endl;
	}
} 

bool search() {
	int x=-1, y=-1, minCands = 1023;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (color[i][j] == WHITE && value[i][j] == 0) {
				int cands = getCandCoord(i, j);
				if (getSize(minCands) > getSize(cands)) {
					minCands = cands;
					x = i; 
					y = j;
				}
			}
		}
	}
	if (minCands == 0) return false;
	if (y == -1) {
		printSolution();
		return true;
	}
	for (int val=1; val<=9; ++val) {
		if (minCands & (1<<val)) {
			put(x, y, val);
			if (search()) return true;
			remove(x, y, val);
		}
	}
	return false;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(color, 0, sizeof(color));
		memset(value, 0, sizeof(value));
		memset(hint, 0, sizeof(hint));
		memset(sum, 0, sizeof(sum));
		memset(length, 0, sizeof(length));
		memset(known, 0, sizeof(known));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cin >> color[i][j];
			}
		}
		cin >> q;
		for (int i=0; i<q; ++i) {
			int x, y, dir, s;
			cin >> x >> y >> dir >> s;
			x--, y--;
			sum[i] = s;
			int l = 0;
			if (dir == 0) {
				for (int ny=y+1; ny<n; ++ny) {
					if (color[x][ny] == WHITE) {
						l++;
						hint[x][ny][dir] = i;
					} 
					else break;
				}
			} else { 
				for (int nx=x+1; nx<n; ++nx) {
					if (color[nx][y] == WHITE) {
						l++;
						hint[nx][y][dir] = i;
					}
					else break;
				}
			} 
			length[i] = l;
		}
		generateCandidates();
		search(); 
	}
	return 0;
} 
