#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector<vector<int>> adj; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	adj.assign(2*N, vector<int>());
	vector<pii> D(N);
	for (int i=0; i<N; ++i) {
		cin >> D[i].first;
		D[i].second = i*2;
	}
	sort(D.begin(), D.end(), greater<pii>());
	for (int i=0; i<N-1; ++i) { 
		int here = D[i].second;
		int next = D[i+1].second;
		adj[here].push_back(next);
	}
	for (int i=0; i<N; ++i) {
		int here = D[i].second;
		int pos = i + D[i].first; 
		if (pos == (int)D.size()) {
			D.emplace_back(0, here+1);
		}
		int pre = D[pos-1].second;
		adj[pre].push_back(here+1); 
	}
	for (int i=0; i<2*N; ++i) {
		for (int next : adj[i]) {
			cout << i+1 << ' ' << next+1 << '\n';
		}
	}
	return 0;
}

