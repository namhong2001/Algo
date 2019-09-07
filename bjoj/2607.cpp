#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	string ts;
	cin >> ts;
	map<char,int> t;
	for (char c : ts) {
		t[c]++;
	}
	int ans = 0;
	for (int i=1; i<N; ++i) {
		string a;
		cin >> a;
		map<char,int> aa;
		for (char c : a) {
			aa[c]++;
		}
		int plus = 0; 
		int minus = 0;
		for (auto aai : aa) {
			int c = aai.first; 
			int cnt = aai.second;
			if (cnt > t[c]) plus += cnt - t[c];
		}
		for (auto ti : t) {
			int c = ti.first; 
			int cnt = ti.second;
			if (cnt > aa[c]) minus += cnt - aa[c];
		}
		if (plus <= 1 && minus <= 1) ans++;
	}
	cout << ans; 
    return 0;
}

