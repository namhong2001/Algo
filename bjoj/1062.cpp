#include <iostream>

using namespace std;

int N, K;
int word[50]; 

int get_cnt(int state) {
	int ret = 0;
	for (int i=0; i<N; ++i) {
		if ((word[i] & state) == word[i]) ret++;
	}
	return ret;
} 

int ans = 0;
void solve(int state, int here) {
	if (__builtin_popcount(state) == K) {
		ans = max(ans, get_cnt(state));
		return;
	}
	if (here == 26) return; 
	if (state & 1<<here) {
		solve(state, here+1);
	} else {
		solve(state, here+1);
		solve(state|1<<here, here+1);
	} 
} 

int main() {
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s;
		int w = 0;
		for (char a : s) {
			w |= 1<<(a-'a');
		}
		word[i] = w;
	} 
	int state = 0;
	state |= 1<<('a'-'a');
	state |= 1<<('c'-'a');
	state |= 1<<('i'-'a');
	state |= 1<<('n'-'a');
	state |= 1<<('t'-'a');
	solve(state, 0);
	cout << ans;
	return 0;
} 
