#include <iostream>

using namespace std;

int board[5][5];
bool checked[5][5];

bool bingo() {
	int cnt = 0;
	for (int i=0; i<5; ++i) {
		int j = 0;
		for (; j<5; ++j) {
			if (!checked[i][j]) break;
		}
		if (j == 5) cnt++;
	}
	for (int i=0; i<5; ++i) {
		int j = 0;
		for (; j<5; ++j) {
			if (!checked[j][i]) break;
		}
		if (j == 5) cnt++;
	}
	int i=0;
	for (; i<5; ++i) { 
		if (!checked[i][i]) break;
	}
	if (i == 5) cnt++;
	i=0;
	for (; i<5; ++i) { 
		if (!checked[4-i][i]) break;
	}
	if (i == 5) cnt++;
	if (cnt >= 3) return true;
	return false;
} 

void check(int num) {
	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			if (board[i][j] == num) {
				checked[i][j] = true;
				return;
			}
		}
	}
}

int main() {
	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i=1; i<=25; ++i) {
		int a;
		cin >> a;
		check(a);
		if(bingo()) {
			cout << i;
			return 0;
		}
	} 
    return 0;
}

