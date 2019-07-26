#include <iostream>
#include <regex>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<string> words(N);
	for (int i=0; i<N; ++i) {
		cin >> words[i];
	}
	for (int i=0; i<M; ++i) {
		string niddle;
		cin >> niddle;
		vector<char> vchar;
		for (char c : niddle) {
			if (c == '?') vchar.push_back('.');
			vchar.push_back(c);
		}
		string str(vchar.begin(), vchar.end()); 
		regex reg(str);
		int cnt = 0;
		for (int i=0; i<N; ++i) {
			if (regex_match(words[i], reg)) cnt++;
		}
		cout << cnt << '\n';
	} 
	return 0;
}
