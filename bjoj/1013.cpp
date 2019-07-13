#include <iostream>
#include <regex>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	regex e("(100+1+|01)+");
	int T;
	cin >> T;
	while (T--) {
		string target;
		cin >> target;
		cout << (regex_match(target, e) ? "YES" : "NO") << '\n';
	}
	return 0;
}

