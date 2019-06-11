#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

const set<char> VOWEL = {'a', 'e', 'i', 'o', 'u'}; 

int L, C;
set<char> ans; 
set<char> input;
void print_all(set<char>::iterator input_it, int v_required, int c_required) {
	if (ans.size() == L) {
		if (v_required > 0 || c_required > 0) return;
		string s;
		for (char c : ans) {
			s += c;
		}
		cout << s << '\n';
		return;
	} 
	if (v_required + c_required > L-(int)ans.size()) return;

	for (auto it=input_it; it!=input.end(); ++it) {
		ans.insert(*it); 
		if (VOWEL.find(*it) != VOWEL.end()) { 
			print_all(next(it), v_required-1, c_required);
		} else {
			print_all(next(it), v_required, c_required-1);
		} 
		ans.erase(*it);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> L >> C;
	for (int i=0; i<C; ++i) {
		string s;
		cin >> s;
		input.insert(s[0]);
	}
	print_all(input.begin(), 1, 2);
	return 0;
}
	
