#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Word {
	int x, y;
	string w;
};

vector<vector<int>> adj;
vector<int> bmatch;


bool collision(Word &hword, Word &vword) {
	int x = hword.x;
	int y = vword.y;
	if (hword.y <= y && y < hword.y+hword.w.size() &&
			vword.x <= x && x < vword.x+vword.w.size()) {
		if (hword.w[y-hword.y] != vword.w[x-vword.x]) {
			return true;
		} 	
	} 
	return false;
}

bool dfs(int here, vector<bool> &visited) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there : adj[here]) {
		if (bmatch[there] == -1 || dfs(bmatch[there], visited)) {
			bmatch[there] = here;
			return true;
		}
	}
	return false; 
}

int bip(int H, int V) {
	bmatch.assign(V, -1);
	int cnt = 0;
	for (int i=0; i<H; ++i) {
		vector<bool> visited(H, false);
		cnt += dfs(i, visited);
	}
	return cnt;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		int H, V;
		cin >> H >> V;
		vector<Word> hwords(H);
		vector<Word> vwords(V);
		for (int i=0; i<H; ++i) {
			int x, y;
			string w;
			cin >> y >> x >> w;
			hwords[i] = {x, y, w};
		}
		for (int i=0; i<V; ++i) {
			int x, y;
			string w;
			cin >> y >> x >> w;
			vwords[i] = {x, y, w};
		}
		adj.clear();
		adj.resize(H); 
		for (int i=0; i<H; ++i) {
			for (int j=0; j<V; ++j) {
				if (collision(hwords[i], vwords[j])) {
					adj[i].push_back(j);
				}
			}
		}
		cout << H+V-bip(H, V) << endl;
	}
	return 0;
} 

