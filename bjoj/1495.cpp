#include <iostream>

using namespace std;

const int INF = 987654321;

int P[101];
int N, S, M;

bool visited[101][1001];
int ans = -1;
void solve(int nth, int volume) {
	if (volume > M || volume < 0) return; 
	if (visited[nth][volume]) return;
	visited[nth][volume] = true;
	if (nth == N) {
		ans = max(ans, volume);
		return;
	} 
	solve(nth+1, volume + P[nth]);
	solve(nth+1, volume - P[nth]);
} 

int main() {
	cin >> N >> S >> M;
	for (int i=0; i<N; ++i) {
		cin >> P[i];
	}
	solve(0, S);
	cout << ans; 
	return 0;
}

