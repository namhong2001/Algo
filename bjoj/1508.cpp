#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e6;

string ans;
int N, M, K;
bool decision(vector<int> &pos, int limit) {
	ans = string(K, '0');
	int left = -INF;
	int cnt = 0;
	for (int i=0; i<K; ++i) {
		int p = pos[i];
		if (p-left >= limit) {
			cnt++;
			left = p;
			if (cnt <= M) {
				ans[i] = '1'; 
			}
		}
	}
	return cnt >= M;
} 

int main() {
	cin >> N >> M >> K;
	if (M >= K) {
		cout << string(K, '1') << endl;
		return 0;
	} 
	vector<int> pos(K);
	for (int i=0; i<K; ++i) {
		cin >> pos[i];
	}
	int l = 0, r = 1e6+1; // true, false
	while (l+1<r) {
		int mid = (l+r)/2;
		if (decision(pos, mid)) {
			l = mid;
		} else {
			r = mid;
		}
	} 
	decision(pos, l);
	cout << ans << endl;
	return 0; 
} 
