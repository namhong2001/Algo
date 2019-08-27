#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int next(int cur, int P) { 
	int ret = 0;
	while (cur) {
		int digit = cur%10;
		ret += pow(digit, P);
		cur /= 10;
	}
	return ret;
} 

int main() {
	int A, P;
	cin >> A >> P;
	map<int,int> index;
	int order = 1;
	while (index.find(A) == index.end()) {
		index[A] = order++;
		A = next(A, P);
	}
	cout << index[A]-1 << '\n'; 
	return 0;
}

