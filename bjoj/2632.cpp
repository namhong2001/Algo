#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std; 

typedef long long ll;

int main() {
	int S, M, N;
	cin >> S >> M >> N;
	int A[2000]; 
	int B[2000];
	for (int i=0; i<M; ++i) cin >> A[i];
	for (int i=0; i<M; ++i) A[i+M] = A[i];
	for (int i=0; i<N; ++i) cin >> B[i];
	for (int i=0; i<N; ++i) B[i+N] = B[i];
	unordered_map<int,int> A_cnt;
	unordered_map<int,int> B_cnt; 
	auto gen_cnt = [&](unordered_map<int,int> &cnt, int arr[], int end) { 
		for (int i=0; i<end; ++i) {
			int sum = 0;
			for (int j=i; j<i+end; ++j) {
				if (i > 0 && j == i+end-1) continue;
				sum += arr[j];
				if (cnt.find(sum) == cnt.end()) {
					cnt[sum] = 1;
				} else {
					cnt[sum]++; 
				}
			}
		} 
	};
	gen_cnt(A_cnt, A, M);
	gen_cnt(B_cnt, B, N);
	ll ans = 0;
	for (pair<const int,int> &a : A_cnt) {
		int asum = a.first;
		int acnt = a.second;
		int bsum = S-asum;
		if (B_cnt.find(bsum) == B_cnt.end()) continue;
		int bcnt = B_cnt[bsum];
		ans += 1ll * acnt * bcnt; 
	}
	for (pair<const int,int> &a : A_cnt) {
		if (a.first == S) ans += a.second;
	}
	for (pair<const int,int> &b : B_cnt) {
		if (b.first == S) ans += b.second;
	}
	cout << ans;
	return 0;
} 
