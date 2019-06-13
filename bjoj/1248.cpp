#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> cand;
vector<vector<int>> s(10, vector<int>(10));
vector<int> ans;
vector<int> psum(11, 0); // front zero padding;
int N;

bool search(int here) { 
	if (here == N) return true;
	for (int i=0; i<(int)cand.size(); ++i) { 
		int c = cand[i];
		psum[here+1] = psum[here] + c;
		bool ok = true;
		for (int j=0; j<=here; ++j) {
			int sum = psum[here+1] - psum[j];
			if (sum > 0) {
				if (s[j][here] != 1) ok = false;
			}
			else if (sum == 0) {
				if (s[j][here] != 0) ok = false;
			}
			else if (sum < 0) {
				if (s[j][here] != -1) ok = false;
			}
			if (ok == false) break;
		}
		if (ok == false) continue;
		
		ans.push_back(c);
		if (search(here+1)) return true;
		ans.pop_back();
	}
	return false;
} 

bool check() {
	for (int i=0; i<N; ++i) {
		int sum = 0;
		for (int j=i; j<N; ++j) {
			sum += ans[j];
			if (sum > 0) {
				if (s[i][j] != 1) return false;
			}
			else if (sum == 0) {
				if (s[i][j] != 0) return false;
			}
			else if (sum < 0) {
			   if (s[i][j] != -1) return false;
			}
		}
	}
	return true;
} 

int main() {
	cin >> N;
	string in;
	cin >> in;
	int r = 0, c = 0;
	for (char i : in) {
		int a;
		if (i == '-') a = -1;
		else if (i == '+') a = 1;
		else if (i == '0') a = 0;
		s[r][c] = a;
		c++;
		if (c == N) {
			r++;
			c = r;
		}
	} 
	for (int i=-10; i<=10; ++i) {
		cand.push_back(i);
	}
	search(0);
	for (int a : ans) {
		cout << a << ' ';
	}
	return 0;
} 
