#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	deque<char> wheel(n, -1);
	int here = 0;
	vector<bool> used(26, false);
	while (k--) {
		int cnt;
		string letter; 
		cin >> cnt >> letter;
		here = (here + cnt) % n;
		if (wheel[here] != -1) {
			if (letter[0] != wheel[here]) {
				cout << "!" << endl; 
				return 0;
			}
		} else if (used[letter[0]]) {
			cout << "!" << endl; 
			return 0;
		}

		wheel[here] = letter[0];
		used[letter[0]] = true;
	} 
	if (n == 26 && k == 25) {
		vector<bool> exist(26, false);
		char missing_letter;
		for (char a : wheel) {
			if (a == -1) continue;
			exist[a-'A'] = true;
		}
		for (int i=0; i<26; ++i) {
			if (!exist[i]) {
				missing_letter = 'A' + i;
			}
		}
		for (char &a : wheel) {
			if (a == -1) a = missing_letter;
		}
	} 
	for (int i=here; i<n-1; ++i) { 
		int b = wheel.back();
		wheel.pop_back();
		wheel.push_front(b);
	}
	reverse(wheel.begin(), wheel.end());

	for (char a : wheel) {
		if (a == -1) cout << '?';
		else cout << a;
	}
	return 0;
} 
