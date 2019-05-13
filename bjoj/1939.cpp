#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bridge {
	int a, b, c;
	bool operator < (const Bridge &A) const {
		return this->c < A.c;
	}
};

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}

void un(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
}
	

int main() {
	int n, m;
	cin >> n >> m;
	vector<Bridge> arr;
	r.resize(n);
	for (int i=0; i<n; ++i) r[i] = i;
	for (int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back({a-1, b-1, -c});
	}
	sort(arr.begin(), arr.end());
	int u, v;
	cin >> u >> v;
	for (Bridge &b : arr) {
		un(b.a, b.b);
		if (f(u-1) == f(v-1)) {
			cout << -b.c << endl;
			break;
		}
	}
	return 0;
} 
