#include <iostream>
#include <vector>

using namespace std; 

typedef pair<int,char> pic;
typedef pair<int,int> pii;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n, 0));  // 0 : vacant, 1 : apple, 2 : sanke
	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}
	int l;
	cin >> l;
	int head_dir = 1; // 0: top, 1:right, 2: bottom, 3:left
	int tail_dir = 1;
	pii head = {0, 0};
	pii tail = {0, 0}; 
	vector<int> cd(2e4, 0);
	while (l--) {
		int x;
		string s;
		cin >> x >> s;
		if (s[0] == 'L') { 
			cd[x] = -1;
		} else {
			cd[x] = 1;
		}
	} 
	int time;
	int len = 1;
	for (time = 1; time<2e4; ++time) {
		head.first += dx[head_dir];
		head.second += dy[head_dir]; 
		if(head.first < 0 || head.first >= n || head.second < 0 || head.second >= n || board[head.first][head.second] == 2) {
			break;
		}

		if (board[head.first][head.second] == 1) {
			len++;
		} else { 
			board[tail.first][tail.second] = 0;
			tail.first += dx[tail_dir];
			tail.second += dy[tail_dir]; 
			tail_dir = (tail_dir + cd[time-len+1] + 4) % 4; 
		}

		board[head.first][head.second] = 2;
		head_dir = (head_dir + cd[time] + 4) % 4; 
	}
	cout << time;
	return 0;
} 
