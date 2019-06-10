#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

using namespace std; 

int main() {
	cout << 1 << endl;
	srand(time(nullptr));
	vector<string> name = {
		"aa", "ab", "ac", "ad", "ae", "af", "ag", "ah", "ai", "aj", "ak", "al", "am", "an", "ao", "ap", "aq", "ar", "as", "at", "au", "av", "aw", "ax", "ay", "az",
		"ba", "bb", "bc", "bd", "be", "bf", "bg", "bh", "bi", "bj", "bk", "bl", "bm", "bn", "bo", "bp", "bq", "br", "bs", "bt", "bu", "bv", "bw", "bx"
	};
	int n = 40;
	int m = 30;
	cout << n << ' ' << m << endl;
	for (int i=0; i<n; ++i) {
		cout << name[i] << ' ';
	}
	cout << endl;
	for (int i=0; i<m; ++i) {
		int cnt = rand()%(n-5);
		set<int> s;
		while (s.size() < cnt) {
			int ith = rand()%n;
			s.insert(ith);
		}
		cout << cnt << ' ';
		for (int ith : s) {
			cout << name[ith] << ' ';
		}
		cout << endl;
	}
	return 0; 
}

