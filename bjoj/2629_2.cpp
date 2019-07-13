#include <iostream>
#include <vector>

using namespace std; 

const int LIMIT = 15001;

int main() {
	int N;
	cin >> N;
	vector<bool> d(LIMIT, false);
	d[0] = true;
	for (int i=0; i<N; ++i) {
		int cur;
		cin >> cur;
		vector<bool> next = d;
		for (int j=0; j<LIMIT; ++j) {
			if (d[j]) {
				if (abs(j+cur) < LIMIT) next[abs(j+cur)] = true;
				if (abs(j-cur) < LIMIT) next[abs(j-cur)] = true;
			}
		}
		swap(d, next);
	}
	int M;
	cin >> M;
	for (int i=0; i<M; ++i) {
		int a;
		cin >> a;
		if (a < LIMIT && d[a]) cout << "Y" << " ";
		else cout << "N" << " ";
	}
	return 0;
} 
