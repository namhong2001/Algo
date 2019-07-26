#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cand;

void make_cand(string &s, int index, vector<char> &vchar) {
	if ((int)s.size() == index) {
		cand.push_back(string(vchar.begin(), vchar.end()));
		return;
	}
	if (s[index] == '?') {
		for (int i=0; i<5; ++i) {
			vchar.push_back('a'+i);
			make_cand(s, index+1, vchar);
			vchar.pop_back();
		}
		make_cand(s, index+1, vchar);
	} else {
		vchar.push_back(s[index]); 
		make_cand(s, index+1, vchar);
		vchar.pop_back();
	} 
} 

int main() {
	int N, M;
	cin >> N >> M;
	map<string, int> match;
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s;
		match[s]++;
	}
	for (int i=0; i<M; ++i) {
		string s;
		cin >> s;
		cand.clear();
		vector<char> vchar;
		make_cand(s, 0, vchar);
		sort(cand.begin(), cand.end());
		auto last = unique(cand.begin(), cand.end());
		cand.erase(last, cand.end());
		int ans = 0; 
		for (string s : cand) {
			ans += match[s];
		}
		cout << ans << endl;
	}
	return 0;
} 
