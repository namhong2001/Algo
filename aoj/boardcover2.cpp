#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--) {
		int h, w, r, c;
		cin >> h >> w >> r >> c;
		vector<string> board(h);
		vector<string> block(r);
		for (int i=0; i<h; ++i) {
			cin >> board[i];
		}
		for (int i=0; i<r; ++i) {
			cin >> block[i];
		}
			

