#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
    srand(time(0));
	cout << 1 << endl;
	int S = rand() % 10000;
	int D = rand() % 10000;
	cout << D << ' ' << S << '\n';
	for (int i=0; i<S; ++i) {
		cout << rand() % 10000 << ' ' << rand() % 10000 << '\n';
	}
	for (int i=0; i<D; ++i) {
		cout << rand() % 100000000 << ' ' << rand() % 100000000 << '\n';
	}
    cout << '\n';
    return 0;
}
