#include <iostream>
#include <cstring>

using namespace std;

char ans[81];

bool check(int last) {
	int size = 1;
	while (true) {
		int as = last - 2*size + 1; 
		int bs = last - size + 1;
		if (as < 0) return true;
		int i;
		for (i=0; i<size; ++i) {
			if (ans[as+i] != ans[bs+i]) break;
		}
		if (i == size) return false;
		size++;
	}
}

int N;
bool dfs(int here, char prev) {
	if (here == N) return true;
	const char cand[3] = {'1', '2', '3'};
	for (int i=0; i<3; ++i) {
		if (cand[i] != prev) {
			ans[here] = cand[i];
			if (check(here)) { 
				if (dfs(here+1, cand[i])) return true;
			}
		}
	}
	return false;
} 

int main() {
	cin >> N;
	memset(ans, 0, sizeof(ans));
	dfs(0, 0);
	cout << ans << endl;
	return 0;
} 
