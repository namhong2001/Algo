#include <iostream>

using namespace std;

bool have_same_cnt(string S) {
	int lcnt = 0, rcnt = 0;
	for (char c : S) {
		if (c == '(') lcnt++;
		else rcnt++;
	}
	return lcnt == rcnt;
}

bool solve(string S) { 
	int cnt = 0;
	for (char c : S) {
		if (c == '(') cnt++;
		else cnt--; 
		if (cnt < -1) return false;
	}
	return true;
} 

int main() {
	int N;
	string S;
	cin >> N >> S;
	if (!have_same_cnt(S)) {
		cout << "No";
		return 0;
	}
	cout << (solve(S) ? "Yes" : "No"); 
	return 0;
}

