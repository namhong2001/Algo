#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

typedef pair<int,int> pii; 

struct RMQ { // range minimum query
    vector<int> A;
    vector<vector<int>> B;
    RMQ() {};
    RMQ(vector<int> &A) {
        this->A = A;
        int logbound = floor(log2((double)A.size()));
        B = vector<vector<int>>(A.size(), vector<int>(logbound+1));
        for (int i=0; i<=logbound; ++i) {
            for (int j=0; j<A.size(); ++j) {
                if (i == 0) {
                    B[j][i] = j;
                } else {
                    int second_idx = min(j+(int)pow(2, i-1), (int)A.size()-1);
                    if (A[B[j][i-1]] <= A[B[second_idx][i-1]]) {
                        B[j][i] = B[j][i-1];
                    } else {
                        B[j][i] = B[second_idx][i-1];
                    }
                }
            }
        }
    }
    int query(int l, int r) { // inclusive
        int sz = r-l+1;
        int logsz = floor(log2((double)sz));
        if (A[B[l][logsz]] <= A[B[r-pow(2, logsz)+1][logsz]]) {
            return B[l][logsz];
        } else {
            return B[r-pow(2, logsz)+1][logsz];
        }
    }
};


int get_max(RMQ &rmq, int l, int r) {
	int here = rmq.query(l, r);
	int ret = rmq.A[here] * (r-l+1);
	//cerr << "get_max " << l << ' ' << r << ' ' << here << ' ' << rmq.A[here] << ' ' << ret <<  endl;
	if (here-1 >= l) {
		ret = max(ret, get_max(rmq, l, here-1));
	}
	if (here+1 <= r) {
		ret = max(ret, get_max(rmq, here+1, r));
	}
	return ret;
} 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int R, C, K;
		cin >> R >> C >> K;
		vector<vector<int>> board(R, vector<int>(C));
		vector<vector<int>> heights(R, vector<int>(C));
		for (int i=0; i<R; ++i) {
			for (int j=0; j<C; ++j) {
				cin >> board[i][j]; 
			}
		}
		for (int i=0; i<R; ++i) {
			map<int,int> s;
			int here = 0;
			for (int j=0; j<C; ++j) {
				if (s.find(board[i][j]) == s.end()) {
					s[board[i][j]] = 1;
				} else {
					s[board[i][j]]++;
				} 
				auto e = s.end();
				e--;
				while (e->first - s.begin()->first > K) {
					heights[i][here] = j-here;
					s[board[i][here]]--;
					if (s[board[i][here]] == 0) { 
						s.erase(board[i][here]);
					}
					here++;
					e = s.end();
					e--;
				}
			} 
			while (here < C) {
				heights[i][here] = C-here;
				here++;
			} 
			/* 
			for (int j=0; j<C; ++j) {
				cerr << heights[i][j] << ' ';
			}
			cerr << endl; 
			*/ 
		}
		int ans = 0;
		for (int j=0; j<C; ++j) {
			vector<int> arr(R);
			for (int i=0; i<R; ++i) {
				arr[i] = heights[i][j];
			}
			RMQ rmq(arr);
			//cerr << j << "th column" << endl;
			ans = max(ans, get_max(rmq, 0, arr.size()-1));
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
} 

