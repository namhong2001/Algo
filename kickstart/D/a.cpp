#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int N, Q;
		cin >> N >> Q;
		vector<int> in(N); 
		set<int> odd, even;
		for (int i=0; i<N; ++i) { 
			cin >> in[i];
			if (__builtin_popcount(in[i]) % 2) {
				odd.insert(i);
			} else {
				even.insert(i);
			} 
		}
		vector<int> ans;
		for (int i=0; i<Q; ++i) {
			int index, val;
			cin >> index >> val;
			if (__builtin_popcount(in[index]) % 2) {
				odd.erase(index);
			} else {
				even.erase(index);
			}
			if (__builtin_popcount(val) % 2) {
				odd.insert(index);
			} else {
				even.insert(index);
			}
			int len = 0;
			if (odd.size() % 2 == 0) {
				len = N;
			} else {
				int e = *prev(odd.end()) - 1;
				len = max(len, e+1);
				int s = *odd.begin()+1;
				len = max(len, N-s);
			} 
			ans.push_back(len);
			in[index] = val;
		}
		cout << "Case #" << t << ": ";
		for (int a : ans) {
			cout << a << ' ';
		}
		cout << '\n';
	} 
	return 0;
}
