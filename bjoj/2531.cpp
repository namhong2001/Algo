#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int,int> cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, D, K, C;
	cin >> N >> D >> K >> C; 
	int ans = 0;
	vector<int> in(N); 
	int types = 0;
	for (int i=0; i<N; ++i) {
		cin >> in[i]; 
		cnt[in[i]]++;
		if (cnt[in[i]] == 1) types++; 
		if (cnt[C]) ans = max(ans, types);
		else ans = max(ans, types+1); 
		if (i>=K) { 
			cnt[in[i-K]]--;
			if (cnt[in[i-K]] == 0) types--;
		}
	}
	cout << ans << endl;
} 
