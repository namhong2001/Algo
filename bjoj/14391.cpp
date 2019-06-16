#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

vector<string> board(4); 
vector<int> d(1<<16, -1);
int N, M;

pii find_lt(int state) {
	int r = -1, c = -1;
	for (int i=0; i<N*M; ++i) {
		if (state & 1<<i) continue;

		r = i/M;
		c = i%M;
		break;
	}
	return {r, c};
}

int solve(int state) {
	if (state == (1<<N*M)-1) return 0;
	int &ret = d[state];
	if (ret != -1) return ret;
	int x, y;
	tie(x, y) = find_lt(state);
	ret = 0; 

	// to right
	int hstate = state; 
	string snum;
	for (int i=y; i<M; ++i) {
		if (hstate & 1<<(x*M+i)) break; 
		snum += board[x][i]; 
		int num = stoi(snum); 
		hstate |= 1<<(x*M+i);
		ret = max(ret, num + solve(hstate));
	}
		
	// to down
	int vstate = state; 
	snum = "";
	for (int i=x; i<N; ++i) {
		if (vstate & 1<<(i*M+y)) break; 
		snum += board[i][y]; 
		int num = stoi(snum);
		vstate |= 1<<(i*M+y);
		ret = max(ret, num + solve(vstate));
	}
	/*
	for (int i=0; i<(N*M); ++i) {
		if (state & 1<<i) cerr << 1 << ' ';
		else cerr << 0 << ' ';
		if ((i+1)%M == 0) cerr << endl;
	} 
	cerr << ret << endl;
	*/

	return ret;
} 

int main() {
	cin >> N >> M;
	for (int i=0; i<N; ++i) cin >> board[i];
	cout << solve(0);
	return 0;
} 
