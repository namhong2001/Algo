#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		multiset<int> Q; 
		for (int i=0; i<K; ++i) {
			string s;
			int a;
			cin >> s >> a;
			if (s == "I") {
				Q.insert(a);
			} else {
				if (Q.empty()) continue;
				if (a == 1) { 
					Q.erase(prev(Q.end()));
				} else {
					Q.erase(Q.begin());
				}
			}
		}
		if (Q.empty()) {
			cout << "EMPTY" << endl;
		} else {
			cout << *prev(Q.end()) << ' ' << *Q.begin() << endl;
		}
	}
	return 0;
} 
