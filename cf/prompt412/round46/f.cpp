#include <iostream>

using namespace std;

int d[1e5+1][11];

int solve(int n, int k) {
	int &ret = d[n][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += solve(n-1, k-1

int main() {
	

	return 0;
}

