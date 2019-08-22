#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int ui;

int main() {
	string A, T;
	cin >> A >> T;
	ui alen = A.size();
	ui tlen = T.size();
	ui lpos = 0, rpos = tlen-1;
	vector<char> LEFT, RIGHT; 
	bool order = true;
	while (lpos <= rpos) {
		if (order) { 
			LEFT.push_back(T[lpos++]);
			if (LEFT.size() >= alen) {
				ui lstart = LEFT.size()-alen;
				bool isMatch = true;
				for (ui i=0; i<alen; ++i) {
					if (LEFT[lstart+i] != A[i]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) {
					for (ui i=0; i<alen; ++i) {
						LEFT.pop_back();
					}
					order = !order;
				}
			}
		} else { 
			RIGHT.push_back(T[rpos--]);
			if (RIGHT.size() >= alen) {
				ui rstart = RIGHT.size()-alen;
				bool isMatch = true;
				for (ui i=0; i<alen; ++i) {
					if (RIGHT[rstart+i] != A[alen-1-i]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) {
					for (ui i=0; i<alen; ++i) {
						RIGHT.pop_back();
					}
					order = !order;
				}
			}
		}
	}
	while (!LEFT.empty() && !RIGHT.empty()) {
		if (order) { 
			char c = RIGHT.back();
			RIGHT.pop_back(); 
			LEFT.push_back(c);
			if (LEFT.size() > alen) {
				ui lstart = LEFT.size()-alen;
				bool isMatch = true;
				for (ui i=0; i<alen; ++i) {
					if (LEFT[lstart+i] != A[i]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) {
					for (ui i=0; i<alen; ++i) {
						LEFT.pop_back();
					}
					order = !order;
				}
			}
		} else { 
			char c = LEFT.back();
			LEFT.pop_back(); 
			RIGHT.push_back(c);
			if (RIGHT.size() > alen) {
				ui rstart = RIGHT.size()-alen;
				bool isMatch = true;
				for (ui i=0; i<alen; ++i) {
					if (RIGHT[rstart+i] != A[alen-1-i]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) {
					for (ui i=0; i<alen; ++i) {
						RIGHT.pop_back();
					}
					order = !order;
				}
			}
		}
	} 
	if (!LEFT.empty()) {
		for (char ans : LEFT) {
			cout << ans;
		}
	} else {
		reverse(RIGHT.begin(), RIGHT.end());
		for (char ans : RIGHT) {
			cout << ans;
		}
	} 
	return 0;
}

