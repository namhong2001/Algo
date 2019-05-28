#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> a;
	a.insert(1);
	a.insert(3);
	a.insert(7);
	a.insert(2);
	cout << *a.begin() << endl;
	auto it = a.end();
	it--;
	cout << *it << endl;
	return 0;
}

