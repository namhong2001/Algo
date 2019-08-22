#include <iostream>

using namespace std;

int N;
int d[1001];
int arr[1001];
int solve(int index) { 
	if (d[index]) return d[index];
	int &ret = d[index];
	ret = arr[index];
	for (int next=index+1; next<N; ++next) {
		if (arr[index] < arr[next]) {
			ret = max(ret, arr[index] + solve(next));
		}
	}
	return ret;
} 

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	} 
	int ans = 0;
	for (int i=0; i<N; ++i) {
		ans = max(ans, solve(i));
	}
	cout << ans << endl;
	return 0;
} 
