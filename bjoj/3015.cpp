#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int> arr(N+2);
	vector<int> left_max(N+2, -1);
	vector<int> left_max_pos(N+2, 0);
	vector<int> right_max(N+2, -1);
	map<int, vector<int>> pos;
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
	}
	for (int i=1; i<=N; ++i) {
		if (arr[i] >= left_max[i-1]) { 
			left_max[i] = arr[i];
			left_max_pos[i] = i; 
		} else {
			left_max[i] = left_max[i-1];
			left_max_pos[i] = left_max_pos[i-1];
		} 
	}
	for (int i=N; i>=1; --i) {
		right_max[i] = max(right_max[i+1], arr[i]);
	}
	ll ans = 0;
	for (int i=1; i<=N; ++i) {
		int origin = ans;
		if (left_max[i-1] > arr[i]) ans++;
		if (right_max[i+1] > arr[i]) ans++;
		int lpos = left_max[i-1] > arr[i] ? left_max_pos[i-1] : 0;
		vector<int>& mypos = pos[arr[i]];
		cerr << lpos << ' ';
		ans += distance(upper_bound(mypos.begin(), mypos.end(), lpos), mypos.end());
		mypos.push_back(i);
		cerr << ans - origin << ' ' << endl; 
	}
	cerr << endl;
	cout << ans << '\n';
	return 0;
}

