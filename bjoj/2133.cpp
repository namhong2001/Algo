#include <iostream>
#include <vector>

using namespace std;


vector<int> d;

int get_cnt(int n) {
	if (n%2) return 0;
	int &ret = d[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=2; i<n; i+=2) {
		if (i == 2) ret += 3 * get_cnt(n-i);
		else ret += 2 * get_cnt(n-i);
	}
	ret += 2;
	return ret;
} 
int main() {
	int n;
	cin >> n;
	d.assign(n+1, -1);
	d[0] = 0;
	d[2] = 3;
	cout << get_cnt(n) << endl;
	return 0;
} 
