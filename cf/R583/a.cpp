#include <iostream>

using namespace std; 

int main() {
	int N, D, E;
	cin >> N >> D >> E;
	E *= 5;
	int ans = N;
	for (int e=0; e<=N; e+=E) {
		ans = min(ans, (N-e) % D);
	}
	cout << ans;
	return 0;
}

