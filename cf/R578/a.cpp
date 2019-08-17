#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<bool> occupied(10);
	for (auto c : s) {
		if (c == 'L') {
			for (int i=0; i<10; ++i) {
				if (!occupied[i]) {
					occupied[i] = true;
					break;
				}
			}
		} else if (c == 'R') {
			for (int i=9; i>=0; --i) {
				if (!occupied[i]) {
					occupied[i] = true;
					break;
				}
			}
		} else {
			occupied[c-'0'] = false;
		}
	}
	for (auto a : occupied) {
		if (a) cout << "1";
		else cout << "0";
	} 
	return 0;
}

