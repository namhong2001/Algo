#include <iostream>
#include <list>

using namespace std;


typedef pair<int,int> pii;


void circular_advance(list<pii> &l, list<pii>::iterator &it, int n) {
	if (n > 0) {
		for (int i=0; i<n; ++i) {
			it++;
			if (it == l.end()) it = l.begin();
		}
	} else if (n < 0) {
		for (int i=0; i>n; --i) {
			if (it == l.begin()) it = l.end();
			it--;
		}
	}
}

		


int main() {
	int n; 
	cin >> n;
	list<pii> l; 
	for (int i=1; i<=n; ++i) {
		int a;
		cin >> a;
		l.push_back({i, a});
	}
	auto it = l.begin();
	while (true) { 
		cout << it->first << ' ';
		int go = it->second;
		it = l.erase(it); 
		if (it == l.end()) it = l.begin();
		if (l.empty()) break;
		if (go > 0) circular_advance(l, it, go-1);
		else circular_advance(l, it, go);
	}
	return 0;
} 

