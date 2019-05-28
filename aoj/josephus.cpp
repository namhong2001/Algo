#include <iostream>
#include <list>
#include <iterator>

using namespace std;


void circular_advance(list<int> &l, list<int>::iterator &it, int n) {
	for (int i=0; i<n; ++i) {
		advance(it, 1);
		if (it == l.end()) it = l.begin();
	}
}

list<int>::iterator circular_next(list<int> &l, list<int>::iterator &it, int n = 1) {
	list<int>::iterator n_it = it;
	circular_advance(l, n_it, n);
	return n_it; 
} 

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, k;
		cin >> n >> k;
		list<int> l;
		for (int i=1; i<=n; ++i) {
			l.push_back(i);
		}
		auto it = l.begin();
		for (int i=0; i<n-2; ++i) { 
			it = l.erase(it);
			if (it == l.end()) it = l.begin();
			circular_advance(l, it, k-1);
		}
		cout << l.front() << ' ' << l.back() << endl;
	}
	return 0;
} 
