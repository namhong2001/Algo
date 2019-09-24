#include <iostream>
#include <vector>

using namespace std;

int fibo(int N) {
	vector<int> arr(N, 1);
	for (int i=2; i<N; ++i) {
		arr[i] = arr[i-2] + arr[i-1];
	}
	return arr[N-1];
}

int main() {
	int D, K;
	cin >> D >> K;
	int co_a = fibo(D-2);
	int co_b = fibo(D-1); 
	for (int i=1; i<K; ++i) {
		int a = i;
		int bb = K - co_a * a;
		if (bb % co_b == 0) {
			cout << a << '\n' << bb / co_b;
			return 0;
		}
	} 
    return 0;
}

