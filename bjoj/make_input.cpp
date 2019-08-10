#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	cout << 1 << '\n';
	int square[4]; 
    for (int i=0; i<4; ++i) {
		square[i] = rand() % 20000 - 10000;
    }
	sort(square, square+4);
    for (int i=0; i<4; ++i) {
		cout << square[i] << ' ';
    }
	cout << '\n';

    for (int i=0; i<4; ++i) {
		cout << (rand() % 20000 - 10000) << ' ';
    } 
    cout << ' ';
    return 0;
}
