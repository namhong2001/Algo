#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000;

string s;

int d[5001]; 
int solve(int index) { 
	if (index == (int)s.size()) return 1;
	int &ret = d[index];
	if (ret != -1) return ret; 
	ret = 0;
	if (s[index] != '0') {
		ret += solve(index+1); 
		ret %= MOD;
	}
	if (index+1 < (int)s.size()) {
		int num = stoi(s.substr(index, 2));
		if (10<=num && num<=26) {
			ret += solve(index+2);
			ret %= MOD;
		}
	}
	return ret;
} 

int main() {
	cin >> s;
	memset(d, -1, sizeof(d)); 
	cout << solve(0) << endl;
	return 0;
}

