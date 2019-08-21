#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int d[1001][2];
int increase(int index) {
	if (d[index][0]) return d[index][0];
	int &ret = d[index][0];
	ret = 1;
	for (int prev=0; prev<index; ++prev) {
		if (arr[prev] < arr[index]) {
			ret = max(ret, 1+increase(prev));
		}
	}
	return ret;
}
	
int decrease(int index) {
	if (d[index][1]) return d[index][1];
	int &ret = d[index][1];
	ret = 1;
	for (int next=index+1; next<N; ++next) {
		if (arr[index] > arr[next]) {
			ret = max(ret, 1+decrease(next));
		}
	}
	return ret;
}


int main() {
	cin >> N;
	arr.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	int ans = 0; 
	for (int i=0; i<N; ++i) {
		int bitonic = increase(i) + decrease(i) - 1;
		ans = max(ans, bitonic); 
	}
	cout << ans << endl; 
	return 0;
}

