#include <iostream>

using namespace std;


int main() {
	int B, G, N; 
	cin >> B >> G >> N;
	int cnt = 0;
	for (int i=0; i<=N; ++i) {
		if (i <= B && N-i <= G) cnt++; 
	}
	cout << cnt;
	return 0;
}

