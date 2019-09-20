#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};


int N;
bool inrange(int x, int y) {
	return 0<=x && x<N && 0<=y && y<N;
}

int main() {
	cin >> N;
	vector<string> board(N);
	for (int i=0; i<N; ++i) {
		cin >> board[i];
	}
	bool isok = true;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			int cnt = 0;
			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (inrange(nx, ny) && board[nx][ny] == 'o') {
					cnt++;
				}
			}
			if (cnt % 2) {
				isok=false;
				break;
			}
		}
		if (!isok) break;
	}
	cout << (isok ? "YES" : "NO") << endl; 
	return 0;
}
