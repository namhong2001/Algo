#include <iostream>
#include <iterator>
#include <list>

using namespace std;

void circular_advance(list<int> &l, list<int>::iterator &it) {
	advance(it, 1);
	if (it == l.end()) it = l.begin();
} 

int main() {
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	auto it = a.begin();
	for (int i=0; i<4; ++i) {
		for (int j=0; j<3; ++j) {
			circular_advance(a, it);
		} 
		cout << *it << endl;
	}
	return 0;
}

