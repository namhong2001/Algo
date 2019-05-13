#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> isprime(2000);

void make_isprime() {
	isprime.assign(2000, true);
	isprime[0] = isprime[1] = false;
	for (int i=2; i<isprime.size(); ++i) {
		if (isprime[i]) {
			for (int j=2; i*j < isprime.size(); ++j) {
				isprime[i*j] = false;
			}
		}
	}
}
	
vector<vector<int>> adj;
vector<int> amatch, bmatch;
int hide;

bool dfs(int here, vector<bool> &visited) {
	visited[here] = true;
	for (int there : adj[here]) {
		if (there == hide) continue;
		if (bmatch[there] == -1) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	}
	for (int there : adj[here]) {
		if (there == hide) continue;
		int p = bmatch[there];
		if (visited[p]) continue;	
		if (dfs(p, visited)) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int bimatch(int set_size) {
	amatch.assign(set_size, -1);
	bmatch.assign(set_size, -1);
	int cnt = 0;
	for (int i=1; i<set_size; ++i) {
		vector<bool> visited(set_size, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}

int main() {
	make_isprime();
	int n;
	cin >> n;
	vector<int> in(n);
	for (int i=0; i<n; ++i) {
		cin >> in[i];
	}
	vector<int> aset;
	vector<int> bset;
	aset.push_back(in[0]);
	for (int i=1; i<n; ++i) {
		if (in[i]%2 == in[0]%2) aset.push_back(in[i]);
		else bset.push_back(in[i]);
	}
	if (aset.size() != bset.size()) {
		cout << -1;
		return 0;
	}
	adj.clear();
	adj.resize(aset.size());
	for (int i=0; i<aset.size(); ++i) {
		int a = aset[i];
		for (int j=0; j<bset.size(); ++j) {
			int b = bset[j];
			if (isprime[a+b]) {
				adj[i].push_back(j);
			}
		}
	}
	vector<int> ans;
	for (int cand : adj[0]) {
		hide = cand;
		if (bimatch(aset.size()) == aset.size()-1) ans.push_back(bset[cand]);
	}
	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int a : ans) {
		cout << a << ' ';
	}
	return 0;
} 
