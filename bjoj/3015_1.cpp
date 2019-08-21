#include <iostream> 
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int N;
	cin >> N;
	stack<pii> st;
	ll ans = 0;
	for (int i=0; i<N; ++i) {
		int h;
		cin >> h;
		pii cur(h, 1);
		for (; !st.empty() && st.top().first <= h; st.pop()) {
			ans += st.top().second;
			if (st.top().first == h) {
				cur.second += st.top().second;
			}
		}
		if (!st.empty()) ans++;
		st.push(cur);
	} 
	cout << ans << endl; 
	return 0;
}

