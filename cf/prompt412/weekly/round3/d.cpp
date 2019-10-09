#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b > a) {
		cout << -1;
		return 0;
	}
	if (a == b) {
		cout << a;
		return 0;
	}
	int k = (a+b)/(2*b);
	double x = (double)(a+b)/(2*k);
	k = (a-b)/(2*b); 
	if (k != 0) {
		x = min(x, (double)(a-b)/(2*k));
	}
	cout << fixed << setprecision(10) << x; 
	return 0;
}

