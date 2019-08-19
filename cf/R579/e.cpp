#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N+2);
	arr[0] = 0;
	arr[N+1] = INF;
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int l = 1;
	while (l < N+2) {
		int r = l;
		while (arr[l] == arr[r]) {
			r++;
		}
		r--;
		int cnt = r-l+1;
		if (cnt >= 3) {
			if (arr[l-1] < arr[l]-1) {
				arr[l]--;
			}
			if (arr[r] < arr[r+1]-1) {
				arr[r]++;
			}
		} else if (cnt == 2) {
			if (arr[l-1] < arr[l]-1) {
				arr[l]--;
			} else if (arr[r] < arr[r+1]-1) {
				arr[r]++;
			}
		}
		l = r+1;
	} 
	for (auto a : arr) {
		cerr << a  << ' ';
	}
	cerr << endl;
	arr.erase(unique(arr.begin(), arr.end()), arr.end()); 
	
	cout << arr.size()-2 << endl; 
	return 0;
}

