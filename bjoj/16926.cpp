#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int,int> pii;
int N, M, R;

pii nextPos(int x, int y) { 
	const int in = min({x, N-1-x, y, M-1-y});
	const int xmov = N - in*2 - 1;
	const int ymov = M - in*2 - 1;
	const int rot = (xmov+ymov)*2; 
	int add = R % rot; 
	const int xmin = in;
	const int xmax = N-1-in;
	const int ymin = in;
	const int ymax = M-1-in; 
	//cerr << "{" << x << ", " << y << "}" << ' ';
	while (add > 0) {
		if (x == xmax && y<ymax) { 
			int a = min(add, ymax-y);
			y += a;
			add -= a;
		} else if (x == xmin && y>ymin) { 
			int a = min(add, y-ymin);
			y -= a;
			add -= a;
		} else if (y == ymax && x>xmin) { 
			int a = min(add, x-xmin);
			x -= a;
			add -= a;
		} else if (y == ymin && x<xmax) { 
			int a = min(add, xmax-x);
			x += a;
			add -= a;
		}
	}
	//cerr << "{" << x << ", " << y << "}" << endl;
	return {x, y};
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M >> R;
	int board[N][M];
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cin >> board[i][j];
		}
	}
	int ans[N][M];
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			pii next = nextPos(i, j); 
			ans[next.first][next.second] = board[i][j];
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	} 
	return 0;
}

