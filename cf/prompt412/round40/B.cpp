#include <iostream>
#include <cmath>

using namespace std;

int solve(string str) {
	int ans = 0;
	int n = str.size(); 
	for (int i=0; i<n; ++i) {
		if (str[i] == '4') {
			ans += pow(2, n-i-1); 
		} else {
			ans += pow(2, n-i);
		}
	}
	return ans;
} 

int main() {
	string str;
	cin >> str;
	cout << solve(str) << endl; 
	return 0;
}

