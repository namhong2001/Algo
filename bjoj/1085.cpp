#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min({x, y, abs(w-x), abs(y-h)}); 
	return 0;
}

