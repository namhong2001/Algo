#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int LIMIT = 1e6+1;

bool isPowOf2(int num) {
	while (num > 1) {
		if (num%2) return false;
		num /= 2;
	}
	return true;
}

struct Segment {
	vector<int> b;
	int sz;
	Segment(int cnt) {
		sz = 1;
		while (sz < cnt) {
			sz *= 2;
		}
		b.assign(sz*2, 0);
	}
	void update(int val) {
		int p = sz+val;
		while (p) {
			b[p]++;
			p/=2;
		}
	}
	int biggerCnt(int val) {
		int ret = 0;
		int p = sz+val+1;
		while (true) { 
			if (p%2) {
				ret += b[p];
				p /= 2; 
				p++;
				if (isPowOf2(p)) break; 
			} else {
				p /= 2;
			}
		}
		return ret; 
	}
	void print() {
		int nl = 1;
		for (int i=1; i<sz*2; ++i) {
			cerr << b[i] << ' ';
			if (i == nl) {
				cerr << endl;
				nl *= 2;
			}
		}
		cerr << endl;
	};
};

int main() {
	int N;
	cin >> N;
	int ans = 0;
	Segment seg(LIMIT);
	for (int i=0; i<N; ++i) {
		int num; 
		cin >> num;
		ans = max(ans, seg.biggerCnt(num));
		seg.update(num);
	}
	cout << ans+1;
	return 0;
}

