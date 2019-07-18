#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 101; 

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
} 

int N, M;
double K;
int get_index(int x, int y) {
	return x*2*M + y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> M >> N >> K;
	const int SIZE = 2*N*2*M;
	r.resize(SIZE);
	for (int i=0; i<SIZE; ++i) r[i]=i; 

	vector<vector<bool>> board(2*N, vector<bool>(2*M));
	vector<string> in(2*N+1);
	for (int i=0; i<2*N+1; ++i) { 
		cin >> in[i];
		if (i%2) {
			for (int j=1; j<2*M+1; j+=2) {
				int x = i-1;
				int y = j-1;
				board[x][y] = in[i][j] == 'B';
				board[x+1][y] = in[i][j] == 'B'; 
				board[x][y+1] = in[i][j] == 'B'; 
				board[x+1][y+1] = in[i][j] == 'B'; 
				if (in[i][j] == 'B') {
					u(get_index(x, y), get_index(x, y+1));
					u(get_index(x, y), get_index(x+1, y+1));
					u(get_index(x, y), get_index(x+1, y)); 
					for (int k=0; k<4; ++k) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						int nx = ni + dx[k] - 1;
						int ny = nj + dy[k] - 1;
						if (in[ni][nj] == '.' && board[nx][ny]) {
							u(get_index(x, y), get_index(nx, ny)); 
						} 
					}
				}
			}
		}
	}
	vector<bool> visited(SIZE, false);
	int x = 2*N, y = K*2; 
	int ans = 0;
	int ddx = -1, ddy = -1;
	/*
	for (int i=0; i<2*N; ++i) {
		for (int j=0; j<2*M; ++j) {
			if (board[i][j]) {
				cerr << f(get_index(i, j)) << ' ' ;
			} else {
				cerr << -1 << ' ';
			}
		}
		cerr << endl;
	}
	cerr << endl;
	*/
	do {
		int nx = x + ddx;
		int ny = y + ddy;
		if (nx == 0) ddx = -ddx;
		if (ny == 0 || ny == 2*M) ddy = -ddy;
		int targetx = min(nx, x);
		int targety = min(ny, y);
		int root = f(get_index(targetx, targety)); 
		if (board[targetx][targety] && !visited[root]) {
	//		cerr << targetx << ' ' << targety << ' ' << root << endl;
			ans++;
			visited[root] = true;
		} 
		x = nx;
		y = ny;
	} while (x < 2*N);
	cout << ans << endl;
} 
