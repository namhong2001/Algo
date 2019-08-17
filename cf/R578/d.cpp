#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K; 
	cin >> N >> K;
	int pos[N][2] = {};
	int pos2[N][2] = {};
	memset(pos, -1, sizeof(pos));
	memset(pos2, -1, sizeof(pos));
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s; 
		for (int j=0; j<N; ++j) {
			if (s[j] == 'B') {
				if (pos[i][0] == -1) pos[i][0] = j;
				if (pos2[j][0] == -1) pos2[j][0] = i;
				pos[i][1] = j;
				pos2[j][1] = i;
			}
		}
	} 
	int initial = 0;
	for (int i=0; i<N; ++i) {
		if (pos[i][0] == -1) initial++;
		if (pos2[i][0] == -1) initial++;
	} 
	bool rowOk[N][N] = {};
	bool colOk[N][N] = {};
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (pos[i][0] != -1 && (pos[i][0] >= j && pos[i][1] <= j+K-1)) rowOk[i][j] = true;
			if (pos2[j][0] != -1 && (pos2[j][0] >= i && pos2[j][1] <= i+K-1)) colOk[i][j] = true;
		}
	} 
	int rowCnt[N][N] = {};
	int colCnt[N][N] = {};
	for (int j=0; j<=N-K; ++j) {
		int low = 0, high = 0; 
		int cur = 0;
		for (int i=0; i<=N-K; ++i) { 
			while (high < i+K && high < N) {
				if (rowOk[high][j]) cur++;
				high++;
			}
			while (low < high-K) {
				if (rowOk[low][j]) cur--;
				low++;
			}
			rowCnt[i][j] = cur;
		}
	}
	/*
	for (int i=0; i<=N-K; ++i) {
		for (int j=0; j<=N-K; ++j) {
			cerr << rowCnt[i][j] << ' ';
		}
		cerr << endl;
	}
	*/
	for (int i=0; i<=N-K; ++i) {
		int low = 0, high = 0; 
		int cur = 0;
		for (int j=0; j<=N-K; ++j) { 
			while (high < j+K && high < N) {
				if (colOk[i][high]) cur++;
				high++;
			}
			while (low < high-K) {
				if (colOk[i][low]) cur--;
				low++;
			}
			colCnt[i][j] = cur;
		}
	}
	/*
	for (int i=0; i<=N-K; ++i) {
		for (int j=0; j<=N-K; ++j) {
			cerr << colCnt[i][j] << ' ';
		}
		cerr << endl;
	}
	*/ 
	int ans = 0;
	for (int i=0; i<=N-K; ++i) {
		for (int j=0; j<=N-K; ++j) {
			ans = max(ans, initial + rowCnt[i][j] + colCnt[i][j]);
		}
	}
	cout << ans << '\n'; 
	return 0;
}

