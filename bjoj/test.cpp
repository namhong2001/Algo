#include <iostream>

using namespace std;

int main() {
	string s;
	s += '0';
	cout << stoi(s) << endl;
	s += '0';
	cout << stoi(s) << endl;
	s += '1';
	cout << stoi(s) << endl;
	return 0;
}
