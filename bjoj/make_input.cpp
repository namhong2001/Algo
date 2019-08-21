#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	int N = 20;
	cout << N << endl;
	for (int i=0; i<N; ++i) {
		cout << rand() % 1000 << ' ';
	}
    cout << '\n';
    return 0;
}
