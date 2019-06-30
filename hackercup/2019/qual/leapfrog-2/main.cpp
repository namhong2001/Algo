#include <iostream>

using namespace std; 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		string s;
		cin >> s;
		int vacant_cnt = 0;
		int B_cnt = 0;
		for (int i=1; i<(int)s.size(); ++i) {
			if (s[i] == '.') vacant_cnt++;
			else if (s[i] == 'B') B_cnt++;
		}
		char ans;
		if (vacant_cnt == 0) {
			ans = 'N';
		} else if (vacant_cnt > B_cnt && B_cnt < 2) {
			ans = 'N';
		} else {
			ans = 'Y';
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0; 
} 
