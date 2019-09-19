#include <iostream>

using namespace std;

int W, H, N; 

int shortest(int adir, int adist, int bdir, int bdist) {
	if (adir == bdir) return abs(adist - bdist);
	if (adir <= 2 && bdir <= 2) return H + min(adist + bdist, 2*W - (adist + bdist)); 
	if (adir >= 3 && bdir >= 3) return W + min(adist + bdist, 2*H - (adist + bdist)); 
	if (adir <= 2) {
		int ret = 0;
		if (adir == 1) ret += bdist;
		else ret += H-bdist;

		if (bdir == 3) ret += adist;
		else ret += W-adist;
		return ret;
	} else {
		return shortest(bdir, bdist, adir, adist);
	} 
} 

int main() {
	cin >> W >> H >> N;
	int dir[N];
	int dist[N];
	for (int i=0; i<N; ++i) { 
		cin >> dir[i] >> dist[i];
	}
	int xdir, xdist;
	cin >> xdir >> xdist;
	int ans = 0;
	for (int i=0; i<N; ++i) {
		ans += shortest(dir[i], dist[i], xdir, xdist);
	}
	cout << ans; 
	return 0;
}

