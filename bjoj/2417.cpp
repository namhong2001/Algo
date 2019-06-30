#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
	ull num;
	cin >> num; 
	ull l = 0, r = 1ll<<32;
	while (l < r) {
		ull mid = (l+r)/2;
		if (num > mid*mid) l = mid+1;
		else r = mid;
	}
	cout << l << endl;
	return 0;
} 
