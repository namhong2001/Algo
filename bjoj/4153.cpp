#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int side[3];
		for (int i=0; i<3; ++i) {
			cin >> side[i];
		}
		if (side[0] == 0) break;
		sort(side, side+3);
		if (side[0]*side[0] + side[1]*side[1] == side[2]*side[2]) {
			cout << "right" << '\n';
		} else {
			cout << "wrong" << '\n';
		} 
	} 
	return 0;
}

