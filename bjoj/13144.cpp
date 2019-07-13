#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 1e5+1;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N;
	cin >> N; 
	ll ans = 0;
	vector<bool> occur(LIMIT, false);
	vector<int> arr(N);
	int l = 0;
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
		if (occur[arr[i]]) { 
			while (arr[l] != arr[i]) {
				ans += i - l;
				occur[arr[l]] = false;
				l++;
			}
			ans += i - l;
			occur[arr[l]] = false;
			l++;
		} 
		occur[arr[i]] = true;
	} 
	while (l<N) {
		ans += N-l;
		l++;
	}
	cout << ans << endl;
	return 0;
} 
