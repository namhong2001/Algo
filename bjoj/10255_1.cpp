#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int square_x[2];
		int square_y[2];
		for (int i=0; i<2; ++i) {
			cin >> square_x[i] >> square_y[i];
		}
		int xs[2];
		int ys[2];
		for (int i=0; i<2; ++i) {
			cin >> xs[i] >> ys[i];
		}
		if (xs[0] == xs[1]) {
			int x = xs[0];
			if (x == square_x[0] || x == square_x[1]) {
				cout << 4 << '\n';
			} else if (square_x[0] < x && x < square_x[1])  {
				cout << 2 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else if (ys[0] == ys[1]) {
			int y = ys[0];
			if (y == square_y[0] || y == square_y[1]) {
				cout << 4 << '\n';
			} else if (square_y[0] < y && y < square_y[1])  {
				cout << 2 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else {
			int dx = xs[1] - xs[0];
			int dy = ys[1] - ys[0];
			double p1 = 1.0*(square_x[0] - xs[0])/dx;
			double y1 = ys[0] + p1*dy;
			double p2 = 1.0*(square_x[1] - xs[0])/dx;
			double y2 = ys[0] + p2*dy;
			if ((y1 < square_y[0] && y2 < square_y[0]) ||
					(y1 > square_y[1] && y2 > square_y[1])) {
				cout << 0 << '\n';
			} else if ((square_y[0] < y1 && y1 < square_y[1]) &&
					(square_y[0] < y2 && y2 < square_y[1])) {
				cout << 2 << '\n';
			} else {
				cout << 1 << '\n';
			}
		}
	}
	return 0;
}
