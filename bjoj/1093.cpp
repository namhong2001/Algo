#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max(); 
typedef pair<int,int> pii; 

void debug(vector<pii> &A) {
	for (auto a : A) {
		cerr << "{" << a.first << ", " << a.second << "}" << endl;
	}
}

int main() {
	int N;
	cin >> N;
	int p[N+1];
	for (int i=1; i<=N; ++i) cin >> p[i];
	int v[N+1];
	for (int i=1; i<=N; ++i) cin >> v[i];
	int K, M;
	cin >> K >> M;
	int seed_money = 0;
	for (int i=0; i<M; ++i) {
		int a;
		cin >> a;
		a++;
		seed_money += p[a];
	}
	vector<pii> A = {{0, 0}}, B = {{0, 0}}; // value, price
	auto add = [](vector<pii> &A, int p, int v) {
		int sz = A.size();
		for (int j=0; j<sz; ++j) {
			A.emplace_back(A[j].first + v, A[j].second + p);
		}
	}; 
	for (int i=1; i<=N; ++i) { 
		if (i <= N/2) add(A, p[i], v[i]);
		else add(B, p[i], v[i]);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	auto filter = [](vector<pii> &A) { 
		vector<pii> ret;
		for (auto &a : A) {
			while (!ret.empty() && ret.back().second >= a.second) ret.pop_back();
			ret.push_back(a);
		}
		return ret;
	};
	A = filter(A);
	B = filter(B); 
	int ans = INF;
	for (auto &a : A) {
		auto lower = lower_bound(B.begin(), B.end(), pii {K-a.first, 0});
		if (lower != B.end()) ans = min(ans, a.second + lower->second);
	}
	if (ans == INF) cout << -1;
	else cout << max(ans-seed_money, 0); 
	return 0;
}

