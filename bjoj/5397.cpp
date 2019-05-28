#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		list<char> l;
		auto it = l.begin();
		string s;
		cin >> s;
		for (char action : s) {
			if (action == '<') {
				if (it != l.begin()) {
					it--;
				}
			} else if (action == '>') {
				if (it != l.end()) it++;
			} else if (action == '-') {
				if (it != l.begin()) {
					l.erase(prev(it));
				}
			} else {
				l.insert(it, action);
			}
		}
		for (auto it= l.begin(); it != l.end(); ++it) {
			cout << *it;
		}
		cout << '\n';
	}

	return 0;
} 
