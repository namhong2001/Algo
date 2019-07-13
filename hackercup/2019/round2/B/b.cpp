#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

typedef pair<int,int> pii;

vector<int> r;
vector<int> cnt;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]); 
}
void u(int a, int b) {
	a = f(a), b = f(b);
	cnt[b] += cnt[a];
	cnt[a] = 0;
	r[a] = b; 
}

int N, M; 
vector<int> last;
void update_last() {
	last.assign(N+1, -1);
	priority_queue<pii, vector<pii>, greater<pii>> q; 
	q.push({-1, 0});
	last[0] = -2;
	while (!q.empty()) {
		pii here = q.top();
		q.pop();
		int index, sum;
		tie(index, sum) = here;
		if (last[sum] >= 0) continue; 
		if (last[sum] == -1) last[sum] = index; 
		for (int i=index+1; i<N; ++i) {
			if (cnt[i] > 0) {
				q.push({i, sum+cnt[i]});
			}
		}
	}
} 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> N >> M;
		r.resize(N);
		cnt.assign(N, 1);
		for (int i=0; i<N; ++i) r[i] = i; 
		for (int i=0; i<M; ++i) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			while (x < y) {
				u(x, y);
				x++, y--;
			}
		} 
		update_last(); 
		bool isone[N] = {};
		for (int i=N/2; i>=0; --i) {
			if (last[i] != -1) { 
				while (last[i] >= 0) {
					isone[last[i]] = true;
					i -= cnt[last[i]];
				}
				break;
			}
		}
		char ans[N+1] = {};
		for (int i=0; i<N; ++i) {
			if (isone[f(i)]) ans[i] = '1';
			else ans[i] = '0';
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}
