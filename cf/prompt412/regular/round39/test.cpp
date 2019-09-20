#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(nullptr));
	int n = 1000;
	cout << n << endl;
	for (int i=0; i<n; ++i) {
		cout << rand() % (int)1e9 << ' ';
	}
	return 0;
}
