#include <iostream>
#include <vector>


using namespace std;

void dfs(vector<vector<int>> &adj_list, vector<int> &component_map, int here, int component_id) {
	component_map[here] = component_id;
	for (int i=0; i<adj_list[here].size(); ++i) {
		int there = adj_list[here][i];
		if (component_map[there] == 0) {
			dfs(adj_list, component_map, there, component_id);
		}
	}
}


void solve(vector<vector<int>> &adj_list, vector<int> &component_map) {
	int component_id = 0;
	for (int here=0; here<adj_list.size(); ++here) {	
		if (component_map[here]  == 0) {
			dfs(adj_list, component_map, here, ++component_id);
		}
	}
}	

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adj_list(n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			int a;
			cin >> a;
			if (a == 1) {
				adj_list[i].push_back(j);
			}
		}
	}

	vector<int> component_map(n, 0);
	
	solve(adj_list, component_map);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i == j || component_map[i] == component_map[j]) {
				cout << '1';
			} else {
				cout << '0';
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
