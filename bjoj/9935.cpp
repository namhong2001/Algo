#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int ui;

int main() {
	string A, B;
	cin >> A >> B;
	ui blen = B.size();
	vector<char> ans;
	for (char a : A) {
		ans.push_back(a);
		if (ans.size() >= blen) {
			ui start = ans.size() - blen;
			bool match = true;
			for (ui i=0; i<blen; ++i) {
				if (ans[start+i] != B[i]) {
					match = false;
					break;
				}
			}
			if (match) {
				for (ui i=0; i<blen; ++i) {
					ans.pop_back();
				}
			}
		}
	}
	if (ans.empty()) {
		cout << "FRULA";
	} else {
		for (char a : ans) {
			cout << a;
		}
	} 
	return 0;
}

