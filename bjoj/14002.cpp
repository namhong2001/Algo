#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	int arr[N+1];
	int P[N+1]; 
	int M[N+1];
	int L = 0;
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
		auto lower = lower_bound(M+1, M+L+1, arr[i]);
		if (lower != M+L+1) { 
			*lower = i;
			P[i] = M[lower-M-1];
		} else {
			L++;
			M[L] = i;
			P[i] = M[L-1];
		}
	} 
	cout << L << '\n';
	int index = M[L];
	for (int i=0; i<L; ++i) {
		cout << arr[index] << ' ';
		index = P[index];
	} 
	return 0;
}

