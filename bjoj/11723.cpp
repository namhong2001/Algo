#include <iostream>

using namespace std;

typedef unsigned int ui;

struct S {
	ui s = 0;
	void add(ui x) {
		s |= 1u<<x;
	}
	void remove(ui x) {
		s &= ~(1u<<x);
	}
	void check(ui x) {
		cout << ((s & 1<<x) ? 1 : 0) << '\n';
	}
	void toggle(ui x) {
		s ^= 1u<<x;
	}
	void all() {
		s = (1<<20) - 1;
	}
	void empty() {
		s = 0;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> m;
	S s;
	while (m--) {
		string comm;
		int x;
		cin >> comm;
		if (comm != "all" && comm != "empty") {
			cin >> x;
			x--;
		}
		if (comm == "add") s.add(x);
		else if (comm == "remove") s.remove(x);
		else if (comm == "check") s.check(x);
		else if (comm == "toggle") s.toggle(x);
		else if (comm == "all") s.all();
		else if (comm == "empty") s.empty();
	}
	return 0;
} 
