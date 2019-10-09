#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

vector<string> parse(string &in) {
	int s = 0;
	vector<string> ret;
	for (int i=0; i<(int)in.size(); ++i) {
		if (in[i] == ' ' || in[i] == '-') {
			ret.push_back(in.substr(s, i-s+1));
			s = i+1;
		}
	}
	ret.push_back(in.substr(s, (int)in.size()-s+1));
	return ret;
}	

int lines(vector<string> &words, int w) {
	int ret = 1;
	int cnt = 0;
	for (string &s : words) { 
		int sz = s.size();
		if (sz > w) return INF; 
		if (cnt + sz > w) {
			ret++;
			cnt = 0;
		}
		cnt += sz;
	}
	return ret;
} 

int main() {
	int K;
	cin >> K;
	string temp;
	getline(cin, temp);
	string in; 
	getline(cin, in);
	vector<string> words = parse(in);
	int l = 0, r = INF;
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (lines(words, mid) > K) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << r; 
	return 0;
}

