#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		vector<int> A(N);
		for (int i=0; i<N; ++i) {
			cin >> A[i];
		}
		int M; 
		cin >> M;
		vector<int> B(M);
		for (int i=0; i<M; ++i) {
			cin >> B[i];
		}
		int i = 0, j = 0;
		int asum = 0, bsum = 0;
		vector<int> ASUM;
		vector<int> BSUM;
		int ans = 0;
		while (i < N || j < M) { 
			if (i < N && j < M && A[i] == B[j]) {
				ans += A[i];
				ASUM.push_back(asum);
				BSUM.push_back(bsum);
				asum = 0;
				bsum = 0;
				i++, j++; 
			} else if (j == M || (i < N && j < M && A[i] < B[j])) {
				asum += A[i];
				i++;
			} else {
				bsum += B[j];
				j++;
			}
		}
		ASUM.push_back(asum); 
		BSUM.push_back(bsum);
		for (int i=0; i<(int)ASUM.size(); ++i) {
			ans += max(ASUM[i], BSUM[i]);
		}
		cout << ans << '\n';
	}
	return 0;
} 
