#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int p = b; 
	while (b) {
		int c = b%10;
		cout << a * c << endl;
		b/=10;
	} 
	cout << a*p << endl;
    return 0;
}

