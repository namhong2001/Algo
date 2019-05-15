#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(time(0));
	int c = 1;
	cout << c << endl;
	int n = rand() % 12 + 1;
	int k = rand() % (n+1);
	int m = rand() % 10 + 1;
	int l = rand() % 10 + 1;
	cout << n << ' ' << k << ' ' << m << ' ' << l << endl;
	for (int i=0; i<n; ++i) {
		int r = rand() % n;
		cout << r << ' ';
		vector<int> pre;
		while (pre.size() < r) { 
			int p = rand() % n;
			if (p == i) continue;
			bool dup = false;
			for (int a : pre) {
				if (a == p) {
					dup = true;
					break; 
				}
			}
			if (dup) continue;
			pre.push_back(p);
		}
		for (int p : pre) {
			cout << p << ' ';
		}
		cout << endl;
	}
	for (int i=0; i<m; ++i) {
		int r = rand() % n + 1;
		cout << r << ' ';
		vector<int> lecture;
		while (lecture.size() < r) { 
			int p = rand() % n;
			bool dup = false;
			for (int a : lecture) {
				if (a == p) {
					dup = true;
					break; 
				}
			}
			if (dup) continue;
			lecture.push_back(p);
		}
		for (int p : lecture) {
			cout << p << ' ';
		}
		cout << endl;
	}

    return 0;
}

