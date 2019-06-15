#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll cnt = 0;
	int i = 0;
	while (pow(10, i+1) <= N) { 
		cnt += (pow(10, i+1) - pow(10, i))*(i+1);
		++i;
	}
	cnt += (N - pow(10, i)+1)*(i+1);
	cout << cnt;
	return 0;
} 
