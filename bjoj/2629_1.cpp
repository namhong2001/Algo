#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int target;
vector<int> arr;

int d[30][15001]; // step, sum

int solve(int step, int sum) { 
	if (sum > 15000) return 0;
	if (step == N) {
		if (sum == 0) return 1;
		else return 0;
	}
	int &ret = d[step][sum];
	if (ret != -1) return ret; 
	return ret = solve(step+1, sum-arr[step]) | solve(step+1, sum) | solve(step+1, sum+arr[step]);
}

int main() {
	cin >> N;
	arr.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	int M;
	cin >> M;
	memset(d, -1, sizeof(d)); 
	for (int i=0; i<M; ++i) {
		int a;
		cin >> a;
		cout << (solve(0, a) == 1 ? "Y" : "N") << ' ';
	}
	return 0;
} 
