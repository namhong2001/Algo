#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> hs(n);
		for (int i=0; i<n; ++i) cin >> hs[i];
		vector<int> left(n);
		vector<int> right(n);
		stack<int> st;
		for (int i=0; i<n; ++i) {
			if (st.empty() || hs[st.top()] < hs[i]) left[i] = i;
			else {
				while(!st.empty() && hs[st.top()] >= hs[i]) st.pop();
				if (st.empty()) left[i] = 0;
				else left[i] = st.top()+1;
			}
			st.push(i);
		}
		st = stack<int>();
		for (int i=n-1; i>=0; --i) {
			if (st.empty() || hs[st.top()] < hs[i]) right[i] = i;
			else {
				while(!st.empty() && hs[st.top()] >= hs[i]) st.pop();
				if (st.empty()) right[i] = n-1;
				else right[i] = st.top()-1;
			}
			st.push(i);
		}
		ll ans = 0; 
		for (int i=0; i<n; ++i) {
			ans = max(ans, 1ll*hs[i]*(right[i]-left[i]+1));
		}
		cout << ans << endl; 
	}
	return 0;
} 
