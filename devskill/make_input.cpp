#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	cout << 1 << endl;
	int N = 100;
	int Q = 5;
	cout << N << ' ' << Q << '\n';
	for (int i=0; i<N; ++i) { 
		cout << (rand() % 26) + 1 << ' ';
	}
    cout << '\n';
	for (int i=0; i<Q; ++i) {
		int s = (rand() % N) + 1;
		int e = (rand() % N) + 1;
		cout << min(s, e) << ' ' << max(s, e) << '\n';
	}
    return 0;
}
