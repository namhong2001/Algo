#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i=0; i<N; ++i) {
		if (s[i] == '1') cnt++;
		else {
			cnt++;
			break;
		}
	}
	cout << cnt << endl; 
	return 0;
}
