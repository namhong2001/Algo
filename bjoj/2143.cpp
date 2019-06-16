#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std; 

typedef long long ll;

int main() {
	int T;
	cin >> T; 
	int N;
	cin >> N;
	int A[1000]; 
	int B[1000];
	for (int i=0; i<N; ++i) cin >> A[i];
	int M;
	cin >> M;
	for (int i=0; i<M; ++i) cin >> B[i];
	unordered_map<ll,int> A_cnt;
	unordered_map<ll,int> B_cnt; 
	auto gen_cnt = [&](unordered_map<ll,int> &cnt, int arr[], int end) { 
		for (int i=0; i<end; ++i) {
			ll sum = 0;
			for (int j=i; j<end; ++j) {
				sum += arr[j];
				if (cnt.find(sum) == cnt.end()) {
					cnt[sum] = 1;
				} else {
					cnt[sum]++; 
				}
			}
		} 
	};
	gen_cnt(A_cnt, A, N);
	gen_cnt(B_cnt, B, M);
	ll ans = 0;
	for (pair<const ll,int> &a : A_cnt) {
		ll asum = a.first;
		int acnt = a.second;
		ll bsum = T-asum; 
		if (B_cnt.find(bsum) == B_cnt.end()) continue;
		int bcnt = B_cnt[bsum];
		ans += 1ll * acnt * bcnt; 
	}
	cout << ans;
	return 0;
} 
