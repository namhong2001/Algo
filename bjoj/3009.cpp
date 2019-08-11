#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int,int> X, Y;
	for (int i=0; i<3; ++i) {
		int x, y;
		cin >> x >> y;
		X[x]++;
		Y[y]++;
	}
	for (auto x : X) {
		if (x.second == 1) {
			cout << x.first << ' ';
		}
	}
	for (auto y : Y) {
		if (y.second == 1) {
			cout << y.first << ' ';
		}
	} 
	return 0;
}

