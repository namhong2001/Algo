#include <iostream>

using namespace std;

int digit_sum(int a) {
	int sum = 0;
	while (a) {
		sum += a%10;
		a /= 10;
	}
	return sum;
}


int main() {
	int a;
	cin >> a;
	while (true) {
		if (digit_sum(a)%4 == 0) break;
		a++;
	}
	cout << a << endl;
	return 0;
}

