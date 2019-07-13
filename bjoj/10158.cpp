#include <iostream>

using namespace std;

int next(int width, int p, int t) {
	if (p + t <= width) return p + t;
	t -= width-p;
	if (t/width % 2 == 0) return width - t % width;
	else return 0 + t % width;
} 

int main() {
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;
	cout << next(w, p, t) << ' ' << next(h, q, t) << endl;
	return 0;
} 
