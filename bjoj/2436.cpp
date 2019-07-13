#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

int main() {
	int G, L;
	cin >> G >> L;
	int ab = L/G;
	for (int a = (int)sqrt(ab); a>0; --a) {
		if (ab % a == 0 && gcd(a, ab/a) == 1) {
			cout << a*G << ' ' << ab/a*G << '\n';
			break;
		}
	}
	return 0;
}
