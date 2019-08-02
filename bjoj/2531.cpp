#include <iostream>
#include <map>
#include <vector>

using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, D, K, C;
	cin >> N >> D >> K >> C; 
	vector<int> in(2*N); 
	map<int,int> cnt;
	for (int i=0; i<N; ++i) {
		cin >> in[i];
	}
	copy(in.begin(), in.begin()+N, in.begin()+N); 
	int ans = 0; 
	int types = 0; 
	for (int i=0; i<N+K; ++i) {
		int t = in[i];
		cnt[t]++;
		if (cnt[t] == 1) types++; 
		if (i>=K) { 
			cnt[in[i-K]]--;
			if (cnt[in[i-K]] == 0) types--;
		}
		if (cnt[C]) ans = max(ans, types);
		else ans = max(ans, types+1); 
	}
	cout << ans << endl;
} 
