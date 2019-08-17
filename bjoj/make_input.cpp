#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	for (int i=0; i<6; ++i) {
		cout << (double)rand() / 100 << ' ';
	}
    cout << '\n';
    return 0;
}
