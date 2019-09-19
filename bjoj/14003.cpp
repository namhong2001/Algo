#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	int arr[N+1] = {};
	int P[N+1] = {};
	int M[N+1] = {};
	int L = 0;
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
		auto lower = lower_bound(M+1, M+L+1, i, [&](const int &a, const int &b){return arr[a] < arr[b];});
		if (lower != M+L+1) { 
			*lower = i;
			P[i] = *prev(lower);
		} else {
			L++;
			M[L] = i;
			P[i] = M[L-1];
		}
	} 
	cout << L << '\n';
	vector<int> ans; 
	int i = M[L];
	while (i) {
		ans.push_back(arr[i]);
		i = P[i];
	} 
	reverse(ans.begin(), ans.end());
	for (int a : ans) {
		cout << a << ' ';
	} 
	return 0;
}

