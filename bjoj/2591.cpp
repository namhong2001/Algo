#include <iostream>
#include <cstring> 

using namespace std;

string S;
int d[42];
int solve(int nth) {
	if (nth == 0) return 1;
	if (nth == 1) return 1;
	int &ret = d[nth];
	if (ret != -1) return ret;
	ret = 0; 
	if (S[nth] != '0') ret += solve(nth-1);
	if (('0' < S[nth-1] && S[nth-1] <= '2') ||  (S[nth-1] == '3' && S[nth] <= '4')) ret += solve(nth-2);
	return ret;
} 

int main() {
	memset(d, -1, sizeof(d));
	string s;
	cin >> s;
	S = '9' + s;
	cout << solve(s.size()); 
    return 0;
}

