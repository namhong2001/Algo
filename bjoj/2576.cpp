#include <iostream>

using namespace std;

int main() {
	int odd_sum = 0;
	int min_odd = 101;
	for (int i=0; i<7; ++i) {
		int a;
		cin >> a;
		if (a%2) { 
			odd_sum += a;
			min_odd = min(min_odd, a);
		}
	}
	if (odd_sum == 0) {
		cout << -1;
	} else {
		cout << odd_sum << '\n' << min_odd;
	} 
    return 0;
}

