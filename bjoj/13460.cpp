#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

typedef vector<string> State; 

int N, M; 

State move(State &state, int type) {
	int rx, ry, bx, by;
	for (int i=1; i<N-1; ++i) {
		for (int j=1; j<M-1; ++j) {
			if (state[i][j] == 'R') rx = i, ry = j;
			else if (state[i][j] == 'B') bx = i, by = j;
		}
	} 
	State ret = state; 
	bool in_hole = false;
	while (true) {
		bool moved = false; 
		int nrx = rx+dx[type];
		int nry = ry+dy[type];
		int nbx = bx+dx[type];
		int nby = by+dy[type];
		if (!in_hole) {
			if (ret[nrx][nry] == '.') { 
				ret[nrx][nry] = 'R';
				ret[rx][ry] = '.';
				rx = nrx;
				ry = nry;
				moved = true;
			} else if (ret[nrx][nry] == 'O') { 
				ret[rx][ry] = '.';
				rx = nrx;
				ry = nry;
				in_hole = true;
			}
		}
		if (ret[nbx][nby] == '.') {
			ret[nbx][nby] = 'B';
			ret[bx][by] = '.';
			bx = nbx;
			by = nby;
			moved = true;
		} else if (ret[nbx][nby] == 'O') {
			ret[nbx][nby] = 'B';
			return ret;
		}
		if (!moved) break;
	} 
	if (in_hole) ret[rx][ry] = 'R';
	return ret; 
}

map<State,int> discovered;

int solve(State i_state) {
	int holex = -1, holey = -1;
	for (int i=1; i<N-1; ++i) {
		for (int j=1; j<M-1; ++j) {
			if (i_state[i][j] == 'O') {
				holex = i;
				holey = j;
				break;
			}
		}
		if (holex != -1) break;
	}

	queue<State> q;
	q.push(i_state);
	discovered[i_state] = 0;
	while (!q.empty()) {
		State here = q.front();
		q.pop();
		int cnt = discovered[here];
		if (cnt >= 10) break;
		
		for (int i=0; i<4; ++i) {
			State next = move(here, i); 

			if (next[holex][holey] == 'R') return cnt+1;
			if (next[holex][holey] != 'B' && discovered.find(next) == discovered.end()) {
				q.push(next);
				discovered[next] = cnt+1;
			}
		}
	}
	return -1;
} 

int main() {
	cin >> N >> M; 
	State in;
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s; 
		in.push_back(s);
	}
	cout << solve(in);
	return 0;
} 
