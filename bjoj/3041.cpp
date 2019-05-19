#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


pair<int,int> origin_coord(char a) {
	if (a == '.') return {3, 3};
	int order = a - 'A';
	return {order/4, order%4};
}

int manhattan(const pair<int,int> &a, const pair<int,int> &b) {
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int main() {
	vector<string> board;
	for (int i=0; i<4; ++i) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	int ans = 0;
	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			if (board[i][j] == '.') continue;
			ans += manhattan({i, j}, origin_coord(board[i][j]));
		}
	}
	cout << ans << endl;
	return 0;
} 
