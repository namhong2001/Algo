#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int pos = 0;
	bool isOk = true;
	for (int i=0; i<n; ++i) {
		int t;
		string dir;
		cin >> t >> dir;
		if (pos == 0 && dir != "South") {
			isOk = false;
			break;
		}
		if (pos == 20000 && dir != "North") {
			isOk = false;
			break;
		}


		if (dir == "South") { 
			pos += t;
		} else if (dir == "North") {
			pos -= t;
		}
			
		
		if (pos < 0 || pos > 20000) {
			isOk = false;
			break;
		}
	}
	if (pos != 0) isOk = false;
	if (isOk) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	} 
	return 0;
}

