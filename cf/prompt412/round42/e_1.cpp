#include <iostream>
#include <vector>
#include <set>

using namespace std; 
struct Node; 
set<Node*> visited; 

struct Node {
	char c;
	int cnt=0;
	vector<Node*> children;
	Node (char c): c(c) {
		children.assign(5, nullptr); 
	};
	void add_child(string &s, int index) {
		if (index > (int)s.size()) return;
		if (index == (int)s.size()) {
			cnt++;
			return;
		}
		if (children[s[index]-'a'] == nullptr) {
			children[s[index]-'a'] = new Node(s[index]);
		}
		children[s[index]-'a']->add_child(s, index+1);
	} 
	int search(string &s, int index, bool before_empty) {
		if (index >= (int)s.size()) {
			if (visited.find(this) == visited.end()) { 
				visited.insert(this);
				return cnt; 
			}
			return 0;
		}
		if (s[index] == '?') {
			int ret = 0; 
			if (!before_empty) {
				for (int i=0; i<5; ++i) {
					if (children[i] != nullptr) {
						ret += children[i]->search(s, index+1, false);
					}
				}
			}
			ret += search(s, index+1, true);
			return ret;
		} else {
			if (children[s[index]-'a'] != nullptr) {
				return children[s[index]-'a']->search(s, index+1, false);
			}
			return 0;
		}
		return 0; // cannot reach
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int N, M;
	cin >> N >> M;
	Node root(0); 
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s;
		root.add_child(s, 0);
	} 
	for (int i=0; i<M; ++i) {
		string p;
		cin >> p;
		visited.clear();
		cout << root.search(p, 0, false) << '\n';
	} 
	return 0;
}
