#include <iostream>
#include <vector>

using namespace std;

bool checkClock(vector<int> &arr, int N) {
	for (int i=0; i<N; ++i) {
		int j = (i+1) % N;
		if (arr[i] != N) {
			if (arr[j] != arr[i]+1) {
				return false;
			}
		}
	}
	return true;
}

bool checkCounterClock(vector<int> &arr, int N) {
	for (int i=N-1; i>=0; --i) {
		int j = (i-1+N) % N;
		if (arr[i] != N) {
			if (arr[j] != arr[i]+1) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int Q;
	cin >> Q;
	for (int i=0; i<Q; ++i) {
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i=0; i<N; ++i) {
			cin >> arr[i];
		}
		if (checkClock(arr, N) || checkCounterClock(arr, N)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} 
	return 0;
}

