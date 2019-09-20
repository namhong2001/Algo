#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if (N > M) {
		N = min(N, 2*M);
	} else {
		M = min(M, 2*N);
	}
	cout << (N+M)/3; 
    return 0;
}

