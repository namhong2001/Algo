#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int INF = 987654321;

typedef pair<int,int> pii;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> order[k+1];
	vector<int> input(k);
	for (int i=0; i<k; ++i) {
		cin >> input[i];
		order[input[i]].push(i);
	}
	set<pii> s;
	int ans = 0;
	for (int in : input) { 
		int here_index = order[in].front();
		order[in].pop(); 
		int next_index = -1;
		if (order[in].empty()) next_index = INF;
		else next_index = order[in].front(); 

		if (s.find({here_index, in}) != s.end()) {
			s.erase({here_index, in});
			s.insert({next_index, in}); 
		} else if (s.size() < n) {
			s.insert({next_index, in});
		} else { 
			auto e = s.end();
			e--;
			s.erase(e);
			s.insert({next_index, in});
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
