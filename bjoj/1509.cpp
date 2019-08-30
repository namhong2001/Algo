#include <iostream>

using namespace std;

const int INF = 987654321;

int d[2500];
bool is_palin[2500][2500]; // s, e
string S; 
int N;

int solve(int e) {
	if (e < 0) return 0;
	if (e == 0) return 1;
	int &ret = d[e]; 
	if (ret) return ret;
	ret = INF;
	for (int s=0; s<=e; ++s) {
		if (is_palin[s][e]) {
			ret = min(ret, solve(s-1) + 1);
		}
	}
	return ret;
}

void add(int s, int e) {
	if (s < 0 || e >= N) return;
	if (S[s] == S[e]) {
		is_palin[s][e] = true;
		add(s-1, e+1);
	}
} 

void make_palin() {
	for (int i=0; i<N; ++i) {
		add(i, i);
		add(i, i+1);
	}
} 

int main() {
	cin >> S; 
	N = S.size();
	make_palin();
	cout << solve(N-1) << '\n';
	return 0;
}
