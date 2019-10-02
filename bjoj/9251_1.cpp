#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	int N = A.size();
	int M = B.size();
	int d[M] = {};
	for (int i=0; i<N; ++i) {
		int cur = 0;
		for (int j=0; j<M; ++j) {
			int prev = d[j];
			if (A[i] == B[j]) d[j] = cur+1;
			cur = max(cur, prev);
		}
	}
	cout << *max_element(d, d+M); 
	return 0;
}

