#include <iostream>

using namespace std;

int accumCnt(int N, int base) {
	int ret = 0;
	while(N) { 
		ret += N/base;
		N /= base;
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	int cntOf2 = accumCnt(N, 2);
	cntOf2 -= accumCnt(M, 2);
	cntOf2 -= accumCnt(N-M, 2);
	int cntOf5 = accumCnt(N, 5);
	cntOf5 -= accumCnt(M, 5);
	cntOf5 -= accumCnt(N-M, 5);
	cout << min(cntOf2, cntOf5); 
	return 0;
}

