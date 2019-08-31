#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	int N = 100000;
	for (int i=0; i<N; ++i) { 
		cout << (char)('A' + (rand() % 26));
	}
    cout << '\n';
    return 0;
}
