#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
vector<int> psum;
vector<int> gcds;

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

bool solve(int sum, int index) { 
	if (sum == 0) return true;
	if (index == N) return false;
	int remain = psum[N] - psum[index];
	if (sum < -(remain) || sum > remain) return false;
	if (sum % gcds[index] != 0) return false; 
	return solve(sum+arr[index], index+1) || solve(sum, index+1) || solve(sum-arr[index], index+1);
}

int main() {
	cin >> N;
	arr.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	psum.assign(N+1, 0);
	for (int i=1; i<=N; ++i) {
		psum[i] = psum[i-1] + arr[i-1];
	}
	gcds.assign(N, 0);
	gcds[N-1] = arr[N-1];
	for (int i=N-2; i>=0; --i) {
		gcds[i] = gcd(gcds[i+1], arr[i]);
	}
	int M;
	cin >> M;
	for (int i=0; i<M; ++i) {
		int a;
		cin >> a; 
		cout << (solve(-a, 0) ? "Y" : "N") << ' ';
	}
	return 0;
} 
